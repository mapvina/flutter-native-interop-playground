import '../_.dart';

const hdrFnPrefix = 'EXTERNC FLMLN_EXPORT';
const srcFnPrefix = 'EXTERNC';

extension SpecLayerCUtils on SpecLayer {
  String get cPrefix => 'mbgl_style_${type.toSnakeCase()}_layer';
  String get cName => '${cPrefix}_t';

  String get mbglClassName => 'style::${type.toUpperCamelCase()}Layer';
  String castCToMbgl(String varName) => 'reinterpret_cast<$mbglClassName*>($varName)';

  String get cCreateFnName => '${cPrefix}_create';
  String get cDestroyFnName => '${cPrefix}_destroy';
}

extension SpecFieldEnumValueCUtils on SpecFieldEnumValue {
  String get cName => 'MBGL_STYLE_${parent.toUpperSnakeCase()}_${name.toUpperSnakeCase()}';
  String get mbglName => name.toUpperCamelCase();
}

extension SpecFieldEnumCUtils on SpecFieldEnum {
  String get cName => 'MBGL_STYLE_${name.toUpperSnakeCase()}';

  String get mbglName {
    final result = switch (name) {
      'fill-translate-anchor' => 'TranslateAnchor',
      'fill-extrusion-translate-anchor' => 'TranslateAnchor',
      'line-translate-anchor' => 'TranslateAnchor',
      'circle-translate-anchor' => 'TranslateAnchor',
      'icon-translate-anchor' => 'TranslateAnchor',
      'text-translate-anchor' => 'TranslateAnchor',
      'icon-anchor' => 'SymbolAnchor',
      'text-anchor' => 'SymbolAnchor',
      'circle-pitch-alignment' => 'Alignment',
      'icon-pitch-alignment' => 'Alignment',
      'text-pitch-alignment' => 'Alignment',
      'text-rotation-alignment' => 'Alignment',
      'icon-rotation-alignment' => 'Alignment',
      _ => name.toUpperCamelCase(),
    };

    return '${result}Type';
  }

  String get mbglFullName => 'style::$mbglName';

  String get castMbglToCName => '${name.toSnakeCase()}_to_c';
  String get castCToMbglName => '${name.toSnakeCase()}_to_mbgl';

  String castMbglToC(String varName) => '$castMbglToCName($varName)';
  String castCToMbgl(String varName) => '$castCToMbglName($varName)';
}

extension SpecFieldArrayCUtils on SpecFieldArray {
  String get cArrayFnBaseName {
    if (length != null) return 'std_array_${innerType.cTypeNameBase.toLowerCase()}_$length';
    return 'std_vector_${innerType.cTypeNameBase.toLowerCase()}';
  }

  String get cArrayCreateName => '${cArrayFnBaseName}_create';
  String get cArrayDestroyName => '${cArrayFnBaseName}_destroy';
  String get cArrayLengthName => '${cArrayFnBaseName}_length';
  String get cArrayGetAtName => '${cArrayFnBaseName}_get_at';

  String castCToMbgl(String varName) {
    return '*reinterpret_cast<$mbglTypeName*>($varName)';
  }

  String castMbglToC(String varName) {
    return 'reinterpret_cast<$cTypeName>(const_cast<$mbglTypeName*>(&$varName))';
  }
}

extension SpecFieldCUtils on SpecField {
  String get cPrefix => 'mbgl_style_${parent.toSnakeCase()}_layer';
  String get cName => '${cPrefix}_${name.toSnakeCase()}';
  String get cGetterName => '${cName}_get';
  String get cSetterName => '${cName}_set';

  String get cTypeNameBase {
    if (this is SpecFieldArray) {
      final _this = this as SpecFieldArray;
      if (_this.length != null) return 'std_array_${_this.innerType.cTypeNameBase.toLowerCase()}_${_this.length}';
      return 'std_vector_${_this.innerType.cTypeNameBase.toLowerCase()}';
    }

    return switch (type) {
      SpecFieldType.string => 'const_char',
      SpecFieldType.number => 'float',
      SpecFieldType.boolean => 'bool',
      SpecFieldType.color => 'mbgl_color',
      SpecFieldType.padding => 'mbgl_padding',
      SpecFieldType.variableAnchorOffsetCollection => 'mbgl_variable_anchor_offset_collection',
      SpecFieldType.resolvedImage => 'mbgl_style_expression_image',
      SpecFieldType.formatted => 'mbgl_style_expression_formatted',
      SpecFieldType.enum_ => (this as SpecFieldEnum).cName,
      SpecFieldType.array => throw UnimplementedError(), // Handled above
    };
  }

  String get cTypeName {
    return switch (type) {
      SpecFieldType.string => 'const char*',
      SpecFieldType.number => 'float',
      SpecFieldType.boolean => 'bool',
      SpecFieldType.enum_ => (this as SpecFieldEnum).cName,
      _ => '${cTypeNameBase}_t',
    };
  }

  String get cTypeNameForHeader {
    if (this is SpecFieldEnum) return 'enum $cTypeName';
    return cTypeName;
  }

  String get cPropertyValueTypeNameBase {
    return switch (type) {
      SpecFieldType.string => 'string',
      SpecFieldType.number => 'float',
      SpecFieldType.boolean => 'bool',
      _ => cTypeNameBase,
    };
  }

  String get cPropertyValuePrefix => 'mbgl_style_property_value';

  String get cPropertyValueType {
    if (propertyType == 'constant') return cTypeName;
    if (propertyType == 'color-ramp') return 'mbgl_style_property_value_mbgl_color_ramp_t';

    return '${cPropertyValuePrefix}_${cPropertyValueTypeNameBase.toLowerCase()}_t';
  }

  String get cPropertyValueTypeForHeader {
    if (cPropertyValueType.startsWith('mbgl_style_property_value_')) return cPropertyValueType;
    if (this is SpecFieldEnum) return 'enum $cPropertyValueType';
    return cPropertyValueType;
  }

  String get mbglTypeName {
    if (this is SpecFieldArray) {
      final _this = this as SpecFieldArray;
      if (_this.length != null) return 'std::array<${_this.innerType.mbglTypeName}, ${_this.length}>';
      return 'std::vector<${_this.innerType.mbglTypeName}>';
    }

    return switch (type) {
      SpecFieldType.string => 'std::string',
      SpecFieldType.number => 'float',
      SpecFieldType.boolean => 'bool',
      SpecFieldType.color => 'Color',
      SpecFieldType.padding => 'Padding',
      SpecFieldType.variableAnchorOffsetCollection => 'VariableAnchorOffsetCollection',
      SpecFieldType.resolvedImage => 'style::expression::Image',
      SpecFieldType.formatted => 'style::expression::Formatted',
      SpecFieldType.enum_ => (this as SpecFieldEnum).mbglFullName,
      SpecFieldType.array => throw UnimplementedError(), // Handled above
    };
  }

  String get mbglGetterName => 'get${name.toUpperCamelCase()}';
  String get mbglSetterName => 'set${name.toUpperCamelCase()}';

  String get mbglPropertyValueType {
    if (propertyType == 'constant') return mbglTypeName;
    if (propertyType == 'color-ramp') return 'style::ColorRampPropertyValue';
    return 'style::PropertyValue<$mbglTypeName>';
  }

  String castMbglToC(String varName) {
    if (this is SpecFieldEnum) return (this as SpecFieldEnum).castMbglToC(varName);
    if (this is SpecFieldArray) return (this as SpecFieldArray).castMbglToC(varName);

    return switch (type) {
      SpecFieldType.boolean => varName,
      SpecFieldType.number => varName,
      _ => 'reinterpret_cast<$cTypeName>(const_cast<$mbglTypeName*>(&$varName))',
    };
  }

  String castCToMbgl(String varName) {
    if (this is SpecFieldEnum) return (this as SpecFieldEnum).castCToMbgl(varName);
    if (this is SpecFieldArray) return (this as SpecFieldArray).castCToMbgl(varName);

    return switch (type) {
      SpecFieldType.string => 'std::string($varName)',
      SpecFieldType.number => varName,
      SpecFieldType.boolean => varName,
      _ => '*reinterpret_cast<$mbglTypeName*>($varName)',
    };
  }

  String castPropertyValueMbglToC(String varName) {
    if (propertyType == 'constant') return castMbglToC(varName);
    return 'reinterpret_cast<$cPropertyValueType>(const_cast<$mbglPropertyValueType*>(&$varName))';
  }

  String castPropertyValueCToMbgl(String varName) {
    if (propertyType == 'constant') return castCToMbgl(varName);
    return '*reinterpret_cast<$mbglPropertyValueType*>($varName)';
  }

  String get cPropertyValueFnNamePrefix => '${cPropertyValuePrefix}_${cPropertyValueTypeNameBase.toLowerCase()}';

  String get cPropertyValueCreateConstantFnName => '${cPropertyValueFnNamePrefix}_create_constant';
  String get cPropertyValueDestroyFnName => '${cPropertyValueFnNamePrefix}_destroy';
  String get cPropertyValueIsConstantFnName => '${cPropertyValueFnNamePrefix}_is_constant';
  String get cPropertyValueIsDataDrivenFnName => '${cPropertyValueFnNamePrefix}_is_data_driven';
  String get cPropertyValueIsExpressionFnName => '${cPropertyValueFnNamePrefix}_is_expression';
  String get cPropertyValueIsUndefinedFnName => '${cPropertyValueFnNamePrefix}_is_undefined';
  String get cPropertyValueIsZoomConstantFnName => '${cPropertyValueFnNamePrefix}_is_zoom_constant';
  String get cPropertyValueAsConstantFnName => '${cPropertyValueFnNamePrefix}_as_constant';
  String get cPropertyValueAsExpressionFnName => '${cPropertyValueFnNamePrefix}_as_expression';
}

extension SpecLayerDartUtils on SpecLayer {
  String get dartClassName => '${type.toUpperCamelCase()}Layer';
}

extension SpecFieldEnumValueDartUtils on SpecFieldEnumValue {
  String get dartName => name.toCamelCase();
}

extension SpecFieldEnumDartUtils on SpecFieldEnum {
  String get dartName => name.toUpperCamelCase();

  String get dartToNativeName => '$dartName._toNative';
  String get dartFromNativeName => '$dartName._fromNative';

  String castDartToNative(String varName) => '$varName._toNative()';
  String castNativeToDart(String varName) => '$dartFromNativeName($varName)';
}

extension SpecFieldArrayDartUtils on SpecFieldArray {
  String castDartToNative(String varName) {
    if (length == null) {
      late final String cast;

      if (innerType is SpecFieldEnum) {
        cast = '$varName.toNativeList((e) => e._toNative())';
      } else {
        cast = '$varName.toNativeList()';
      }

      return '$cArrayCreateName($varName.length, $cast)';
    } else {
      var args = <String>[];
      for (var i = 0; i < length!; i++) {
        args.add(innerType.castDartToNative('$varName.\$${i + 1}'));
      }
      return '$cArrayCreateName(${args.join(', ')})';
    }
  }

  String castNativeToDart(String varName) {
    if (length == null) {
      return '$varName.toDartList($cArrayLengthName, $cArrayGetAtName, (n) => ${innerType.castNativeToDart('n')})';
    } else {
      var args = <String>[];
      for (var i = 0; i < length!; i++) {
        args.add(innerType.castNativeToDart('$cArrayGetAtName($varName, $i)'));
      }
      return '(${args.join(', ')})';
    }
  }
}

extension SpecFieldDartUtils on SpecField {
  String get dartName => name.toCamelCase();

  String get dartTypeNameAlias {
    if (this is SpecFieldArray && (this as SpecFieldArray).length != null) {
      final _this = this as SpecFieldArray;
      return 'tuple_${_this.length}_${_this.innerType.dartTypeNameBase}';
    }

    return dartTypeNameBase;
  }

  String get dartTypeNameBase {
    if (this is SpecFieldArray) {
      final _this = this as SpecFieldArray;
      if (_this.length == null) return 'List<${_this.innerType.dartTypeNameBase}>';
      return '(${List.filled(_this.length!, _this.innerType.dartTypeNameBase).join(', ')})';
    }

    return switch (type) {
      SpecFieldType.string => 'String',
      SpecFieldType.number => 'double',
      SpecFieldType.boolean => 'bool',
      SpecFieldType.color => 'ui.Color',
      SpecFieldType.padding => 'ui.EdgeInsets',
      SpecFieldType.variableAnchorOffsetCollection => 'VariableAnchorOffsetCollection',
      SpecFieldType.resolvedImage => 'ResolvedImage',
      SpecFieldType.formatted => 'Formatted',
      SpecFieldType.enum_ => (this as SpecFieldEnum).dartName,
      SpecFieldType.array => throw UnimplementedError(), // Handled above
    };
  }

  String get dartPropertyValueType {
    if (propertyType == 'constant') return dartTypeNameBase;
    if (propertyType == 'color-ramp') return 'ColorRampPropertyValue';
    return 'PropertyValue<$dartTypeNameBase>';
  }

  String castDartToNative(String varName) {
    if (this is SpecFieldEnum) return (this as SpecFieldEnum).castDartToNative(varName);
    if (this is SpecFieldArray) return (this as SpecFieldArray).castDartToNative(varName);

    return switch (type) {
      SpecFieldType.string => '$varName.toNativeUtf8().cast()',
      SpecFieldType.color => '$varName.toMbglColor()',
      SpecFieldType.padding => '$varName.toMbglPadding()',
      SpecFieldType.formatted => 'nullptr', // TODO
      SpecFieldType.resolvedImage => 'nullptr', // TODO
      SpecFieldType.variableAnchorOffsetCollection => 'nullptr', // TODO
      _ => varName,
    };
  }

  String castNativeToDart(String varName) {
    if (this is SpecFieldEnum) return (this as SpecFieldEnum).castNativeToDart(varName);
    if (this is SpecFieldArray) return (this as SpecFieldArray).castNativeToDart(varName);

    return switch (type) {
      SpecFieldType.string => '$varName.cast<Utf8>().toDartString()',
      SpecFieldType.color => '$varName.toDartColor()',
      SpecFieldType.padding => '$varName.toDartPadding()',
      SpecFieldType.formatted => '$varName as dynamic', // TODO
      SpecFieldType.resolvedImage => '$varName as dynamic', // TODO
      SpecFieldType.variableAnchorOffsetCollection => '$varName as dynamic', // TODO
      _ => varName,
    };
  }

  String dartPropertyValueFromNative(String varName) {
    if (propertyType == 'constant') return castNativeToDart(varName);
    if (propertyType == 'color-ramp') return 'ColorRampPropertyValue.fromNative($varName)';

    return 'PropertyValue<$dartTypeNameBase>.fromNative($varName)';
  }

  String dartPropertyValueToNative(String varName) {
    if (propertyType == 'constant') return castDartToNative(varName);
    return '$varName.ptr';
  }

  String get dartPropertyValueClassName => '_PropertyValue_${cPropertyValueTypeNameBase.toLowerCase()}';
}

Set<SpecField> getPropertyValues(List<SpecLayer> layers) {
  final propertyValues = <SpecField>{};
  final _added = <String>{};

  for (final layer in layers) {
    for (final field in layer.fields.values) {
      final type = field.cPropertyValueType;
      if (field.cPropertyValueType.startsWith('mbgl_style_property_value_')) {
        if (!_added.contains(type)) {
          propertyValues.add(field);
          _added.add(type);
        }
      }
    }
  }

  return propertyValues;
}

Set<SpecFieldEnum> getEnums(List<SpecLayer> layers) {
  final enums = <SpecFieldEnum>{};
  final _added = <String>{};

  for (final layer in layers) {
    for (final field in layer.fields.values) {
      if (field is SpecFieldEnum) {
        if (!_added.contains(field.cName)) {
          enums.add(field);
          _added.add(field.cName);
        }
      } else if (field is SpecFieldArray && field.innerType is SpecFieldEnum) {
        final enumField = field.innerType as SpecFieldEnum;
        if (!_added.contains(enumField.cName)) {
          enums.add(enumField);
          _added.add(enumField.cName);
        }
      }
    }
  }

  return enums;
}
