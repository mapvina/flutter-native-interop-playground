from dataclasses import dataclass, field
import cpp_ffi.cpp as cpp
import cpp_ffi.converter as converter


@dataclass
class Enum:
  name: str
  values: dict[str, int]
  cpp_enum: cpp.Enum = field(repr=False)

  @property
  def to_cpp_fn_name(self) -> str:
    return f'{self.name.lower()}_to_cpp'

  @property
  def to_c_fn_name(self) -> str:
    return f'{self.name.lower()}_to_c'

  def get_value_full_name(self, index: int) -> str:
    return list(self.values.keys())[index]


@dataclass
class Field:
  type: str
  name: str
  optionality_field_name: str | None
  primary_field_name: str | None
  is_optionality_field: bool
  cpp_field: cpp.Field | None = field(repr=False)
  
  def cast_to_cpp(self, var_name: str) -> str:
    return converter.get_cast_from_c_to_cpp(self.cpp_field.type, var_name)
  
  def cast_from_cpp(self, var_name: str) -> str:
    return converter.get_cast_from_cpp_to_c(self.cpp_field.type, var_name)


@dataclass
class Struct:
  name: str
  fields: list[Field]
  cpp_struct: cpp.Struct
  
  def get_field(self, name: str) -> Field:
    for f in self.fields:
      if f.name == name:
        return f
      
    raise ValueError(f'Field {name} not found in struct {self.name}')
  
  @property
  def create_fn_name(self) -> str:
    return f'{self.name.lower()}_create'
  
  @property
  def destroy_fn_name(self) -> str:
    return f'{self.name.lower()}_destroy'
  
  @property
  def to_c_fn_name(self) -> str:
    return f'{self.name.lower()}_to_c'
  
  @property
  def to_cpp_fn_name(self) -> str:
    return f'{self.name.lower()}_to_cpp'

@dataclass
class ClassOpaque:
  typedef_name: str
  cpp_class: cpp.Class = field(repr=False)
  
  @property
  def base_name(self) -> str:
    return self.typedef_name[:-2]
  
  @property
  def to_c_fn_name(self) -> str:
    return f'{self.base_name.lower()}_to_c'
  
  @property
  def to_cpp_const_ref_fn_name(self) -> str:
    return f'{self.base_name.lower()}_to_cpp_const_ref'

  @property
  def to_cpp_copy_fn_name(self) -> str:
    return f'{self.base_name.lower()}_to_cpp_copy'

  @property
  def create_fn_name(self) -> str:
    return f'{self.base_name.lower()}_create'
  
  @property
  def destroy_fn_name(self) -> str:
    return f'{self.base_name.lower()}_destroy'
  
  def create_fn_name_indexed(self, index: int) -> str:
    return f'{self.create_fn_name}_{index}'
  
  def create_fn_name_factory(self, factory: cpp.Method) -> str:
    return f'{self.create_fn_name}_{factory.name}'
