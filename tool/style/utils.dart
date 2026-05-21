import 'dart:io';

import 'package:path/path.dart' as p;

final scriptDir = p.dirname(Platform.script.toFilePath());
final projectRoot = p.normalize(p.join(scriptDir, '..'));

List<T> jsonListAs<T>(dynamic list) => (list as List<dynamic>).cast<T>();
Map<String, T> jsonMapAs<T>(dynamic map) => (map as Map<String, dynamic>).cast<String, T>();

extension StringUtils on String {
  String capitalize() => isEmpty ? this : '${this[0].toUpperCase()}${substring(1)}';

  String toCamelCase() {
    final parts = split(RegExp(r'[_\- ]+'));
    return parts.first + parts.skip(1).map((v) => v.capitalize()).join();
  }

  String toUpperCamelCase() {
    final parts = split(RegExp(r'[_\- ]+'));
    return parts.map((v) => v.capitalize()).join();
  }

  String toSnakeCase() {
    final b = StringBuffer();

    final parts = splitMapJoin(
      RegExp(r'[_\-]+|(?=[A-Z])'),
      onMatch: (m) => ' ',
      onNonMatch: (n) => n,
    ).split(' ');

    for (var i = 0; i < parts.length; i++) {
      final part = parts[i];
      if (part.isEmpty) continue;
      if (i > 0) b.write('_');
      b.write(part.toLowerCase());
    }

    return b.toString();
  }

  String toUpperSnakeCase() => toSnakeCase().toUpperCase();
}

extension Indented on List<String> {
  List<String> indented([int spaces = 2]) {
    final indent = ' ' * spaces;
    return map((line) => '$indent$line').toList();
  }
}
