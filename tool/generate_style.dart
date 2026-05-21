#!/usr/bin/env dart
// Generates the Dart style spec and the C/C++ bindings for talking to mapvina-native.

import 'style/_.dart';

void main() {
  var layers = <SpecLayer>[];
  final layerTypes = jsonMapAs(spec['layer']['type']['values']).keys;

  for (final type in layerTypes) {
    final name = type;
    final paintFields = SpecField.parseFields(name, jsonMapAs(spec['paint_$name']));
    final layoutFields = SpecField.parseFields(name, jsonMapAs(spec['layout_$name']));

    paintFields.removeWhere((key, field) => !field.mbglCoreSupported);
    layoutFields.removeWhere((key, field) => !field.mbglCoreSupported);

    layers.add(SpecLayer(type: name, layoutFields: layoutFields, paintFields: paintFields));
  }

  globalParsedEnums.removeWhere((v) => v.values.isEmpty || !v.mbglCoreSupported);

  // Dart
  final dartCode = dartGenerator.generate(layers: layers);
  outputDartFile.writeAsStringSync(dartCode.join('\n'));

  // C/C++
  final (cHdrCode, cSrcCode) = cGenerator.generate(layers: layers);
  outputCHeaderFile.writeAsStringSync(cHdrCode.join('\n'));
  outputCSourceFile.writeAsStringSync(cSrcCode.join('\n'));
}
