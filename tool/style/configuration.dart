import 'dart:convert';
import 'dart:io';
import '_.dart';

import 'package:path/path.dart' as p;

final mbglCoreUnsupportedFields = <String>{
  'text-overlap',
  'icon-overlap',
};

final mbglCoreEnumUnsupportedValues = <String, List<String>>{
  'text-rotation-alignment': ['viewport-glyph'],
  'icon-rotation-alignment': ['viewport-glyph'],
};

final refSpecJsonFile = File(p.join(projectRoot, 'tool', 'style', 'reference', 'v8.json'));
final spec = jsonDecode(refSpecJsonFile.readAsStringSync());

final outputDartFile = File(p.join(projectRoot, 'lib', 'src', 'gen', 'style.gen.dart'));
final outputCHeaderFile = File(p.join(projectRoot, 'src', 'src', 'flmln_style_gen.h'));
final outputCSourceFile = File(p.join(projectRoot, 'src', 'src', 'flmln_style_gen.cpp'));

const dartPreamble = [
  '// GENERATED CODE - DO NOT MODIFY BY HAND',
  '// Generated via tool/generate_style.dart',
  '',
  '// ignore_for_file: camel_case_types',
  '',
  'part of "package:flmln/src/style/layer.dart";',
  '',
];

const cHeaderPreamble = [
  '// GENERATED CODE - DO NOT MODIFY BY HAND',
  '// Generated via tool/generate_style.dart',
  '',
  '#pragma once',
  '',
  '#include "flmln.h"',
  '#include "stdbool.h"',
  '#include "stddef.h"',
  '',
  '#define const_char const char*',
  '',
];

const cSourcePreamble = [
  '// GENERATED CODE - DO NOT MODIFY BY HAND',
  '// Generated via tool/generate_style.dart',
  '',
  '#include "flmln_style_gen.h"',
  '',
  '#include <mbgl/style/layer.hpp>',
  '#include <mbgl/style/types.hpp>',
  '#include <mbgl/style/layers/fill_layer.hpp>',
  '#include <mbgl/style/layers/fill_extrusion_layer.hpp>',
  '#include <mbgl/style/layers/line_layer.hpp>',
  '#include <mbgl/style/layers/circle_layer.hpp>',
  '#include <mbgl/style/layers/symbol_layer.hpp>',
  '#include <mbgl/style/layers/raster_layer.hpp>',
  '#include <mbgl/style/layers/heatmap_layer.hpp>',
  '#include <mbgl/style/layers/background_layer.hpp>',
  '#include <mbgl/style/layers/hillshade_layer.hpp>',
  '',
  'using namespace mbgl;',
  '',
];
