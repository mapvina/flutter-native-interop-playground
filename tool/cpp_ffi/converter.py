import cpp_ffi.c as c
import cpp_ffi.cpp as cpp
import cpp_ffi.utils as utils


def cpp_name_to_c_name(cpp_name: str) -> str:
  return utils.camel_case_to_snake_case(cpp_name.replace('::', '_')).replace('__', '_')


def cpp_enum_name_to_c_enum_name(cpp_enum_name: str) -> str:
  return cpp_name_to_c_name(cpp_enum_name).upper()


def cpp_enum_value_to_c_enum_value(cpp_enum_name: str, cpp_enum_value: str) -> str:
  return f'{cpp_enum_name_to_c_enum_name(cpp_enum_name)}_{cpp_name_to_c_name(cpp_enum_value).upper()}'


def cpp_struct_name_to_c_struct_name(cpp_struct_name: str) -> str:
  return cpp_name_to_c_name(cpp_struct_name).upper()


def cpp_class_name_to_c_class_opaque_typedef_name(cpp_class_name: str) -> str:
  return cpp_name_to_c_name(cpp_class_name) + '_t'


def create_c_enum_from_enum(enum: cpp.Enum) -> c.Enum:
  return c.Enum(
    name=cpp_enum_name_to_c_enum_name(enum.full_name),
    values={cpp_enum_value_to_c_enum_value(enum.full_name, k): v for k, v in enum.values.items()},
    cpp_enum=enum,
  )


def get_cast_from_cpp_to_c(type_: cpp.Type, var_name: str) -> str:
  cast = var_name
  type = type_

  if type.is_optional:
    cast = f'{cast}.value()'
    type = type.unwrapped

  basic_cast_switcher = {
    'int': cast,
    'float': cast,
    'double': cast,
    'bool': cast,
    'std::string': f'{cast}.c_str()',
  }

  if basic_cast_switcher.get(type.base_name) is not None:
    cast = basic_cast_switcher[type.base_name]
  elif type.base_name == 'mbgl::Duration':
    cast = f'std::chrono::duration_cast<std::chrono::milliseconds>({cast}).count()'
  elif type.is_enum:
    cast = f'{type.as_enum.to_c_fn_name}({cast})'
  elif type.is_struct:
    cast = f'{type.as_struct.to_c_fn_name}({cast})'
  elif type.is_class:
    cast = f'{type.as_class.to_c_fn_name}({cast})'
  else:
    # TODO
    pass

  return cast


def get_cast_from_c_to_cpp(type_: cpp.Type, var_name: str) -> str:
  cast = var_name
  type = type_

  if type.is_optional:
    type = type.unwrapped

  basic_cast_switcher = {
    'int': cast,
    'float': cast,
    'double': cast,
    'bool': cast,
    'std::string': f'std::string({cast})',
  }

  if basic_cast_switcher.get(type.base_name) is not None:
    cast = basic_cast_switcher[type.base_name]
  elif type.base_name == 'Duration':
    cast = f'std::chrono::milliseconds({cast})'
  elif type.is_enum:
    cast = f'{type.as_enum.to_cpp_fn_name}({cast})'
  elif type.is_struct:
    cast = f'{type.as_struct.to_cpp_fn_name}({cast})'
  elif type.is_class:
    if type.is_rvalue_reference:
      cast = f'{type.as_class.to_cpp_copy_fn_name}({cast})'
    else:
      cast = f'{type.as_class.to_cpp_const_ref_fn_name}({cast})'
  else:
    # TODO
    pass

  return cast


def get_c_type_from_cpp_type(type: cpp.Type) -> str:
  switcher = {
    'int': 'int',
    'float': 'float',
    'double': 'double',
    'bool': 'bool',
    'std::string': 'char*',
    'Duration': 'int64_t',
    'uint8_t': 'uint8_t',
    'uint16_t': 'uint16_t',
    'uint32_t': 'uint32_t',
    'uint64_t': 'uint64_t',
    'int8_t': 'int8_t',
    'int16_t': 'int16_t',
    'int32_t': 'int32_t',
    'int64_t': 'int64_t',
  }


  if switcher.get(type.base_name) is not None:
    return switcher[type.base_name]
  elif type.is_enum:
    return type.as_enum.as_c_enum.name
  elif type.is_struct:
    return type.as_struct.as_c_struct.name
  elif type.is_class:
    return type.as_class.as_c_class_opaque.typedef_name
  else:
    c_name = cpp_struct_name_to_c_struct_name(type.base_name)
    print(f'Warning: Unhandled type mapping for {type.full_name}: defaulting to {c_name}')
    return c_name


def create_c_field_from_field(field: cpp.Field) -> list[c.Field]:
  result_fields = []
  c_field_name = cpp_name_to_c_name(field.name)
  field_type = field.type

  # generate a has_ field for optional fields
  is_optional = field.type.is_optional
  is_function = field.type.is_function

  if is_function:
    print(f'Warning: Skipping function field {field.name}')
    return result_fields

  if is_optional:
    field_type = field.type.generic_args[0]
    result_fields.append(
      c.Field(
        type='bool',
        name=f'has_{c_field_name}',
        optionality_field_name=None,
        primary_field_name=c_field_name,
        is_optionality_field=True,
        cpp_field=None,
      )
    )

  result_fields.append(
    c.Field(
      type=get_c_type_from_cpp_type(field_type),
      name=c_field_name,
      optionality_field_name=f'has_{c_field_name}' if is_optional else None,
      primary_field_name=None,
      is_optionality_field=False,
      cpp_field=field,
    )
  )

  return result_fields


def create_c_struct_from_struct(struct: cpp.Struct) -> c.Struct:
  fields: list[c.Field] = []

  # Use constructor parameters if there's exactly one constructor
  if len(struct.constructors) == 1:
    constructor = struct.constructors[0]
    fields = constructor.parameters

  # Otherwise, use all fields
  if len(fields) == 0:
    fields = struct.fields

  return c.Struct(
    name=cpp_struct_name_to_c_struct_name(struct.full_name),
    fields=[c_field for f in fields for c_field in create_c_field_from_field(f)],
    cpp_struct=struct,
  )


def create_c_class_opaque_from_class(cls: cpp.Class) -> c.ClassOpaque:
  return c.ClassOpaque(
    typedef_name=cpp_class_name_to_c_class_opaque_typedef_name(cls.full_name),
    cpp_class=cls,
  )
