# installation instructions:

install bazelisk (required for ios builds):

```bash
bazelisk
```

clone mapvina-native with submodules at a specific commit: (TODO: maybe there's a better way to do this?)

```bash
git clone https://github.com/mapvina/mapvina-native \
    --filter=blob:none \
    --no-checkout \
    third-party/mapvina-native
cd third-party/mapvina-native
git checkout 29428dce42000484d387ffc7825326faf35c093d
git submodule update --init --recursive --depth 1

```

clean build artifacts:

* install `cmake`
* Create a new python env with e.g. `venv`.

```bash
./tool/clean_build.py
```

build the dynamic libraries (by default, builds in `RelWithDebInfo`):

```bash
./tool/build-libraries.py # build everything

./tool/build_libraries.py ios
./tool/build_libraries.py macos
./tool/build_libraries.py android

./tool/build-libraries.py --verbose # see build output
```

generate style code:

```bash
./tool/generate_style.dart
```

run ffigen:

```bash
./tool/ffigen.py
```

testing only: create a `example/lib/keys.dart` file and add your style url/api key:

```dart
const styleUrl = 'https://api.maptiler.com/maps/streets-v4-dark/style.json?key=x';
const apiKey = 'x';
```

run the project:

```bash
cd example
flutter run
```

# notable folders/files:

`lib` - Dart code

`src` - C/C++ code (copied over to third-party/mapvina-native/platform/flutter) during builds

`tool` - build scripts

`ios/flmln/Sources` and `macos/flmln/Sources` - Swift code for texture interfacing with Flutter (NOTE: those two folders are almost exactly the same! i couldn't find a way to share them in a Darwin folder.)

`android/src/main` - contains some Java code from MapVina native (some Android stuff uses JNI to use Java objects from C++ code)
