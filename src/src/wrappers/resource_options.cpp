#include <mbgl/storage/resource_options.hpp>

#include "enum_helpers.hpp"
#include "map_options.h"
#include "tile_server_options.h"

mbgl_resource_options_t mbgl_resource_options_create() {
  auto* options = new mbgl::ResourceOptions();
  return reinterpret_cast<mbgl_resource_options_t>(options);
}

void mbgl_resource_options_destroy(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  delete options;
}

char* mbgl_resource_options_api_key_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  const std::string& apiKey = options->apiKey();
  return strdup(apiKey.c_str());
}

void mbgl_resource_options_api_key_set(mbgl_resource_options_t _resourceOptions, const char* apiKey) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  options->withApiKey(std::string(apiKey));
}

char* mbgl_resource_options_asset_path_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  const std::string& assetPath = options->assetPath();
  return strdup(assetPath.c_str());
}

void mbgl_resource_options_asset_path_set(mbgl_resource_options_t _resourceOptions, const char* assetPath) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  options->withAssetPath(std::string(assetPath));
}

char* mbgl_resource_options_cache_path_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  const std::string& cachePath = options->cachePath();
  return strdup(cachePath.c_str());
}

void mbgl_resource_options_cache_path_set(mbgl_resource_options_t _resourceOptions, const char* cachePath) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  options->withCachePath(std::string(cachePath));
}

uint64_t mbgl_resource_options_maximum_cache_size_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  return options->maximumCacheSize();
}

void mbgl_resource_options_maximum_cache_size_set(mbgl_resource_options_t _resourceOptions, uint64_t maximumCacheSize) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  options->withMaximumCacheSize(maximumCacheSize);
}

void* mbgl_resource_options_platform_context_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  return options->platformContext();
}

void mbgl_resource_options_platform_context_set(mbgl_resource_options_t _resourceOptions, void* platformContext) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  options->withPlatformContext(platformContext);
}

mbgl_tile_server_options_t mbgl_resource_options_tile_server_options_get(mbgl_resource_options_t _resourceOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  auto tileServerOptions = options->tileServerOptions();
  return reinterpret_cast<mbgl_tile_server_options_t>(new mbgl::TileServerOptions(tileServerOptions));
}

void mbgl_resource_options_tile_server_options_set(mbgl_resource_options_t _resourceOptions,
                                                   mbgl_tile_server_options_t _tileServerOptions) {
  auto* options = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  auto* tileServerOptions = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  options->withTileServerOptions(*tileServerOptions);
}