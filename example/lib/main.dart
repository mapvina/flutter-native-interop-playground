import 'package:example/keys.dart';
import 'package:flmln/flmln.dart';
import 'package:flutter/material.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  test();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData.from(colorScheme: ColorScheme.dark()),
      home: Scaffold(
        body: FlMlnWidget(styleUrl: styleUrl, apiKey: apiKey),
      ),
      // home: Container(),
    );
  }
}
