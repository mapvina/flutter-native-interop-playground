import cpp_ffi.c as c
import cpp_ffi.cpp as cpp

ccode = tuple[list[str], list[str]]


def append_c_code(dst: ccode, src: ccode) -> None:
  dst[0].extend(src[0])
  dst[1].extend(src[1])
  dst[0].append('')
  dst[1].append('')


def generate_c_enum(enum: c.Enum, implement: bool = True) -> ccode:
  hdr = []
  src = []

  # Header typedef
  hdr.append(f'// C-compatible enum definition for {enum.cpp_enum.full_name}')
  hdr.append(f'typedef enum {enum.name} {{')
  for value_name, value in enum.values.items():
    hdr.append(f'  {value_name} = {value},')
  hdr.append(f'}} {enum.name};')
  
  if implement:
    src.append(f'//--------------------------------------------------------------')
    src.append(f'// C-compatible enum implementation for {enum.cpp_enum.full_name}')
    src.append(f'//--------------------------------------------------------------')
    src.append('')

  if implement:
    # Cpp -> C converter function
    src.append(f'{enum.name} {enum.to_c_fn_name}({enum.cpp_enum.full_name} value) {{')
    src.append(f'  switch (value) {{')
    for i in range(len(enum.values)):
      cpp_value_full_name = enum.cpp_enum.get_value_full_name(i)
      c_value_full_name = enum.get_value_full_name(i)
      src.append(f'    case {cpp_value_full_name}: return {c_value_full_name};')
    src.append(f'  }}')
    src.append(f'  throw std::runtime_error("Invalid enum value for {enum.cpp_enum.full_name}");')
    src.append(f'}}')

    src.append('')

    # C -> Cpp converter function
    src.append(f'{enum.cpp_enum.full_name} {enum.to_cpp_fn_name}({enum.name} value) {{')
    src.append(f'  switch (value) {{')
    for i in range(len(enum.values)):
      cpp_value_full_name = enum.cpp_enum.get_value_full_name(i)
      c_value_full_name = enum.get_value_full_name(i)
      src.append(f'    case {c_value_full_name}: return {cpp_value_full_name};')
    src.append(f'  }}')
    src.append(f'  throw std::runtime_error("Invalid enum value for {enum.name}");')
    src.append(f'}}')

  return hdr, src


def generate_c_struct(c_struct: c.Struct, implement: bool = True) -> ccode:
  hdr = []
  src = []
  
  cpp_struct = c_struct.cpp_struct

  # Header struct definition
  hdr.append(f'// C-compatible struct definition for {cpp_struct.full_name}')
  hdr.append(f'typedef struct {c_struct.name} {{')
  for field in c_struct.fields:
    hdr.append(f'  {field.type} {field.name};')
  hdr.append(f'}} {c_struct.name};')
  hdr.append('')

  # Create/destroy functions
  hdr.append(f'{c_struct.name}* {c_struct.create_fn_name}();')
  hdr.append(f'void {c_struct.destroy_fn_name}({c_struct.name}* instance);')

  if implement:
    src.append(f'//--------------------------------------------------------------')
    src.append(f'// C-compatible struct implementation for {cpp_struct.full_name}')
    src.append(f'//--------------------------------------------------------------')
    src.append('')
  
  if implement:
    # Create/destroy
    src.append(f'{c_struct.name}* {c_struct.create_fn_name}() {{')
    src.append(f'  return new {c_struct.name}();')
    src.append(f'}}')
    src.append('')
    src.append(f'void {c_struct.destroy_fn_name}({c_struct.name}* instance) {{')
    src.append(f'  delete instance;')
    src.append(f'}}')
    src.append('')

    # Cpp -> C converter function
    src.append(f'{c_struct.name} {c_struct.to_c_fn_name}(const {cpp_struct.full_name}& instance) {{')
    src.append(f'  {c_struct.name} c_instance;')

    for field in c_struct.fields:
      if field.is_optionality_field:
        primary_field = c_struct.get_field(field.primary_field_name)
        src.append(f'  c_instance.{field.name} = instance.{primary_field.cpp_field.name}.has_value();')
      else:
        src.append(f'  c_instance.{field.name} = {field.cast_from_cpp(f"instance.{field.cpp_field.name}")};')

    src.append(f'  return c_instance;')
    src.append(f'}}')
    src.append('')

    # C -> Cpp converter function
    src.append(f'{cpp_struct.full_name} {c_struct.to_cpp_fn_name}(const {c_struct.name}& instance) {{')
    src.append(f'  {cpp_struct.full_name} cpp_instance;')

    for field in c_struct.fields:
      if not field.is_optionality_field:
        if field.optionality_field_name:
          optionality_field = c_struct.get_field(field.optionality_field_name)
          src.append(f'  if (instance.{optionality_field.name}) cpp_instance.{field.cpp_field.name}.emplace({field.cast_to_cpp(f"instance.{field.name}")});')
          src.append(f'  else cpp_instance.{field.cpp_field.name} = std::nullopt;')
        else:
          src.append(f'  cpp_instance.{field.cpp_field.name} = {field.cast_to_cpp(f"instance.{field.name}")};')

    src.append(f'  return cpp_instance;')
    src.append(f'}}')

  return hdr, src

def generate_param_list(parameters: list[cpp.Field]) -> str:
  params = []
  
  for param in parameters:
    params.append(f'{param.type.as_c_type} {param.name}')
  
  return ', '.join(params)

def generate_c_class_opaque(c_class: c.ClassOpaque, implement: bool = True) -> ccode:
  hdr = []
  src = []
  
  cpp_class = c_class.cpp_class
  
  # Header typedef
  hdr.append(f'// C-compatible opaque class definition for {cpp_class.full_name}')
  hdr.append(f'typedef void* {c_class.typedef_name};')
  hdr.append('')
  
  if implement:
    src.append(f'//--------------------------------------------------------------')
    src.append(f'// C-compatible opaque class implementation for {cpp_class.full_name}')
    src.append(f'//--------------------------------------------------------------')
    src.append('')
  
  if implement:
    # Cpp -> C converter function
    src.append(f'inline {c_class.typedef_name} {c_class.to_c_fn_name}({cpp_class.full_name}* instance) {{')
    src.append(f'  return static_cast<{c_class.typedef_name}>(instance);')
    src.append(f'}}')
    src.append('')
    # C -> Cpp converter function (const ref)
    src.append(f'inline const {cpp_class.full_name}& {c_class.to_cpp_const_ref_fn_name}({c_class.typedef_name} instance) {{')
    src.append(f'  return *static_cast<{cpp_class.full_name}*>(instance);')
    src.append(f'}}')
    src.append('')
    # C -> Cpp converter function (copy)
    src.append(f'inline {cpp_class.full_name} {c_class.to_cpp_copy_fn_name}({c_class.typedef_name} instance) {{')
    src.append(f'  return *static_cast<{cpp_class.full_name}*>(instance);')
    src.append(f'}}')
    src.append('')
  
  # Constructor functions
  constructors = cpp_class.constructors
  for i in range(len(constructors)):
    constructor = constructors[i]
    param_list = generate_param_list(constructor.parameters)
    hdr.append(f'{c_class.typedef_name} {c_class.create_fn_name_indexed(i)}({param_list});')
    
    if implement:
      src.append(f'{c_class.typedef_name} {c_class.create_fn_name_indexed(i)}({param_list}) {{')
      params = ', '.join([param.type.cast_from_c(param.name) for param in constructor.parameters])
      src.append(f'  return new {cpp_class.full_name}({params});')
      src.append(f'}}')
      src.append('')
      
  # Destructor function
  hdr.append(f'void {c_class.destroy_fn_name}({c_class.typedef_name} instance);')
  if (implement):
    src.append(f'void {c_class.destroy_fn_name}({c_class.typedef_name} instance) {{')
    src.append(f'  delete static_cast<{cpp_class.full_name}*>(instance);')
    src.append(f'}}')
      

  return hdr, src