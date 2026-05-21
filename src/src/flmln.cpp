#include "flmln.h"

#include <stdint.h>

#include <array>
#include <mbgl/map/map.hpp>
#include <mbgl/style/expression/coalesce.hpp>
#include <mbgl/style/expression/comparison.hpp>
#include <mbgl/style/expression/dsl.hpp>
#include <mbgl/style/expression/expression.hpp>
#include <mbgl/style/layer.hpp>
#include <mbgl/style/layers/background_layer.hpp>
#include <mbgl/style/layers/line_layer.hpp>
#include <mbgl/style/layers/symbol_layer.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/util/run_loop.hpp>

#include "flmln/map_observer.hpp"
#include "flmln/platform.hpp"
#include "flmln/renderer_frontend.hpp"

int test_flmln() { return 42; }

void flmln_initialize() { flmln::initializePlatform(); }

// ---------------------------------
// mbgl_map_options_t
// ---------------------------------

mbgl_map_options_t mbgl_map_options_create() { return reinterpret_cast<mbgl_map_options_t>(new mbgl::MapOptions()); }

void mbgl_map_options_destroy(mbgl_map_options_t _mapOptions) {
  delete reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
}

void mbgl_map_options_set_mode(mbgl_map_options_t _mapOptions, enum MbglMapMode mode) {
  auto* mapOptions = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  mapOptions->withMapMode(static_cast<mbgl::MapMode>(mode));
}

void mbgl_map_options_set_size(mbgl_map_options_t _mapOptions, uint32_t width, uint32_t height) {
  auto* mapOptions = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  mapOptions->withSize({width, height});
}

void mbgl_map_options_set_pixel_ratio(mbgl_map_options_t _mapOptions, float pixelRatio) {
  auto* mapOptions = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  mapOptions->withPixelRatio(pixelRatio);
}

// ----------------------------------
// mbgl_tile_server_options_t
// ----------------------------------

mbgl_tile_server_options_t mbgl_tile_server_options_create() {
  auto a = new mbgl::TileServerOptions();
  return reinterpret_cast<mbgl_tile_server_options_t>(new mbgl::TileServerOptions());
}

mbgl_tile_server_options_t mbgl_tile_server_options_mapbox_configuration_create() {
  auto* configuration = new auto(mbgl::TileServerOptions::MapboxConfiguration());
  return reinterpret_cast<mbgl_tile_server_options_t>(configuration);
}

mbgl_tile_server_options_t mbgl_tile_server_options_maptiler_configuration_create() {
  auto* configuration = new auto(mbgl::TileServerOptions::MapTilerConfiguration());
  return reinterpret_cast<mbgl_tile_server_options_t>(configuration);
}

mbgl_tile_server_options_t mbgl_tile_server_options_mapvina_configuration_create() {
  auto* configuration = new auto(mbgl::TileServerOptions::MapVinaConfiguration());
  return reinterpret_cast<mbgl_tile_server_options_t>(configuration);
}

void mbgl_tile_server_options_destroy(mbgl_tile_server_options_t _tileServerOptions) {
  delete reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
}

// ---------------------------------
// mbgl_resource_options_t
// ---------------------------------

mbgl_resource_options_t mbgl_resource_options_create() {
  return reinterpret_cast<mbgl_resource_options_t>(new mbgl::ResourceOptions());
}

void mbgl_resource_options_destroy(mbgl_resource_options_t _resourceOptions) {
  delete reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
}

void mbgl_resource_options_set_api_key(mbgl_resource_options_t _resourceOptions, const char* apiKey) {
  auto* resourceOptions = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  resourceOptions->withApiKey(std::string(apiKey));
}

void mbgl_resource_options_set_tile_server_options(mbgl_resource_options_t _resourceOptions,
                                                   mbgl_tile_server_options_t _tileServerOptions) {
  auto* resourceOptions = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);
  auto* tileServerOpts = reinterpret_cast<mbgl::TileServerOptions*>(_tileServerOptions);
  resourceOptions->withTileServerOptions(*tileServerOpts);
}

// ---------------------------------
// flmln_map_observer_t
// ---------------------------------

flmln_map_observer_t flmln_map_observer_create() {
  return reinterpret_cast<flmln_map_observer_t>(new flmln::MapObserver());
}

void flmln_map_observer_destroy(flmln_map_observer_t _mapObserver) {
  delete reinterpret_cast<flmln::MapObserver*>(_mapObserver);
}

// ---------------------------------
// flmln_renderer_frontend_t
// ---------------------------------

flmln_renderer_frontend_t flmln_renderer_frontend_create() {
  return reinterpret_cast<flmln_renderer_frontend_t>(new flmln::RendererFrontend(std::nullopt));
}

void flmln_renderer_frontend_destroy(flmln_renderer_frontend_t _rendererFrontend) {
  delete reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
}

void flmln_renderer_frontend_render(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->renderFrame();
}

void flmln_renderer_frontend_set_size_and_pixel_ratio(flmln_renderer_frontend_t _rendererFrontend, uint32_t width,
                                                      uint32_t height, float pixelRatio) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setSizeAndPixelRatio({static_cast<uint32_t>(width), static_cast<uint32_t>(height)}, pixelRatio);
}

int64_t flmln_renderer_frontend_get_texture_id(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  return rendererFrontend->getTextureId();
}

void flmln_renderer_frontend_set_invalidate_callback(flmln_renderer_frontend_t _rendererFrontend, void (*callback)()) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setInvalidateCallback([callback]() { callback(); });
}

void flmln_renderer_frontend_reduce_memory_use(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->reduceMemoryUse();
}

void flmln_renderer_frontend_set_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend, bool enabled) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setTileCacheEnabled(enabled);
}

bool flmln_renderer_frontend_get_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  return rendererFrontend->getTileCacheEnabled();
}

// ---------------------------------
// mbgl_camera_options_t
// ---------------------------------

mbgl_camera_options_t mbgl_camera_options_create() {
  return reinterpret_cast<mbgl_camera_options_t>(new mbgl::CameraOptions());
}

void mbgl_camera_options_destroy(mbgl_camera_options_t _cameraOptions) {
  delete reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
}

void mbgl_camera_options_set_center(mbgl_camera_options_t _cameraOptions, double latitude, double longitude) {
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  cameraOptions->withCenter(mbgl::LatLng(latitude, longitude));
}

void mbgl_camera_options_set_zoom(mbgl_camera_options_t _cameraOptions, double zoom) {
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  cameraOptions->withZoom(zoom);
}

void mbgl_camera_options_set_bearing(mbgl_camera_options_t _cameraOptions, double bearing) {
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  cameraOptions->withBearing(bearing);
}

void mbgl_camera_options_set_pitch(mbgl_camera_options_t _cameraOptions, double pitch) {
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  cameraOptions->withPitch(pitch);
}

// ---------------------------------
// mbgl_map_t
// ---------------------------------

mbgl_map_t mbgl_map_create(flmln_renderer_frontend_t _rendererFrontend, flmln_map_observer_t _mapObserver,
                           mbgl_map_options_t _mapOptions, mbgl_resource_options_t _resourceOptions) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  auto* mapObserver = reinterpret_cast<flmln::MapObserver*>(_mapObserver);
  auto* mapOptions = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  auto* resourceOptions = reinterpret_cast<mbgl::ResourceOptions*>(_resourceOptions);

  auto map = new mbgl::Map(*rendererFrontend, *mapObserver, *mapOptions, *resourceOptions);
  return reinterpret_cast<mbgl_map_t>(map);
}

void mbgl_map_destroy(mbgl_map_t _map) { delete reinterpret_cast<mbgl::Map*>(_map); }

void mbgl_map_style_load_url(mbgl_map_t _map, const char* url) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  map->getStyle().loadURL(std::string(url));
}

void mbgl_map_jump_to(mbgl_map_t _map, mbgl_camera_options_t _cameraOptions) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  auto* cameraOptions = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  map->jumpTo(*cameraOptions);
}

void mbgl_map_set_size(mbgl_map_t _map, uint32_t width, uint32_t height) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  map->setSize({width, height});
}

mbgl_style_t mbgl_map_get_style(mbgl_map_t _map) {
  auto* map = reinterpret_cast<mbgl::Map*>(_map);
  auto& style = map->getStyle();
  return reinterpret_cast<mbgl_style_t>(&style);
}

// ---------------------------------
// mbgl_style_t
// ---------------------------------

char* mbgl_style_get_name(mbgl_style_t _style) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto name = style->getName();
  return strdup(name.c_str());
}

size_t mbgl_style_get_layers_length(mbgl_style_t _style) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto layers = style->getLayers();
  return layers.size();
}

mbgl_style_layer_t mbgl_style_get_layer_at(mbgl_style_t _style, size_t index) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto layers = style->getLayers();
  if (index >= layers.size()) return nullptr;

  auto* layer = layers[index];
  return reinterpret_cast<mbgl_style_layer_t>(layer);
}

mbgl_style_layer_t mbgl_style_get_layer(mbgl_style_t _style, const char* layerId) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto* layer = style->getLayer(std::string(layerId));
  return reinterpret_cast<mbgl_style_layer_t>(layer);
}

void mbgl_style_add_layer(mbgl_style_t _style, mbgl_style_layer_t _layer, const char* beforeLayerId) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  if (beforeLayerId) {
    style->addLayer(std::unique_ptr<mbgl::style::Layer>(layer), std::string(beforeLayerId));
  } else {
    style->addLayer(std::unique_ptr<mbgl::style::Layer>(layer));
  }
}

mbgl_style_layer_t mbgl_style_remove_layer(mbgl_style_t _style, const char* layerId) {
  auto* style = reinterpret_cast<mbgl::style::Style*>(_style);
  auto layer = style->removeLayer(std::string(layerId));
  return reinterpret_cast<mbgl_style_layer_t>(layer.release());
}

// ---------------------------------
// mbgl_style_layer_t
// ---------------------------------

void mbgl_style_layer_destroy(mbgl_style_layer_t _layer) { delete reinterpret_cast<mbgl::style::Layer*>(_layer); }

const char* mbgl_style_layer_get_id(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  auto id = layer->getID();
  return strdup(id.c_str());
}

std::map<std::string, MbglStyleLayerType> layerTypeMap = {
    {"fill", MbglStyleLayerType_Fill},
    {"line", MbglStyleLayerType_Line},
    {"symbol", MbglStyleLayerType_Symbol},
    {"circle", MbglStyleLayerType_Circle},
    {"heatmap", MbglStyleLayerType_Heatmap},
    {"fill-extrusion", MbglStyleLayerType_FillExtrusion},
    {"raster", MbglStyleLayerType_Raster},
    {"hillshade", MbglStyleLayerType_Hillshade},
    {"background", MbglStyleLayerType_Background},
};

MbglStyleLayerType mbgl_style_layer_get_type(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  auto typeInfo = layer->getTypeInfo();

  auto it = layerTypeMap.find(typeInfo->type);
  if (it != layerTypeMap.end()) return it->second;
  return MbglStyleLayerType_Unknown;
}

const char* mbgl_style_layer_get_source(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  auto sourceId = layer->getSourceID();
  return strdup(sourceId.c_str());
}

void mbgl_style_layer_set_source(mbgl_style_layer_t _layer, const char* sourceId) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  layer->setSourceID(std::string(sourceId));
  layer->getMinZoom();
}

const char* mbgl_style_layer_get_source_layer(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  auto sourceLayerId = layer->getSourceLayer();
  return strdup(sourceLayerId.c_str());
}

void mbgl_style_layer_set_source_layer(mbgl_style_layer_t _layer, const char* sourceLayerId) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  layer->setSourceLayer(std::string(sourceLayerId));
}

float mbgl_style_layer_get_min_zoom(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  return layer->getMinZoom();
}

void mbgl_style_layer_set_min_zoom(mbgl_style_layer_t _layer, float minZoom) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  layer->setMinZoom(minZoom);
}

float mbgl_style_layer_get_max_zoom(mbgl_style_layer_t _layer) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  return layer->getMaxZoom();
}

void mbgl_style_layer_set_max_zoom(mbgl_style_layer_t _layer, float maxZoom) {
  auto* layer = reinterpret_cast<mbgl::style::Layer*>(_layer);
  layer->setMaxZoom(maxZoom);
}

// ---------------------------------
// mbgl_color_t
// ---------------------------------

mbgl_color_t mbgl_color_create_from_rgba(float r, float g, float b, float a) {
  auto* color = new mbgl::Color(r, g, b, a);
  return reinterpret_cast<mbgl_color_t>(color);
}

void mbgl_color_destroy(mbgl_color_t _color) { delete reinterpret_cast<mbgl::Color*>(_color); }

float mbgl_color_get_r(mbgl_color_t _color) {
  auto* color = reinterpret_cast<mbgl::Color*>(_color);
  return color->r;
}

float mbgl_color_get_g(mbgl_color_t _color) {
  auto* color = reinterpret_cast<mbgl::Color*>(_color);
  return color->g;
}

float mbgl_color_get_b(mbgl_color_t _color) {
  auto* color = reinterpret_cast<mbgl::Color*>(_color);
  return color->b;
}

float mbgl_color_get_a(mbgl_color_t _color) {
  auto* color = reinterpret_cast<mbgl::Color*>(_color);
  return color->a;
}

// ---------------------------------
// mbgl_padding_t
// ---------------------------------

mbgl_padding_t mbgl_padding_create(float top, float right, float bottom, float left) {
  auto* padding = new mbgl::Padding{top, right, bottom, left};
  return reinterpret_cast<mbgl_padding_t>(padding);
}

void mbgl_padding_destroy(mbgl_padding_t _padding) { delete reinterpret_cast<mbgl::Padding*>(_padding); }

float mbgl_padding_get_top(mbgl_padding_t _padding) {
  auto* padding = reinterpret_cast<mbgl::Padding*>(_padding);
  return padding->top;
}

float mbgl_padding_get_right(mbgl_padding_t _padding) {
  auto* padding = reinterpret_cast<mbgl::Padding*>(_padding);
  return padding->right;
}

float mbgl_padding_get_bottom(mbgl_padding_t _padding) {
  auto* padding = reinterpret_cast<mbgl::Padding*>(_padding);
  return padding->bottom;
}

float mbgl_padding_get_left(mbgl_padding_t _padding) {
  auto* padding = reinterpret_cast<mbgl::Padding*>(_padding);
  return padding->left;
}

// ---------------------------------
// utils
// ---------------------------------

void flmln_utils_run_loop_once() { mbgl::util::RunLoop::Get()->runOnce(); }
