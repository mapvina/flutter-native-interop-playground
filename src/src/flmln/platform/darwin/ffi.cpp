#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>
#include "ffi.hpp"

// todo: define-based types to avoid so much boilerplate

using texture_registry_proxy_t = void*;
using flmln_metal_flutter_texture_t = void*;

template <typename T>
static T resolve(const char* name) {
  void* p = dlsym(RTLD_DEFAULT, name);
  T method = reinterpret_cast<T>(p);
  if (!method) {
    fprintf(stderr, "FFI stub: dlsym failed to resolve symbol: %s\n", name);
    return nullptr;
  }

  return method;
}

using FlMlnDarwinPluginGlobals_getTextureRegistry_Fn = texture_registry_proxy_t(*)();
FlMlnDarwinPluginGlobals_getTextureRegistry_Fn FlMlnDarwinPluginGlobals_getTextureRegistry_Fn_ptr = nullptr;

using FlutterTextureRegistryProxy_registerTexture_Fn = int64_t(*)(void*, void*);
FlutterTextureRegistryProxy_registerTexture_Fn FlutterTextureRegistryProxy_registerTexture_Fn_ptr = nullptr;

using FlutterTextureRegistryProxy_textureFrameAvailable_Fn = void(*)(void*, int64_t);
FlutterTextureRegistryProxy_textureFrameAvailable_Fn FlutterTextureRegistryProxy_textureFrameAvailable_Fn_ptr = nullptr;

using FlutterTextureRegistryProxy_unregisterTexture_Fn = void(*)(void*, int64_t);
FlutterTextureRegistryProxy_unregisterTexture_Fn FlutterTextureRegistryProxy_unregisterTexture_Fn_ptr = nullptr;

using FlMlnMetalFlutterTexture_create_Fn = flmln_metal_flutter_texture_t(*)();
FlMlnMetalFlutterTexture_create_Fn FlMlnMetalFlutterTexture_create_Fn_ptr = nullptr;

using FlMlnMetalFlutterTexture_destroy_Fn = void(*)(flmln_metal_flutter_texture_t);
FlMlnMetalFlutterTexture_destroy_Fn FlMlnMetalFlutterTexture_destroy_Fn_ptr = nullptr;

using FlMlnMetalFlutterTexture_updateBuffer_Fn = void(*)(flmln_metal_flutter_texture_t, void*);
FlMlnMetalFlutterTexture_updateBuffer_Fn FlMlnMetalFlutterTexture_updateBuffer_Fn_ptr = nullptr;

void ffi_initialize() {
  FlMlnDarwinPluginGlobals_getTextureRegistry_Fn_ptr = resolve<FlMlnDarwinPluginGlobals_getTextureRegistry_Fn>("FlMlnDarwinPluginGlobals_getTextureRegistry");
  FlutterTextureRegistryProxy_registerTexture_Fn_ptr = resolve<FlutterTextureRegistryProxy_registerTexture_Fn>("FlutterTextureRegistryProxy_registerTexture");
  FlutterTextureRegistryProxy_textureFrameAvailable_Fn_ptr = resolve<FlutterTextureRegistryProxy_textureFrameAvailable_Fn>("FlutterTextureRegistryProxy_textureFrameAvailable");
  FlutterTextureRegistryProxy_unregisterTexture_Fn_ptr = resolve<FlutterTextureRegistryProxy_unregisterTexture_Fn>("FlutterTextureRegistryProxy_unregisterTexture");
  FlMlnMetalFlutterTexture_create_Fn_ptr = resolve<FlMlnMetalFlutterTexture_create_Fn>("FlMlnMetalFlutterTexture_create");
  FlMlnMetalFlutterTexture_destroy_Fn_ptr = resolve<FlMlnMetalFlutterTexture_destroy_Fn>("FlMlnMetalFlutterTexture_destroy");
  FlMlnMetalFlutterTexture_updateBuffer_Fn_ptr = resolve<FlMlnMetalFlutterTexture_updateBuffer_Fn>("FlMlnMetalFlutterTexture_updateBuffer");
}

texture_registry_proxy_t ffi_FlMlnDarwinPluginGlobals_getTextureRegistry() {
  return FlMlnDarwinPluginGlobals_getTextureRegistry_Fn_ptr();
}

int64_t ffi_FlutterTextureRegistryProxy_registerTexture(texture_registry_proxy_t registry, void* texture) {
  return FlutterTextureRegistryProxy_registerTexture_Fn_ptr(registry, texture);
}

void ffi_FlutterTextureRegistryProxy_textureFrameAvailable(texture_registry_proxy_t registry, int64_t textureId) {
  FlutterTextureRegistryProxy_textureFrameAvailable_Fn_ptr(registry, textureId);
}

void ffi_FlutterTextureRegistryProxy_unregisterTexture(texture_registry_proxy_t registry, int64_t textureId) {
  FlutterTextureRegistryProxy_unregisterTexture_Fn_ptr(registry, textureId);
}

flmln_metal_flutter_texture_t ffi_FlMlnMetalFlutterTexture_create() {
  return FlMlnMetalFlutterTexture_create_Fn_ptr();
}

void ffi_FlMlnMetalFlutterTexture_destroy(flmln_metal_flutter_texture_t texture) {
  FlMlnMetalFlutterTexture_destroy_Fn_ptr(texture);
}

void ffi_FlMlnMetalFlutterTexture_updateBuffer(flmln_metal_flutter_texture_t texture, void* mtlTexture) {
  FlMlnMetalFlutterTexture_updateBuffer_Fn_ptr(texture, mtlTexture);
}
