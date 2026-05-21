import '../_.dart';
import 'utils.dart';

final cGenerator = CGenerator._();

typedef CCode = (List<String> hdr, List<String> src);

class CGenerator {
  CGenerator._();

  List<String> _generateDoc(String? doc) {
    final c = <String>[];
    if (doc != null) {
      c.add('/**');
      for (final line in doc.split('\n')) {
        c.add(' * ${line.trim()}');
      }
      c.add(' */');
    }
    return c;
  }

  CCode _generateEnums(List<SpecLayer> layers) {
    final hdr = <String>[];
    final src = <String>[];

    final allEnums = getEnums(layers);

    for (final enum_ in allEnums) {
      hdr.addAll(_generateDoc(enum_.doc));
      hdr.add('enum ${enum_.cName} {');
      final values = enum_.values.values.toList();
      for (var i = 0; i < values.length; i++) {
        final value = values[i];
        hdr.addAll(_generateDoc(value.doc).indented(2));
        hdr.add('  ${value.cName} = $i,');
      }
      hdr.add('};');
      hdr.add('');
    }

    for (final enum_ in allEnums) {
      src.add('${enum_.cName} ${enum_.castMbglToCName}(${enum_.mbglFullName} value) {');
      src.add('  switch (value) {');

      for (final value in enum_.values.values) {
        src.add('    case ${enum_.mbglFullName}::${value.mbglName}: return ${value.cName};');
      }

      src.add('  }');
      src.add('  throw std::invalid_argument("Unknown enum value");');
      src.add('}');
      src.add('');
      src.add('${enum_.mbglFullName} ${enum_.castCToMbglName}(${enum_.cName} value) {');
      src.add('  switch (value) {');

      for (final value in enum_.values.values) {
        src.add('    case ${value.cName}: return ${enum_.mbglFullName}::${value.mbglName};');
      }

      src.add('  }');
      src.add('  throw std::invalid_argument("Unknown enum value");');
      src.add('}');
      src.add('');
    }

    return (hdr, src);
  }

  CCode _generatePropertyValueTypedefs(List<SpecLayer> layers) {
    final hdr = <String>[];
    final src = <String>[];

    final propertyValues = getPropertyValues(layers);

    for (final field in propertyValues) {
      hdr.add('typedef void* ${field.cPropertyValueType};');
      hdr.add('');
    }

    return (hdr, src);
  }

  CCode _generateArrayMethods(SpecFieldArray field) {
    final hdr = <String>[];
    final src = <String>[];

    hdr.add('typedef void* ${field.cTypeName};');
    final createDef = '${field.cTypeName} ${field.cArrayCreateName}';
    late final String cast;

    // Create
    if (field.length != null) {
      cast = 'reinterpret_cast<std::array<${field.innerType.mbglTypeName}, ${field.length}>*>(ptr_)';

      final args = List.generate(field.length!, (i) => '${field.innerType.cTypeNameForHeader} v$i').join(', ');
      hdr.add('$hdrFnPrefix $createDef($args);');
      src.add('$srcFnPrefix $createDef($args) {');
      src.add('  auto arr = new std::array<${field.innerType.mbglTypeName}, ${field.length}>();');
      for (var i = 0; i < field.length!; i++) {
        src.add('  (*arr)[$i] = ${field.innerType.castCToMbgl('v$i')};');
      }
      src.add('  return static_cast<${field.cTypeName}>(arr);');
      src.add('}');
    } else {
      cast = 'reinterpret_cast<std::vector<${field.innerType.mbglTypeName}>*>(ptr_)';

      hdr.add('$hdrFnPrefix $createDef(size_t length_, ${field.innerType.cTypeNameForHeader}* values_);');
      src.add('$srcFnPrefix $createDef(size_t length_, ${field.innerType.cTypeNameForHeader}* values_) {');
      src.add('  auto arr = new std::vector<${field.innerType.mbglTypeName}>();');
      src.add('  arr->reserve(length_);');
      src.add('  for (size_t i = 0; i < length_; i++) {');
      src.add('    arr->push_back(${field.innerType.castCToMbgl('values_[i]')});');
      src.add('  }');
      src.add('  return static_cast<${field.cTypeName}>(arr);');
      src.add('}');
    }

    // Destroy
    hdr.add('$hdrFnPrefix void ${field.cArrayDestroyName}(${field.cTypeName} ptr_);');
    src.add('$srcFnPrefix void ${field.cArrayDestroyName}(${field.cTypeName} ptr_) {');
    src.add('  auto v = $cast;');
    src.add('  delete v;');
    src.add('}');

    // Length
    hdr.add('$hdrFnPrefix size_t ${field.cArrayLengthName}(${field.cTypeName} ptr_);');
    src.add('$srcFnPrefix size_t ${field.cArrayLengthName}(${field.cTypeName} ptr_) {');
    src.add('  auto v = $cast;');
    src.add('  return v->size();');
    src.add('}');

    // Get at
    final getAtDef =
        '${field.innerType.cTypeNameForHeader} ${field.cArrayGetAtName}(${field.cTypeName} ptr_, size_t index_)';
    hdr.add('$hdrFnPrefix $getAtDef;');
    src.add('$srcFnPrefix $getAtDef {');
    src.add('  auto v = $cast;');
    src.add('  return ${field.innerType.castMbglToC('(*v)[index_]')};');
    src.add('}');

    return (hdr, src);
  }

  CCode _generatePropertyValueMethods(List<SpecLayer> layers) {
    final hdr = <String>[];
    final src = <String>[];

    final propertyValues = getPropertyValues(layers);

    for (final field in propertyValues) {
      if (field.propertyType == 'color-ramp') continue; // TODO

      // Create/delete
      if (field is SpecFieldArray) {
        final arrayCodes = _generateArrayMethods(field);
        hdr.addAll(arrayCodes.$1);
        src.addAll(arrayCodes.$2);
        hdr.add('');
        src.add('');
      }

      final cToMbglCast = 'reinterpret_cast<${field.mbglPropertyValueType}*>(ptr_)';

      final constantCreateDef =
          '${field.cPropertyValueType} ${field.cPropertyValueCreateConstantFnName}(${field.cTypeNameForHeader} value_)';
      final destroyDef = 'void ${field.cPropertyValueDestroyFnName}(${field.cPropertyValueType} ptr_)';

      hdr.add('$hdrFnPrefix $constantCreateDef;');
      hdr.add('$hdrFnPrefix $destroyDef;');

      src.add('$srcFnPrefix $constantCreateDef {');
      src.add('  auto value = new ${field.mbglPropertyValueType}(${field.castCToMbgl('value_')});');
      src.add('  return reinterpret_cast<${field.cPropertyValueType}*>(value);');
      src.add('}');
      src.add('');
      src.add('$srcFnPrefix $destroyDef {');
      src.add('  auto value = $cToMbglCast;');
      src.add('  delete value;');
      src.add('}');
      src.add('');

      // isConstant, isDataDriven, isExpression, isUndefined, isZoomConstant
      final checks = ['isConstant', 'isDataDriven', 'isExpression', 'isUndefined', 'isZoomConstant'];
      final checkFnNames = [
        field.cPropertyValueIsConstantFnName,
        field.cPropertyValueIsDataDrivenFnName,
        field.cPropertyValueIsExpressionFnName,
        field.cPropertyValueIsUndefinedFnName,
        field.cPropertyValueIsZoomConstantFnName,
      ];
      for (var i = 0; i < checks.length; i++) {
        final check = checks[i];
        final fnName = checkFnNames[i];

        final def = 'bool $fnName(${field.cPropertyValueType} ptr_)';
        hdr.add('$hdrFnPrefix $def;');
        src.add('$srcFnPrefix $def {');
        src.add('  auto value = $cToMbglCast;');
        src.add('  return value->$check();');
        src.add('}');
        src.add('');
      }

      // asConstant
      final asConstantDef =
          '${field.cTypeNameForHeader} ${field.cPropertyValueAsConstantFnName}(${field.cPropertyValueType} ptr_)';
      hdr.add('$hdrFnPrefix $asConstantDef;');
      src.add('$srcFnPrefix $asConstantDef {');
      src.add('  auto value = $cToMbglCast;');
      src.add('  return ${field.castMbglToC('value->asConstant()')};');
      src.add('}');
      src.add('');

      hdr.add('');
    }

    return (hdr, src);
  }

  CCode _generateLayer(SpecLayer layer) {
    final hdr = <String>[];
    final src = <String>[];

    hdr.add('typedef void* ${layer.cName};');
    hdr.add('');

    // Create/destroy
    // Background doesn't need sourceId
    if (layer.type != 'background') {
      hdr.add('$hdrFnPrefix ${layer.cName} ${layer.cCreateFnName}(char* layerId_, char* sourceId_);');
      src.add('$srcFnPrefix ${layer.cName} ${layer.cCreateFnName}(char* layerId_, char* sourceId_) {');
      src.add('  auto layer = new ${layer.mbglClassName}(std::string(layerId_), std::string(sourceId_));');
      src.add('  return reinterpret_cast<${layer.cName}>(layer);');
      src.add('}');
      src.add('');
    } else {
      hdr.add('$hdrFnPrefix ${layer.cName} ${layer.cCreateFnName}(char* layerId_);');
      src.add('$srcFnPrefix ${layer.cName} ${layer.cCreateFnName}(char* layerId_) {');
      src.add('  auto layer = new ${layer.mbglClassName}(std::string(layerId_));');
      src.add('  return reinterpret_cast<${layer.cName}>(layer);');
      src.add('}');
      src.add('');
    }

    hdr.add('$hdrFnPrefix void ${layer.cDestroyFnName}(${layer.cName} layer_);');
    src.add('$srcFnPrefix void ${layer.cDestroyFnName}(${layer.cName} layer_) {');
    src.add('  auto layer = ${layer.castCToMbgl('layer_')};');
    src.add('  delete layer;');
    src.add('}');
    src.add('');

    for (final field in layer.fields.values) {
      final getterSignature = '${field.cPropertyValueTypeForHeader} ${field.cGetterName}(${layer.cName} layer_)';
      final setterSignature =
          'void ${field.cSetterName}(${layer.cName} layer_, ${field.cPropertyValueTypeForHeader} value_)';

      // Header
      hdr.add('$hdrFnPrefix $getterSignature;');
      hdr.add('$hdrFnPrefix $setterSignature;');
      hdr.add('');

      // Source
      src.add('$srcFnPrefix $getterSignature {');
      src.add('  auto layer = ${layer.castCToMbgl('layer_')};');
      src.add('  return ${field.castPropertyValueMbglToC('layer->${field.mbglGetterName}()')};');
      src.add('}');
      src.add('');
      src.add('$srcFnPrefix $setterSignature {');
      src.add('  auto layer = ${layer.castCToMbgl('layer_')};');
      src.add('  layer->${field.mbglSetterName}(${field.castPropertyValueCToMbgl('value_')});');
      src.add('}');
      src.add('');
    }

    return (hdr, src);
  }

  CCode generate({
    required List<SpecLayer> layers,
  }) {
    final hdr = <String>[];
    final src = <String>[];

    hdr.insertAll(0, cHeaderPreamble);
    src.insertAll(0, cSourcePreamble);

    final enumCodes = _generateEnums(layers);
    hdr.addAll(enumCodes.$1);
    src.addAll(enumCodes.$2);

    final propertyValueTypedefCodes = _generatePropertyValueTypedefs(layers);
    hdr.addAll(propertyValueTypedefCodes.$1);
    src.addAll(propertyValueTypedefCodes.$2);

    final propertyValueMethodCodes = _generatePropertyValueMethods(layers);
    hdr.addAll(propertyValueMethodCodes.$1);
    src.addAll(propertyValueMethodCodes.$2);

    final layerCodes = layers.map(_generateLayer);
    for (final code in layerCodes) {
      hdr.addAll(code.$1);
      src.addAll(code.$2);
    }

    return (hdr, src);
  }
}
