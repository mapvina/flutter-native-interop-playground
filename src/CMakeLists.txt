cmake_minimum_required(VERSION 3.25)

####################################
# Project configuration
####################################

# Determine the target platform
if (CMAKE_SYSTEM_NAME STREQUAL "Android")
  set(PLATFORM_ANDROID TRUE)
elseif (CMAKE_SYSTEM_NAME STREQUAL "iOS")
  set(PLATFORM_IOS TRUE)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(PLATFORM_MACOS TRUE)
else()
  message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# Define the project with appropriate languages
if (PLATFORM_IOS OR PLATFORM_MACOS)
  project(flmln LANGUAGES C CXX OBJC OBJCXX)
  set(CMAKE_OBJC_FLAGS "-fobjc-arc")
  set(CMAKE_OBJCXX_FLAGS "-fobjc-arc")
else()
  project(flmln LANGUAGES C CXX)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################
# mapvina-native configuration
####################################

set(MLN_CORE_INCLUDE_DEPS ON)
set(MLN_WITH_RTTI ON)
set(MLN_WITH_GLFW OFF)

if (PLATFORM_IOS OR PLATFORM_MACOS)
  set(MLN_WITH_METAL ON)
elseif(PLATFORM_ANDROID)
  set(MLN_WITH_OPENGL ON)
endif()

add_subdirectory(../.. ../build-mapvina-native EXCLUDE_FROM_ALL)

####################################
# flmln source files
####################################

set(FLMLN_SOURCES
  src/flmln.cpp
  src/flmln.h
  src/flmln_style_gen.cpp
  src/flmln_style_gen.h
  src/flmln/flutter_texture_interface.hpp
  src/flmln/map_observer.hpp
  src/flmln/platform.hpp
  src/flmln/renderer_backend.hpp
  src/flmln/renderer_frontend.hpp
)

# Platform-specific source files
if (PLATFORM_IOS OR PLATFORM_MACOS)
  list(APPEND FLMLN_SOURCES
    src/flmln/platform/darwin/flutter_texture_interface.cpp
    src/flmln/platform/darwin/flutter_texture_interface.hpp
    src/flmln/platform/darwin/platform.cpp
    src/flmln/platform/darwin/ffi.cpp
    src/flmln/platform/darwin/ffi.hpp
  )

  list(APPEND FLMLN_SOURCES
    src/flmln/mtl/renderer_backend.hpp
    src/flmln/mtl/renderer_backend.cpp
  )
elseif (PLATFORM_ANDROID)
  list(APPEND FLMLN_SOURCES
    src/flmln/platform/android/flutter_texture_interface.cpp
    src/flmln/platform/android/flutter_texture_interface.hpp
    src/flmln/platform/android/flutter_texture.hpp
    src/flmln/platform/android/platform.cpp
  )

  if (MLN_WITH_OPENGL)
    list(APPEND FLMLN_SOURCES
      src/flmln/platform/android/renderer_backend.hpp
      src/flmln/platform/android/renderer_backend.cpp
      src/flmln/platform/android/window_renderable_resource.hpp
      src/flmln/platform/android/window_renderable_resource.cpp
    )
  endif()
endif()

# Define the shared library
add_library(flmln SHARED ${FLMLN_SOURCES})
target_include_directories(flmln PRIVATE src)
set_target_properties(flmln PROPERTIES PUBLIC_HEADER "src/flmln.h")

####################################
# Link and configure dependencies
####################################
target_link_libraries(flmln PRIVATE mbgl-core)
target_include_directories(flmln PRIVATE ../../src)
target_include_directories(flmln PRIVATE ../../include)

if (MLN_WITH_METAL)
  target_link_libraries(flmln PRIVATE mbgl-vendor-metal-cpp)
elseif (MLN_WITH_OPENGL)
  target_sources(flmln PRIVATE ../android/src/gl_functions.cpp)
elseif (MLN_WITH_VULKAN)
  # TODO
endif()

if (PLATFORM_IOS) 
  target_link_libraries(flmln PRIVATE
    "-framework Foundation"
    "-framework CoreFoundation"
    "-framework CoreGraphics"
    "-framework ImageIO"
    "-framework CoreText"
  )

  # Make sure ARC is enabled
  set_target_properties(mbgl-core PROPERTIES XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES")
  target_compile_options(mbgl-core PRIVATE -fobjc-arc)
elseif (PLATFORM_MACOS)
  target_link_libraries(flmln PRIVATE
    "-framework Foundation"
    "-framework CoreFoundation"
    "-framework CoreGraphics"
    "-framework ImageIO"
    "-framework CoreText"
  )

  # Make sure ARC is enabled
  set_target_properties(mbgl-core PROPERTIES XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES")
  target_compile_options(mbgl-core PRIVATE -fobjc-arc)
elseif (PLATFORM_ANDROID)
  target_link_libraries(flmln PRIVATE c++_shared)
  target_link_libraries(flmln PRIVATE mbgl-vendor-unique_resource)
  target_link_libraries(flmln PRIVATE mbgl-vendor-boost)

  # copied from platform/android/MapVinaAndroid/src/cpp/CMakeLists.txt
  target_include_directories(flmln PRIVATE
    ../android/src
    ../android/MapVinaAndroid/src/cpp
    ../../src
    ../default/include
  )

  target_sources(flmln PRIVATE
    ../android/MapVinaAndroid/src/cpp/i18n/collator.cpp
    ../android/MapVinaAndroid/src/cpp/i18n/number_format.cpp
    ../android/MapVinaAndroid/src/cpp/http_file_source.cpp
    ../android/MapVinaAndroid/src/cpp/logging_android.cpp
    ../android/MapVinaAndroid/src/cpp/logger.cpp
    ../android/MapVinaAndroid/src/cpp/java_types.cpp
    ../android/MapVinaAndroid/src/cpp/text/local_glyph_rasterizer.cpp
    ../android/MapVinaAndroid/src/cpp/java/util.cpp
  )
endif()

#####################################
# Packaging configuration
#####################################
if (PLATFORM_IOS OR PLATFORM_MACOS)
  set_target_properties(flmln PROPERTIES
    FRAMEWORK TRUE
    MACOSX_FRAMEWORK_IDENTIFIER "com.kekland.flmln"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.kekland.flmln"
    XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES"
  )
elseif (PLATFORM_ANDROID)
  # TODO
endif()
