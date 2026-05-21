#!/usr/bin/env python3

# Options:
#
# --verbose : Enables verbose output.
#
# ios: Builds iOS xcframework.
# android: Builds Android libraries.
#
# If no platform is specified, builds for everything.

import subprocess
import shlex
import pathlib
import sys
import time
import os
from tqdm.auto import tqdm

plugin_root = pathlib.Path(__file__).parent.parent
mapvina_root = plugin_root / 'third-party/mapvina-native'
mapvina_flutter_root = mapvina_root / 'platform/flutter'

build_type = 'RelWithDebInfo'

# only for verbose builds
verbose = False

def log(msg: str):
  try:
    tqdm.write(msg)
  except Exception:
    print(msg)

def execute(command, cwd = plugin_root):
  log(f'execute: {command} (cwd={cwd})')
  if not verbose:
    proc = subprocess.Popen(
      shlex.split(command),
      cwd=cwd,
      stdout=subprocess.DEVNULL,
      stderr=subprocess.STDOUT,
      text=True,
      bufsize=1,
    )

    ret = proc.wait()
    if ret != 0:
      raise subprocess.CalledProcessError(ret, command)
  else:
    subprocess.run(shlex.split(command), cwd=cwd, check=True)

# Copies the src to the mapvina-native/platform/flutter directory
def copy_src_to_mapvina_native():
  execute(f'rm -rf {mapvina_flutter_root}')
  execute(f'cp -rf {plugin_root / "src"} {mapvina_flutter_root}')

# Generates cmake build files:
# - generator: CMake generator to use
# - system_name: CMake system name
# - build_name: Name to append to the build directory
# - opts: Additional CMake options as a dictionary
#
# Returns: build directory path (relative to mapvina root)
def execute_cmake_gen(generator, system_name, build_name, opts):
  opts_str = ' '.join([f'-D{key}={value}' for key, value in opts.items()])
  build_dir = f'build-{system_name}-{build_name}'

  execute(
    f'cmake -G {generator} -S . -B {mapvina_root / build_dir} '
    f'-DCMAKE_SYSTEM_NAME={system_name} '
    f'{opts_str}',
    cwd=mapvina_flutter_root
  )

  return build_dir

# Executes cmake build:
# - build_dir: Build directory path (relative to mapvina root)
#
# Returns: None
def execute_cmake_build(build_dir):
  execute(
    f'cmake --build {build_dir} --target flmln --config {build_type}',
    cwd=mapvina_root
  )

############################################################
#
# iOS
#
############################################################

# Builds iOS framework for given sysroot
# - sysroot: iOS sysroot (iphoneos or iphonesimulator)
#
# Returns: path to built framework
def build_ios_framework(sysroot):
  with tqdm(total=2, desc=f'build_ios_framework({sysroot})', unit='step', colour='magenta') as pbar:
    build_dir = execute_cmake_gen(
      generator='Xcode',
      system_name='iOS',
      build_name=sysroot,
      opts={
        'CMAKE_OSX_SYSROOT': sysroot,
        'CMAKE_OSX_ARCHITECTURES': 'arm64'
      }
    )
    pbar.update(1)
  
    execute_cmake_build(build_dir)
    pbar.update(1)
    return mapvina_root / build_dir / f'{build_type}-{sysroot}' / 'flmln.framework'

# Builds iOS xcframework.
# Will call build_ios_framework for both iphoneos and iphonesimulator.
#
# Returns: None
def build_ios_xcframework(output_path):
  with tqdm(total=3, desc='build_ios_xcframework', unit='step', colour='white') as pbar:
    iphoneos_framework = build_ios_framework('iphoneos')
    pbar.update(1)

    iphonesimulator_framework = build_ios_framework('iphonesimulator')
    pbar.update(1)

    execute(f'rm -rf {output_path}')
    execute(
      f'xcodebuild -create-xcframework '
      f'-framework {iphoneos_framework} '
      f'-framework {iphonesimulator_framework} '
      f'-output {output_path}'
    )
    pbar.update(1)

#############################################################
#
# macOS
#
#############################################################

# Builds macOS xcframework.
# (Note: only arm64 architecture is supported for now)
#
# Returns: None
def build_macos_xcframework(output_path):
  with tqdm(total=2, desc='build_macos_xcframework', unit='step', colour='cyan') as pbar:
    build_dir = execute_cmake_gen(
      generator='Xcode',
      system_name='Darwin',
      build_name='macos-arm64',
      opts={
        'CMAKE_OSX_ARCHITECTURES': 'arm64'
      }
    )
    pbar.update(1)

    execute_cmake_build(build_dir)
    pbar.update(1)

    framework_path = mapvina_root / build_dir / f'{build_type}' / 'flmln.framework'

    execute(f'rm -rf {output_path}')
    execute(
      f'xcodebuild -create-xcframework '
      f'-framework {framework_path} '
      f'-output {output_path}'
    )

#############################################################
#
# Android
#
#############################################################

# Builds android dynamic library for given ABI:
# - abi: Android ABI (arm64-v8a, armeabi-v7a, x86, x86_64)
#
# Returns: path to built library
def build_android_for_abi(abi):
  with tqdm(total=2, desc=f'build_android_for_abi({abi})', unit='step', colour='blue') as pbar:
    android_ndk_home = os.environ.get('ANDROID_NDK_HOME')
    ndk_toolchain = f"{android_ndk_home}/build/cmake/android.toolchain.cmake"
  
    build_dir = execute_cmake_gen(
      generator='Ninja',
      system_name='Android',
      build_name=abi,
      opts={
        'CMAKE_TOOLCHAIN_FILE': ndk_toolchain,
        'ANDROID_ABI': abi,
        'ANDROID_PLATFORM': '23',
      }
    )
    pbar.update(1)
  
    execute_cmake_build(build_dir)
    return mapvina_root / build_dir / f'libflmln.so'
  
# Returns a path to libc++_shared.so from the NDK for the given ABI
def get_ndk_abi_libcpp_shared(abi):
  abi_to_folder_map = {
    'arm64-v8a': 'aarch64-linux-android',
    'armeabi-v7a': 'arm-linux-androideabi',
    'x86': 'i686-linux-android',
    'x86_64': 'x86_64-linux-android',
  }

  abi_folder = abi_to_folder_map[abi]
  android_ndk_home = pathlib.Path(os.environ.get('ANDROID_NDK_HOME'))
  # TODO: harcoded 'darwin-x86_64' should be replaced with host system detection
  libcpp_shared_path = android_ndk_home / 'toolchains' / 'llvm' / 'prebuilt' / 'darwin-x86_64' / 'sysroot' / 'usr' / 'lib' / abi_folder / 'libc++_shared.so'
  return libcpp_shared_path

# Builds android dynamic libraries for selected ABIs:
# - abis: List of Android ABIs to build (arm64-v8a, armeabi-v7a, x86, x86_64)
# - output_dir: Directory to copy built libraries to. Libraries will be placed under the directory with the abi name.
def build_android(abis, output_dir):
  with tqdm(total=len(abis), desc='build_android', unit='abi', colour='green') as pbar:
    for abi in abis:
      built_library_path = build_android_for_abi(abi)

      dest_dir = pathlib.Path(output_dir) / abi
      dest_dir.mkdir(parents=True, exist_ok=True)
      dest_library_path = dest_dir / 'libflmln.so'

      if dest_library_path.exists(): dest_library_path.unlink()

      # wait 5 seconds before copy. sometimes it gets corrupted or smth
      # the ELF is zero bytes without this.
      time.sleep(5.0)
      execute(f'cp {built_library_path} {dest_library_path}')
      pbar.update(1)

      # copy libc++_shared.so
      libcpp_shared_src = get_ndk_abi_libcpp_shared(abi)
      libcpp_shared_dest = dest_dir / 'libc++_shared.so'
      if libcpp_shared_dest.exists(): libcpp_shared_dest.unlink()
      execute(f'cp {libcpp_shared_src} {libcpp_shared_dest}')

##############################################################
#
# Main
#
##############################################################

def __run__():
    args = sys.argv[1:]

    copy_src_to_mapvina_native()

    global verbose
    verbose = '--verbose' in args

    is_darwin = 'darwin' in args
    is_ios = is_darwin or 'ios' in args
    is_macos = is_darwin or 'macos' in args
    is_android = 'android' in args
    has_args = is_darwin or is_ios or is_macos or is_android

    total_steps = 0
    if not has_args or is_ios: total_steps += 1
    if not has_args or is_macos: total_steps += 1
    if not has_args or is_android: total_steps += 1

    with tqdm(total=total_steps, desc='build_libraries', unit='step', colour='yellow') as pbar:
      if not has_args or is_ios:
        output_xcframework_path = plugin_root / 'ios/flmln/Artifacts/flmln.xcframework'
        build_ios_xcframework(output_xcframework_path)

        pbar.update(1)

      if not has_args or is_macos:
        output_xcframework_path = plugin_root / 'macos/flmln/Artifacts/flmln.xcframework'
        build_macos_xcframework(output_xcframework_path)

        pbar.update(1)

      if not has_args or is_android:
        output_android_dir = plugin_root / 'android/src/main/jniLibs'
        build_android(
          # abis=['arm64-v8a', 'armeabi-v7a', 'x86', 'x86_64'],
          abis=['arm64-v8a'],
          output_dir=output_android_dir
        )

        pbar.update(1)

if __name__ == '__main__':
    __run__()