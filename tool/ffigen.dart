import 'dart:io';

import 'package:ffigen/ffigen.dart';

void main() {
  final packageRoot = Platform.script.resolve('../');
  FfiGenerator(
    output: Output(
      dartFile: packageRoot.resolve('lib/src/gen/flmln_bindings.dart'),
      preamble: '''
// ignore_for_file: camel_case_types, non_constant_identifier_names, unused_element, unused_field, return_of_invalid_type, void_checks, annotate_overrides, no_leading_underscores_for_local_identifiers, library_private_types_in_public_api
''',
      style: NativeExternalBindings(assetId: 'flmln_bindings'),
    ),
    headers: Headers(
      entryPoints: [
        packageRoot.resolve('src/src/flmln.h'),
        packageRoot.resolve('src/src/flmln_style_gen.h'),
      ],
    ),
    functions: Functions(
      include: (decl) => true,
      includeSymbolAddress: (decl) => decl.originalName.contains('_destroy'),
    ),
    structs: Structs.includeAll,
    enums: Enums.includeAll,
    typedefs: Typedefs.includeAll,
    unions: Unions.includeAll,
    unnamedEnums: UnnamedEnums.includeAll,
    macros: Macros.includeAll,
    globals: Globals.includeAll,
  ).generate();
}
