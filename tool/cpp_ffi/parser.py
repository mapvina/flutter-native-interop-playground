import clang.cindex
import pathlib
import subprocess
from dataclasses import dataclass

import cpp_ffi.cpp as cpp
import cpp_ffi.utils as utils


def configure_clang():
  # TODO: make this cross-platform.
  clang.cindex.Config.set_library_file('/opt/homebrew/opt/llvm/lib/libclang.dylib')


def get_sdk_path() -> str:
  return subprocess.check_output(['xcrun', '--show-sdk-path']).decode().strip()


def get_include_dirs():
  script_dir = pathlib.Path(__file__).parent.resolve()
  root_dir = script_dir.parent.parent.resolve()
  mapvina_native_dir = root_dir / 'third-party' / 'mapvina-native'

  return [
    mapvina_native_dir / 'include',
    mapvina_native_dir / 'vendor' / 'mapvina-native-base' / 'include',
    mapvina_native_dir / 'vendor' / 'mapvina-native-base' / 'deps' / 'geometry.hpp' / 'include',
    mapvina_native_dir / 'vendor' / 'mapvina-native-base' / 'deps' / 'variant' / 'include',
  ]


def get_tu(file_path: pathlib.Path) -> clang.cindex.TranslationUnit:
  index = clang.cindex.Index.create()
  sdk_path = get_sdk_path()
  tu = index.parse(
    file_path,
    args=[
      *(f'-I{inc}' for inc in get_include_dirs()),
      '-std=c++20',
      '-x',
      'c++',
      '-stdlib=libc++',
      f'-isysroot{sdk_path}',
      f'-I{sdk_path}/usr/include',
      f'-I{sdk_path}/usr/include/c++/v1',
    ],
  )

  return tu


@dataclass
class ParseResult:
  structs: list[cpp.Struct]
  enums: list[cpp.Enum]
  classes: list[cpp.Class]

  def merge(self, other: 'ParseResult') -> None:
    self.structs.extend(other.structs)
    self.enums.extend(other.enums)
    self.classes.extend(other.classes)

  def find_enum(self, full_name: str) -> cpp.Enum | None:
    for enum in self.enums:
      if enum.full_name == full_name:
        return enum
    return None

  def find_struct(self, full_name: str) -> cpp.Struct | None:
    for struct in self.structs:
      if struct.full_name == full_name:
        return struct
    return None

  def find_class(self, full_name: str) -> cpp.Class | None:
    for cls in self.classes:
      if cls.full_name == full_name:
        return cls
    return None


def parse_type(type: clang.cindex.Type) -> cpp.Type:
  generic_args = []

  for i in range(type.get_num_template_arguments()):
    arg_type = type.get_template_argument_type(i)
    generic_args.append(parse_type(arg_type))

  decl_name = type.get_declaration().spelling
  if not decl_name:
    decl_name = type.spelling

  return cpp.Type(
    type=type,
    full_name=type.get_named_type().spelling.strip() or type.get_canonical().spelling.strip(),
    decl_name=decl_name,
    generic_args=generic_args,
  )


def parse_field(cursor: clang.cindex.Cursor) -> cpp.Field:
  name = cursor.spelling.strip()
  if not name:
    # infer name from type
    name = parse_type(cursor.type).base_name
    # remove any namespace qualifiers and make lowercase
    name = utils.cpp_name_to_c_name(name.split('::')[-1])
    
  return cpp.Field(
    cursor=cursor,
    type=parse_type(cursor.type),
    name=name,
  )


def parse_constructor(cursor: clang.cindex.Cursor) -> cpp.Constructor:
  parameters = []
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.PARM_DECL:
      field = parse_field(child)
      parameters.append(field)

  is_default = len(parameters) == 0

  return cpp.Constructor(
    cursor=cursor,
    name=cursor.spelling,
    parameters=parameters,
    is_default=is_default,
  )


def parse_fields(cursor: clang.cindex.Cursor) -> list[cpp.Field]:
  fields = []
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.FIELD_DECL and child.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
      field = parse_field(child)
      fields.append(field)
  return fields


def parse_constructors(cursor: clang.cindex.Cursor) -> list[cpp.Constructor]:
  constructors = []
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.CONSTRUCTOR and child.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
      if child.is_move_constructor() or child.is_copy_constructor():
        continue

      constructor = parse_constructor(child)
      constructors.append(constructor)
  return constructors


def parse_method(cursor: clang.cindex.Cursor) -> cpp.Method:
  parameters = []
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.PARM_DECL:
      field = parse_field(child)
      parameters.append(field)

  return cpp.Method(
    cursor=cursor,
    name=cursor.spelling,
    return_type=parse_type(cursor.result_type),
    parameters=parameters,
    is_const=cursor.is_const_method(),
    is_static=cursor.is_static_method(),
  )


def parse_methods(cursor: clang.cindex.Cursor) -> list[cpp.Method]:
  methods = []
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.CXX_METHOD and child.access_specifier == clang.cindex.AccessSpecifier.PUBLIC:
      method = parse_method(child)
      methods.append(method)
  return methods


def parse_struct(cursor: clang.cindex.Cursor, namespace: str) -> cpp.Struct:
  return cpp.Struct(
    cursor=cursor,
    namespace=namespace,
    name=cursor.spelling,
    fields=parse_fields(cursor),
    constructors=parse_constructors(cursor),
  )


def parse_enum(cursor: clang.cindex.Cursor, namespace: str) -> cpp.Enum:
  values = {}
  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.ENUM_CONSTANT_DECL:
      values[child.spelling] = child.enum_value

  return cpp.Enum(
    cursor=cursor,
    namespace=namespace,
    name=cursor.spelling,
    values=values,
  )


def parse_class(cursor: clang.cindex.Cursor, namespace: str) -> cpp.Class:
  return cpp.Class(
    cursor=cursor,
    namespace=namespace,
    name=cursor.spelling,
    fields=parse_fields(cursor),
    constructors=parse_constructors(cursor),
    methods=parse_methods(cursor),
  )


def traverse_cursor(cursor: clang.cindex.Cursor, namespace: str = '', result: ParseResult = None):
  if result is None:
    result = ParseResult(structs=[], enums=[], classes=[])

  for child in cursor.get_children():
    if child.kind == clang.cindex.CursorKind.NAMESPACE:
      new_namespace = f'{namespace}::{child.spelling}' if namespace else child.spelling
      traverse_cursor(child, new_namespace, result)
    elif child.kind == clang.cindex.CursorKind.CLASS_DECL:
      cls = parse_class(child, namespace)
      result.classes.append(cls)
      
      new_namespace = f'{namespace}::{child.spelling}' if namespace else child.spelling
      traverse_cursor(child, new_namespace, result)
    elif child.kind == clang.cindex.CursorKind.STRUCT_DECL:
      struct = parse_struct(child, namespace)
      result.structs.append(struct)
    elif child.kind == clang.cindex.CursorKind.ENUM_DECL:
      enum = parse_enum(child, namespace)
      result.enums.append(enum)

  return result


def parse(tu: clang.cindex.TranslationUnit) -> ParseResult:
  return traverse_cursor(tu.cursor)
