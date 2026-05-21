#!/usr/bin/env python3

import pathlib
import cpp_ffi.globals as globals
import cpp_ffi.parser as parser
import cpp_ffi.converter as converter
import cpp_ffi.generator as generator

parser.configure_clang()

# -- Configuration --

script_dir = pathlib.Path(__file__).parent.resolve()
root_dir = script_dir.parent.resolve()
mapvina_native_dir = root_dir / 'third-party' / 'mapvina-native'

output_source_file = root_dir / 'src' / 'src' / 'flmln_ffi_gen.cpp'
output_header_file = root_dir / 'src' / 'src' / 'flmln_ffi_gen.h'

# List of C++ names for which manual implementations exist and should not be auto-generated
# manual_implementations = [
#   'mbgl::util::UnitBezier',
# ]

to_generate = {
  'mbgl/tile/tile_id.hpp': [
    'mbgl::CanonicalTileID',
    'mbgl::UnwrappedTileID',
    'mbgl::OverscaledTileID',
  ],
  'mbgl/map/mode.hpp': [
    'mbgl::MapMode',
    'mbgl::ConstrainMode',
    'mbgl::ViewportMode',
    'mbgl::MapDebugOptions',
  ],
  'mbgl/util/geo.hpp': [
    'mbgl::LatLng',
    'mbgl::LatLng::WrapMode',
    'mbgl::LatLngBounds',
    'mbgl::NorthOrientation',
  ],
  'mbgl/util/unitbezier.hpp': [
    'mbgl::util::UnitBezier',
  ],
  'mbgl/map/camera.hpp': [
    'mbgl::AnimationOptions',
  ],
  'mbgl/map/bound_options.hpp': [
    'mbgl::BoundOptions',
  ],
}


header_preamble = [
  '#pragma once',
  '',
  '#include "stdint.h"',
  '#include "stdbool.h"',
  '',
]

source_preamble = [
  '#include "flmln_ffi_gen.h"',
  '',
  # '#include <flmln_ffi_manual.hpp>',
  *[f'#include <{header}>' for header in to_generate.keys()],
  '',
]

# -- Generation --

ccode: generator.ccode = ([], [])


ccode[0].extend(header_preamble)
ccode[1].extend(source_preamble)

# First, parse everything to build a cache
for header in to_generate.keys():
  header_path = pathlib.Path(mapvina_native_dir / 'include' / header).resolve()
  result = parser.parse(parser.get_tu(header_path))
  globals.add_from_parse_result(result)


def should_implement(cpp_full_name: str) -> bool:
  return True
  # return cpp_full_name not in manual_implementations


# Enums
for header, names in to_generate.items():
  enum_names = [name for name in names if globals.has_cpp_enum(name)]
  for enum_name in enum_names:
    enum = globals.find_cpp_enum(enum_name)
    c_enum = converter.create_c_enum_from_enum(enum)
    globals.add_c_enum(c_enum)

# Opaque classes
for header, names in to_generate.items():
  class_names = [name for name in names if globals.has_cpp_class(name)]
  for class_name in class_names:
    cpp_class = globals.find_cpp_class(class_name)
    c_class_opaque = converter.create_c_class_opaque_from_class(cpp_class)
    globals.add_c_class_opaque(c_class_opaque)

# Structs
for header, struct_names in to_generate.items():
  struct_names = [name for name in struct_names if globals.has_cpp_struct(name)]
  for struct_name in struct_names:
    cpp_struct = globals.find_cpp_struct(struct_name)
    c_struct = converter.create_c_struct_from_struct(cpp_struct)
    globals.add_c_struct(c_struct)

# Codegen
all_names = list()
for names in to_generate.values():
  all_names.extend(names)

# Codegen enums first
for name in all_names:
  is_enum = globals.has_cpp_enum(name)

  if is_enum:
    c_enum = globals.c_enums[name]
    cpp_enum = c_enum.cpp_enum
    code = generator.generate_c_enum(c_enum, implement=should_implement(cpp_enum.full_name))
    generator.append_c_code(ccode, code)

for name in all_names:
  is_enum = globals.has_cpp_enum(name)
  is_struct = globals.has_cpp_struct(name)
  is_class = globals.has_cpp_class(name)

  if is_enum:
    continue

  if is_struct:
    c_struct = globals.c_structs[name]
    cpp_struct = c_struct.cpp_struct
    code = generator.generate_c_struct(c_struct, implement=should_implement(cpp_struct.full_name))
    generator.append_c_code(ccode, code)
  elif is_class:
    c_class_opaque = globals.c_class_opaques[name]
    cpp_class = c_class_opaque.cpp_class
    code = generator.generate_c_class_opaque(c_class_opaque, implement=should_implement(cpp_class.full_name))
    generator.append_c_code(ccode, code)
  else:
    print(f'Warning: No C++ entity found for {name}')

with open(output_header_file, 'w') as f:
  f.write('\n'.join(ccode[0]))

with open(output_source_file, 'w') as f:
  f.write('\n'.join(ccode[1]))
