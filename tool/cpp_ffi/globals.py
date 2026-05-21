import cpp_ffi.parser as parser
import cpp_ffi.cpp as cpp
import cpp_ffi.c as c

cpp_structs: dict[str, parser.Struct] = {}
cpp_enums: dict[str, parser.Enum] = {}
cpp_classes: dict[str, parser.Class] = {}

cpp_field_getters: dict[str, dict[str, str]] = {}


def add_from_parse_result(parse_result: parser.ParseResult) -> None:
  for struct in parse_result.structs:
    cpp_structs[struct.full_name] = struct
  for enum in parse_result.enums:
    cpp_enums[enum.full_name] = enum
  for cls in parse_result.classes:
    cpp_classes[cls.full_name] = cls


c_structs: dict[str, c.Struct] = {}
c_enums: dict[str, c.Enum] = {}
c_class_opaques: dict[str, c.ClassOpaque] = {}


def add_c_struct(c_struct: c.Struct) -> None:
  c_structs[c_struct.cpp_struct.full_name] = c_struct


def add_c_enum(c_enum: c.Enum) -> None:
  c_enums[c_enum.cpp_enum.full_name] = c_enum


def add_c_class_opaque(c_class_opaque: c.ClassOpaque) -> None:
  c_class_opaques[c_class_opaque.cpp_class.full_name] = c_class_opaque


# -- Finders -- #


def has_cpp_struct(full_name: str) -> bool:
  return full_name in cpp_structs


def has_cpp_enum(full_name: str) -> bool:
  return full_name in cpp_enums


def has_cpp_class(full_name: str) -> bool:
  return full_name in cpp_classes


def find_cpp_struct(full_name: str) -> parser.Struct:
  return cpp_structs[full_name]


def find_cpp_enum(full_name: str) -> parser.Enum:
  return cpp_enums[full_name]


def find_cpp_class(full_name: str) -> parser.Class:
  return cpp_classes[full_name]


def find_cpp_class_or_struct(full_name: str) -> cpp.Class | cpp.Struct:
  if full_name in cpp_classes:
    return cpp_classes[full_name]
  return cpp_structs[full_name]


def has_c_enum(full_name: str) -> bool:
  return full_name in c_enums


def has_c_struct(full_name: str) -> bool:
  return full_name in c_structs


def find_c_enum(full_name: str) -> c.Enum:
  return c_enums[full_name]


def find_c_struct(full_name: str) -> c.Struct:
  return c_structs[full_name]


def has_c_class_opaque(full_name: str) -> bool:
  return full_name in c_class_opaques


def find_c_class_opaque(full_name: str) -> c.ClassOpaque:
  return c_class_opaques[full_name]
