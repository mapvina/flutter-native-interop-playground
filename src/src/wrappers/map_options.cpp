#include "map_options.h"

#include <mbgl/map/map_options.hpp>

#include "enum_helpers.hpp"

mbgl_map_options_t mbgl_map_options_create() {
  auto* options = new mbgl::MapOptions();
  return reinterpret_cast<mbgl_map_options_t>(options);
}

void mbgl_map_options_destroy(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  delete options;
}

MBGL_CONSTRAIN_MODE mbgl_map_options_constrain_mode_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return mbgl_constrain_mode_to_c(options->constrainMode());
}

void mbgl_map_options_constrain_mode_set(mbgl_map_options_t _mapOptions, enum MBGL_CONSTRAIN_MODE mode) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withConstrainMode(mbgl_constrain_mode_from_c(mode));
}

bool mbgl_map_options_cross_source_collisions_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return options->crossSourceCollisions();
}

void mbgl_map_options_cross_source_collisions_set(mbgl_map_options_t _mapOptions, bool enableCollisions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withCrossSourceCollisions(enableCollisions);
}

MBGL_MAP_MODE mbgl_map_options_map_mode_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return mbgl_map_mode_to_c(options->mapMode());
}

void mbgl_map_options_map_mode_set(mbgl_map_options_t _mapOptions, enum MBGL_MAP_MODE mode) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withMapMode(mbgl_map_mode_from_c(mode));
}

MBGL_NORTH_ORIENTATION mbgl_map_options_north_orientation_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return static_cast<MBGL_NORTH_ORIENTATION>(options->northOrientation());
}

void mbgl_map_options_north_orientation_set(mbgl_map_options_t _mapOptions, enum MBGL_NORTH_ORIENTATION orientation) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withNorthOrientation(static_cast<mbgl::NorthOrientation>(orientation));
}

float mbgl_map_options_pixel_ratio_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return options->pixelRatio();
}

void mbgl_map_options_pixel_ratio_set(mbgl_map_options_t _mapOptions, float pixelRatio) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withPixelRatio(pixelRatio);
}

MBGL_SIZE mbgl_map_options_size_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  mbgl::Size size = options->size();
  MBGL_SIZE c_size;
  c_size.width = size.width;
  c_size.height = size.height;
  return c_size;
}

void mbgl_map_options_size_set(mbgl_map_options_t _mapOptions, struct MBGL_SIZE size) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  mbgl::Size mbgl_size(size.width, size.height);
  options->withSize(mbgl_size);
}

MBGL_VIEWPORT_MODE mbgl_map_options_viewport_mode_get(mbgl_map_options_t _mapOptions) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  return mbgl_viewport_mode_to_c(options->viewportMode());
}

void mbgl_map_options_viewport_mode_set(mbgl_map_options_t _mapOptions, enum MBGL_VIEWPORT_MODE mode) {
  auto* options = reinterpret_cast<mbgl::MapOptions*>(_mapOptions);
  options->withViewportMode(mbgl_viewport_mode_from_c(mode));
}
