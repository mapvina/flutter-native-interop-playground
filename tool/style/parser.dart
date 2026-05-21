import 'package:equatable/equatable.dart';

import '_.dart';

final List<SpecFieldEnum> globalParsedEnums = [];
void maybeAddParsedEnum(SpecFieldEnum enum_) {
  if (globalParsedEnums.any((e) => e.name == enum_.name)) return;
  globalParsedEnums.add(enum_);
}

enum SpecFieldType {
  string,
  array,
  number,
  enum_,
  boolean,
  resolvedImage,
  padding,
  formatted,
  color,
  variableAnchorOffsetCollection;

  static SpecFieldType parse(String str) => switch (str) {
    'string' => SpecFieldType.string,
    'array' => SpecFieldType.array,
    'number' => SpecFieldType.number,
    'enum' => SpecFieldType.enum_,
    'boolean' => SpecFieldType.boolean,
    'resolvedImage' => SpecFieldType.resolvedImage,
    'padding' => SpecFieldType.padding,
    'formatted' => SpecFieldType.formatted,
    'color' => SpecFieldType.color,
    'variableAnchorOffsetCollection' => SpecFieldType.variableAnchorOffsetCollection,
    _ => throw ArgumentError('Unknown SpecFieldType: $str'),
  };
}

class SpecFieldEnumValue {
  const SpecFieldEnumValue({required this.parent, required this.name, required this.doc});

  static Map<String, SpecFieldEnumValue> parseValues(String parent, Map<String, dynamic> values) {
    return values.map(
      (k, v) => MapEntry(
        k,
        SpecFieldEnumValue(parent: parent, name: k, doc: v['doc'] as String?),
      ),
    );
  }

  final String parent;
  final String name;
  final String? doc;
}

class SpecFieldEnum extends SpecField {
  SpecFieldEnum.extend({
    required SpecField field,
    required this.values,
  }) : super(
         type: SpecFieldType.enum_,
         parent: field.parent,
         name: field.name,
         doc: field.doc,
         units: field.units,
         defaultValue: field.defaultValue,
         propertyType: field.propertyType,
         mbglCoreSupported: field.mbglCoreSupported,
       );

  static SpecFieldEnum parse(String parent, String name, Map<String, dynamic> field, {bool inner = false}) {
    final baseField = SpecField.parseBase(parent, name, field, inner: inner);
    final values = SpecFieldEnumValue.parseValues(name, field['values'] as Map<String, dynamic>);

    final unsupportedValues = mbglCoreEnumUnsupportedValues[name] ?? [];
    values.removeWhere((k, v) => unsupportedValues.contains(k));

    return SpecFieldEnum.extend(field: baseField, values: values);
  }

  final Map<String, SpecFieldEnumValue> values;

  @override
  List<Object?> get props => [...super.props, values];
}

class SpecFieldArray extends SpecField {
  SpecFieldArray.extend({
    required SpecField field,
    required this.innerType,
    this.length,
  }) : super(
         parent: field.parent,
         name: field.name,
         type: field.type,
         doc: field.doc,
         units: field.units,
         defaultValue: field.defaultValue,
         propertyType: field.propertyType,
       );

  static SpecFieldArray parse(String parent, String name, Map<String, dynamic> field) {
    final baseField = SpecField.parseBase(parent, name, field);
    final innerType = field['value'] == 'enum'
        ? SpecFieldEnum.parse(parent, name, field, inner: true)
        : SpecField(parent: '_', name: '_', type: SpecFieldType.parse(field['value'] as String));

    if (innerType is SpecFieldEnum && innerType.values.isNotEmpty) maybeAddParsedEnum(innerType);
    return SpecFieldArray.extend(
      field: baseField,
      innerType: innerType,
      length: field['length'] as int?,
    );
  }

  final SpecField innerType;
  final int? length;

  @override
  List<Object?> get props => [...super.props, innerType, length];
}

class SpecField with EquatableMixin {
  const SpecField({
    required this.parent,
    required this.name,
    required this.type,
    this.doc,
    this.units,
    this.defaultValue,
    this.propertyType,
    this.mbglCoreSupported = true,
  });

  static SpecField parseBase(String parent, String name, Map<String, dynamic> field, {bool inner = false}) {
    final type = SpecFieldType.parse(field['type'] as String);

    final mbglCoreSupported = !mbglCoreUnsupportedFields.contains(name);
    return SpecField(
      parent: parent,
      type: type,
      name: name,
      defaultValue: inner ? null : field['default'],
      units: inner ? null : field['units'] as String?,
      doc: inner ? null : field['doc'] as String?,
      propertyType: inner ? null : field['property-type'] as String?,
      mbglCoreSupported: mbglCoreSupported,
    );
  }

  static SpecField parse(String parent, String name, Map<String, dynamic> field) {
    final type = SpecFieldType.parse(field['type'] as String);
    final result = switch (type) {
      SpecFieldType.enum_ => SpecFieldEnum.parse(parent, name, field),
      SpecFieldType.array => SpecFieldArray.parse(parent, name, field),
      _ => SpecField.parseBase(parent, name, field),
    };

    if (result is SpecFieldEnum && result.values.isNotEmpty) maybeAddParsedEnum(result);
    return result;
  }

  static Map<String, SpecField> parseFields(String parent, Map<String, dynamic> fields) {
    return fields.map(
      (k, v) => MapEntry(k, SpecField.parse(parent, k, v as Map<String, dynamic>)),
    );
  }

  final String parent;
  final String name;
  final SpecFieldType type;
  final String? doc;
  final String? units;
  final dynamic defaultValue;
  final String? propertyType;
  final bool mbglCoreSupported;

  @override
  List<Object?> get props => [name, type, doc, units, defaultValue, propertyType, mbglCoreSupported];
}

class SpecLayer with EquatableMixin {
  SpecLayer({
    required this.type,
    required this.layoutFields,
    required this.paintFields,
  });

  final String type;
  final Map<String, SpecField> layoutFields;
  final Map<String, SpecField> paintFields;
  Map<String, SpecField> get fields => {...layoutFields, ...paintFields};

  @override
  List<Object?> get props => [type, layoutFields, paintFields];
}
