import clang.cindex
from dataclasses import dataclass, field
import cpp_ffi.converter as converter
import cpp_ffi.globals as globals
import cpp_ffi.c as c


@dataclass
class Type:
  type: clang.cindex.Type = field(repr=False)
  full_name: str
  decl_name: str
  generic_args: list['Type']
  
  @property
  def is_const(self) -> bool:
    return self.full_name.startswith('const ')
  
  @property
  def is_reference(self) -> bool:
    return self.full_name.endswith('&')
  
  @property
  def base_name(self) -> str:
    name = self.full_name
    if name.startswith('const '):
      name = name[len('const ') :]
      
    while name.endswith('&'):
      name = name[:-1]
      
    return name.strip()

  @property
  def is_optional(self) -> bool:
    return self.decl_name == 'optional'
  
  @property
  def is_function(self) -> bool:
    return self.decl_name == 'function'

  @property
  def is_pointer(self) -> bool:
    return self.decl_name.endswith('*')
  
  @property
  def is_rvalue_reference(self) -> bool:
    return self.full_name.endswith('&&')
  
  @property
  def is_const_ref(self) -> bool:
    return self.is_const and self.is_reference

  @property
  def unwrapped(self) -> 'Type':
    return self.generic_args[0]

  @property
  def is_enum(self) -> bool:
    return globals.has_cpp_enum(self.base_name)

  @property
  def as_enum(self) -> 'Enum':
    return globals.find_cpp_enum(self.base_name)

  @property
  def is_struct(self) -> bool:
    return globals.has_cpp_struct(self.base_name)

  @property
  def as_struct(self) -> 'Struct':
    return globals.find_cpp_struct(self.base_name)

  @property
  def is_class(self) -> bool:
    return globals.has_cpp_class(self.base_name)

  @property
  def as_class(self) -> 'Class':
    return globals.find_cpp_class(self.base_name)
  
  @property
  def as_c_type(self) -> str:
    return converter.get_c_type_from_cpp_type(self)

  def cast_to_c(self, var_name: str) -> str:
    return converter.get_cast_from_cpp_to_c(self, var_name)

  def cast_from_c(self, var_name: str) -> str:
    return converter.get_cast_from_c_to_cpp(self, var_name)


@dataclass
class Field:
  cursor: clang.cindex.Cursor = field(repr=False)
  type: Type
  name: str


@dataclass
class Constructor:
  name: str
  cursor: clang.cindex.Cursor = field(repr=False)
  parameters: list[Field]
  is_default: bool


@dataclass
class Method:
  cursor: clang.cindex.Cursor = field(repr=False)
  name: str
  return_type: Type
  parameters: list[Field]
  is_const: bool
  is_static: bool


@dataclass
class Struct:
  cursor: clang.cindex.Cursor = field(repr=False)
  namespace: str
  name: str
  fields: list[Field]
  constructors: list[Constructor]

  @property
  def full_name(self) -> str:
    return f'{self.namespace}::{self.name}' if self.namespace else self.name

  @property
  def as_c_struct(self) -> c.Struct:
    return converter.create_c_struct_from_struct(self)

  @property
  def to_c_fn_name(self) -> str:
    return self.as_c_struct.to_c_fn_name

  @property
  def to_cpp_fn_name(self) -> str:
    return self.as_c_struct.to_cpp_fn_name


@dataclass
class Class:
  cursor: clang.cindex.Cursor = field(repr=False)
  namespace: str
  name: str
  fields: list[Field]
  constructors: list[Constructor]
  methods: list[Method]

  @property
  def full_name(self) -> str:
    return f'{self.namespace}::{self.name}' if self.namespace else self.name

  @property
  def as_c_class_opaque(self) -> c.ClassOpaque:
    return converter.create_c_class_opaque_from_class(self)

  @property
  def to_c_fn_name(self) -> str:
    return self.as_c_class_opaque.to_c_fn_name

  @property
  def to_cpp_const_ref_fn_name(self) -> str:
    return self.as_c_class_opaque.to_cpp_const_ref_fn_name
  
  @property
  def to_cpp_copy_fn_name(self) -> str:
    return self.as_c_class_opaque.to_cpp_copy_fn_name
  
  @property
  def static_methods(self) -> list[Method]:
    return [m for m in self.methods if m.is_static]
  
  @property
  def static_factories(self) -> list[Method]:
    return [m for m in self.static_methods if m.return_type.decl_name == self.name]


@dataclass
class Enum:
  cursor: clang.cindex.Cursor = field(repr=False)
  namespace: str
  name: str
  values: dict[str, int]

  @property
  def full_name(self) -> str:
    return f'{self.namespace}::{self.name}' if self.namespace else self.name

  def get_value_full_name(self, index: int) -> str:
    value = list(self.values.items())[index]
    return f'{self.full_name}::{value[0]}'

  @property
  def as_c_enum(self) -> c.Enum:
    return converter.create_c_enum_from_enum(self)

  @property
  def to_cpp_fn_name(self) -> str:
    return self.as_c_enum.to_cpp_fn_name

  @property
  def to_c_fn_name(self) -> str:
    return self.as_c_enum.to_c_fn_name
