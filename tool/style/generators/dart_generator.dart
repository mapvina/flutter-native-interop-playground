import '../_.dart';
import 'utils.dart';

final dartGenerator = DartGenerator._();

class DartGenerator {
  DartGenerator._();

  List<String> _doc(String? doc) {
    final c = <String>[];
    if (doc != null) {
      for (final line in doc.split('\n')) {
        c.add('/// ${line.trim()}');
      }
    }
    return c;
  }

  List<String> _generateLayer(SpecLayer layer) {
    final c = <String>[];

    final className = layer.dartClassName;

    c.addAll([
      'class $className extends Layer {',
      '  $className.fromNative(super.ptr, {super.ownedByDart}): super._fromNative();',
      '',
    ]);

    final fields = layer.fields.values.toList();

    // Constructor
    c.add('  $className({');
    c.add('    required String id,');
    if (layer.type != 'background') c.add('    required String sourceId,');

    for (var i = 0; i < fields.length; i++) {
      final field = fields[i];
      c.add('    ${field.dartPropertyValueType}? ${field.dartName},');
    }

    c.add('    super.minZoom,');
    c.add('    super.maxZoom,');

    final idPtrCast = 'id.toNativeUtf8(allocator: zoneArena).cast()';
    final sourceIdPtrCast = 'sourceId.toNativeUtf8(allocator: zoneArena).cast()';

    if (layer.type != 'background') {
      c.add('    super.sourceLayer,');
      c.add('  }): super._(withZoneArena(() => ${layer.cCreateFnName}($idPtrCast, $sourceIdPtrCast))) {');
    } else {
      c.add('  }): super._(withZoneArena(() => ${layer.cCreateFnName}($idPtrCast))) {');
    }

    for (var i = 0; i < fields.length; i++) {
      final field = fields[i];
      c.add('    if (${field.dartName} != null) this.${field.dartName} = ${field.dartName};');
    }

    c.add('  }');
    c.add('');

    // Finalizers
    c.add('  static final _finalizer = NativeFinalizer(addresses.${layer.cDestroyFnName});');
    c.add('');
    c.add('  @override');
    c.add('  void attachFinalizer() {');
    c.add('    _finalizer.attach(this, ptr, detach: this);');
    c.add('  }');
    c.add('');
    c.add('  @override');
    c.add('  void detachFinalizer() {');
    c.add('    _finalizer.detach(this);');
    c.add('  }');
    c.add('');

    // Fields
    for (var i = 0; i < fields.length; i++) {
      final field = fields[i];
      final isLast = i == fields.length - 1;

      c.addAll(_doc(field.doc).indented(2));
      var getter = '${field.cGetterName}(ptr)';
      getter = field.dartPropertyValueFromNative(getter);

      var setter = field.dartPropertyValueToNative('value');
      setter = '${field.cSetterName}(ptr, $setter)';

      c.add('  ${field.dartPropertyValueType} get ${field.dartName} => $getter;');
      c.add('  set ${field.dartName}(${field.dartPropertyValueType} value) => $setter;');

      if (!isLast) c.add('');
    }

    // Property list
    c.add('');
    c.add('  @override');
    c.add('  Map<String, Object> get properties => {');
    c.add('    ...super.properties,');
    for (var i = 0; i < fields.length; i++) {
      final field = fields[i];
      c.add('    \'${field.dartName}\': ${field.dartName},');
    }
    c.add('  };');
    c.add('}');

    return c;
  }

  List<String> _generateEnums(List<SpecLayer> layers) {
    final c = <String>[];

    final allEnums = getEnums(layers);

    for (final enum_ in allEnums) {
      c.addAll(_doc(enum_.doc));
      c.add('enum ${enum_.dartName} {');
      final values = enum_.values.values.toList();
      for (var i = 0; i < values.length; i++) {
        final value = values[i];
        final isLast = i == values.length - 1;

        c.addAll(_doc(value.doc).indented(2));
        c.add('  ${value.dartName}${isLast ? ';' : ','}');

        if (!isLast) c.add('');
      }

      c.add('');

      c.add('  static ${enum_.dartName} _fromNative(${enum_.cTypeName} value) => switch (value) {');
      for (final value in values) {
        c.add('    ${enum_.cTypeName}.${value.cName} => ${enum_.dartName}.${value.dartName},');
      }
      c.add('  };');

      c.add('');
      c.add('  ${enum_.cTypeName} _toNative() => switch (this) {');
      for (final value in values) {
        c.add('    ${enum_.dartName}.${value.dartName} => ${enum_.cTypeName}.${value.cName},');
      }
      c.add('  };');

      c.add('}');
      c.add('');
    }

    return c;
  }

  List<String> _generatePropertyValueMethods(List<SpecLayer> layers) {
    final c = <String>[];

    final propertyValues = getPropertyValues(layers).toList();
    propertyValues.sort((a, b) {
      if (a is SpecFieldArray && b is SpecFieldArray) {
        if (a.length != null && b.length != null) {
          return a.length!.compareTo(b.length!);
        } else if (a.length != null) {
          return -1;
        } else if (b.length != null) {
          return 1;
        }
      } else if (a is SpecFieldArray) {
        return 1;
      } else if (b is SpecFieldArray) {
        return -1;
      }

      return 0;
    });

    propertyValues.removeWhere((v) => v.propertyType == 'color-ramp');

    // Create helper typedefs for record types
    for (final pv in propertyValues) {
      if (pv is SpecFieldArray && pv.length != null) {
        final typeName = pv.dartTypeNameBase;
        c.add('typedef ${pv.dartTypeNameAlias} = $typeName;');
      }
    }

    c.add('');

    List<String> _createPvSwitch(String Function(SpecField) resultGenerator, {bool isOnGeneric = false}) {
      final c = <String>[];

      for (final pv in propertyValues) {
        if (isOnGeneric) {
          c.add('const (${pv.dartTypeNameAlias}) => ${resultGenerator(pv)},');
        } else {
          c.add('(${pv.dartTypeNameAlias} v) => ${resultGenerator(pv)},');
        }
      }

      c.add('_ => throw UnimplementedError("Unsupported property value type: \$T"),');

      return c;
    }

    c.add('class PropertyValueFactory {');
    c.add(
      '  static PropertyValue<T> fromNative<T>(mbgl_style_property_value_t ptr, {bool ownedByDart = false}) => switch (T) {',
    );
    c.addAll(
      _createPvSwitch(
        (pv) => '${pv.dartPropertyValueClassName}.fromNative(ptr, ownedByDart: ownedByDart) as PropertyValue<T>',
        isOnGeneric: true,
      ).indented(4),
    );
    c.add('  };');
    c.add('');
    c.add('  static PropertyValue<T> constant<T>(T value) => switch (value) {');
    c.addAll(
      _createPvSwitch(
        (pv) => '${pv.dartPropertyValueClassName}.constant(v) as PropertyValue<T>',
        isOnGeneric: false,
      ).indented(4),
    );
    c.add('  };');
    c.add('}');
    c.add('');

    for (final pv in propertyValues) {
      c.add('class ${pv.dartPropertyValueClassName} extends PropertyValue<${pv.dartTypeNameBase}> {');
      c.add('  ${pv.dartPropertyValueClassName}.fromNative(super.ptr, {super.ownedByDart});');
      c.add('');
      c.add('  ${pv.dartPropertyValueClassName}.constant(${pv.dartTypeNameBase} value): super(');
      c.add('    ${pv.cPropertyValueCreateConstantFnName}(${pv.castDartToNative('value')}),');
      c.add('    ownedByDart: true,');
      c.add('  );');
      c.add('');
      c.add('  static final _finalizer = NativeFinalizer(addresses.${pv.cPropertyValueDestroyFnName});');
      c.add('');
      c.add('  @override');
      c.add('  void attachFinalizer() {');
      c.add('    _finalizer.attach(this, ptr, detach: this);');
      c.add('  }');
      c.add('');
      c.add('  @override');
      c.add('  void detachFinalizer() {');
      c.add('    _finalizer.detach(this);');
      c.add('  }');
      c.add('');
      c.add('  @override');
      c.add(
        '  ${pv.dartTypeNameBase} get asConstant => ${pv.castNativeToDart('${pv.cPropertyValueAsConstantFnName}(ptr)')};',
      );
      c.add('');
      c.add('  @override');
      c.add('  bool get isConstant => ${pv.cPropertyValueIsConstantFnName}(ptr);');
      c.add('');
      c.add('  @override');
      c.add('  bool get isDataDriven => ${pv.cPropertyValueIsDataDrivenFnName}(ptr);');
      c.add('');
      c.add('  @override');
      c.add('  bool get isExpression => ${pv.cPropertyValueIsExpressionFnName}(ptr);');
      c.add('');
      c.add('  @override');
      c.add('  bool get isUndefined => ${pv.cPropertyValueIsUndefinedFnName}(ptr);');
      c.add('');
      c.add('  @override');
      c.add('  bool get isZoomConstant => ${pv.cPropertyValueIsZoomConstantFnName}(ptr);');
      c.add('}');
      c.add('');
    }

    // c.add('class PropertyValueFfi {');

    // // Create
    // c.add('  static mbgl_style_property_value_t create<T>(T value) => switch (value) {');
    // c.addAll(
    //   _createPvSwitch((pv) => '${pv.cPropertyValueCreateConstantFnName}(${pv.castDartToNative('v')})').indented(4),
    // );
    // c.add('  };');
    // c.add('');

    // // Destroy
    // c.add('  static void destroy<T>(mbgl_style_property_value_t ptr) => switch(T) {');
    // c.addAll(
    //   _createPvSwitch((pv) => '${pv.cPropertyValueDestroyFnName}(ptr)', isOnGeneric: true).indented(4),
    // );
    // c.add('  };');
    // c.add('');

    // // boolean methods
    // final fnNames = ['isConstant', 'isDataDriven', 'isExpression', 'isUndefined', 'isZoomConstant'];
    // final cFnNames = [
    //   (SpecField field) => field.cPropertyValueIsConstantFnName,
    //   (SpecField field) => field.cPropertyValueIsDataDrivenFnName,
    //   (SpecField field) => field.cPropertyValueIsExpressionFnName,
    //   (SpecField field) => field.cPropertyValueIsUndefinedFnName,
    //   (SpecField field) => field.cPropertyValueIsZoomConstantFnName,
    // ];

    // for (var i = 0; i < fnNames.length; i++) {
    //   final fnName = fnNames[i];
    //   final cFnNameGenerator = cFnNames[i];

    //   c.add('  static bool $fnName<T>(mbgl_style_property_value_t ptr) => switch(T) {');
    //   c.addAll(
    //     _createPvSwitch((pv) => '${cFnNameGenerator(pv)}(ptr)', isOnGeneric: true).indented(4),
    //   );
    //   c.add('  };');
    //   c.add('');
    // }

    // // as constant
    // c.add('  static T asConstant<T>(mbgl_style_property_value_t ptr) => switch(T) {');
    // c.addAll(
    //   _createPvSwitch(
    //     (pv) => '${pv.castNativeToDart('${pv.cPropertyValueAsConstantFnName}(ptr)')} as T',
    //     isOnGeneric: true,
    //   ).indented(4),
    // );
    // c.add('  };');
    // c.add('');

    // c.add('}');

    return c;
  }

  List<String> generate({
    required List<SpecLayer> layers,
  }) {
    final c = <String>[];
    c.insertAll(0, dartPreamble);

    for (var i = 0; i < layers.length; i++) {
      final layer = layers[i];
      final isLast = i == layers.length - 1;

      c.addAll(_generateLayer(layer));

      if (!isLast) c.add('');
    }

    c.add('');
    c.addAll(_generateEnums(layers));
    c.add('');
    c.addAll(_generatePropertyValueMethods(layers));
    c.add('');

    return c;
  }
}
