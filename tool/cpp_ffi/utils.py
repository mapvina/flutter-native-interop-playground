import re


def camel_case_to_snake_case(camel_case_string):
  # Replace ID with Id
  _str = re.sub(r'ID', 'Id', camel_case_string)
  snake_case_string = re.sub(r'(?<!^)(?=[A-Z])', '_', _str).lower()
  return snake_case_string

def cpp_name_to_c_name(cpp_name: str) -> str:
  return camel_case_to_snake_case(cpp_name.replace('::', '_')).replace('__', '_')