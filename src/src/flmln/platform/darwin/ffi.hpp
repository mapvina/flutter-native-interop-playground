#pragma once

#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>

// todo: define-based types to avoid so much boilerplate

using texture_registry_proxy_t = void*;
using flmln_metal_flutter_texture_t = void*;

void ffi_initialize();
texture_registry_proxy_t ffi_FlMlnDarwinPluginGlobals_getTextureRegistry();
int64_t ffi_FlutterTextureRegistryProxy_registerTexture(texture_registry_proxy_t registry, void* texture);
void ffi_FlutterTextureRegistryProxy_textureFrameAvailable(texture_registry_proxy_t registry, int64_t textureId);
void ffi_FlutterTextureRegistryProxy_unregisterTexture(texture_registry_proxy_t registry, int64_t textureId);
flmln_metal_flutter_texture_t ffi_FlMlnMetalFlutterTexture_create();
void ffi_FlMlnMetalFlutterTexture_destroy(flmln_metal_flutter_texture_t texture);
void ffi_FlMlnMetalFlutterTexture_updateBuffer(flmln_metal_flutter_texture_t texture, void* mtlTexture);