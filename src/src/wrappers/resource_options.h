#pragma once

#include "../flmln.h"
#include "tile_server_options.h"

typedef void* mbgl_resource_options_t;

FFI mbgl_resource_options_t mbgl_resource_options_create();
FFI void mbgl_resource_options_destroy(mbgl_resource_options_t _resourceOptions);

FFI char* mbgl_resource_options_api_key_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_api_key_set(mbgl_resource_options_t _resourceOptions, const char* apiKey);

FFI char* mbgl_resource_options_asset_path_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_asset_path_set(mbgl_resource_options_t _resourceOptions, const char* assetPath);

FFI char* mbgl_resource_options_cache_path_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_cache_path_set(mbgl_resource_options_t _resourceOptions, const char* cachePath);

FFI uint64_t mbgl_resource_options_maximum_cache_size_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_maximum_cache_size_set(mbgl_resource_options_t _resourceOptions,
                                                      uint64_t maximumCacheSize);

FFI void* mbgl_resource_options_platform_context_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_platform_context_set(mbgl_resource_options_t _resourceOptions, void* platformContext);

FFI mbgl_tile_server_options_t mbgl_resource_options_tile_server_options_get(mbgl_resource_options_t _resourceOptions);
FFI void mbgl_resource_options_tile_server_options_set(mbgl_resource_options_t _resourceOptions,
                                                       mbgl_tile_server_options_t _tileServerOptions);