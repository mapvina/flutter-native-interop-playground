#include "flmln_ffi_gen.h"

#include <mbgl/tile/tile_id.hpp>
#include <mbgl/map/mode.hpp>
#include <mbgl/util/geo.hpp>
#include <mbgl/util/unitbezier.hpp>
#include <mbgl/map/camera.hpp>
#include <mbgl/map/bound_options.hpp>

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::MapMode
//--------------------------------------------------------------

MBGL_MAP_MODE mbgl_map_mode_to_c(mbgl::MapMode value) {
  switch (value) {
    case mbgl::MapMode::Continuous: return MBGL_MAP_MODE_CONTINUOUS;
    case mbgl::MapMode::Static: return MBGL_MAP_MODE_STATIC;
    case mbgl::MapMode::Tile: return MBGL_MAP_MODE_TILE;
  }
  throw std::runtime_error("Invalid enum value for mbgl::MapMode");
}

mbgl::MapMode mbgl_map_mode_to_cpp(MBGL_MAP_MODE value) {
  switch (value) {
    case MBGL_MAP_MODE_CONTINUOUS: return mbgl::MapMode::Continuous;
    case MBGL_MAP_MODE_STATIC: return mbgl::MapMode::Static;
    case MBGL_MAP_MODE_TILE: return mbgl::MapMode::Tile;
  }
  throw std::runtime_error("Invalid enum value for MBGL_MAP_MODE");
}

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::ConstrainMode
//--------------------------------------------------------------

MBGL_CONSTRAIN_MODE mbgl_constrain_mode_to_c(mbgl::ConstrainMode value) {
  switch (value) {
    case mbgl::ConstrainMode::None: return MBGL_CONSTRAIN_MODE_NONE;
    case mbgl::ConstrainMode::HeightOnly: return MBGL_CONSTRAIN_MODE_HEIGHT_ONLY;
    case mbgl::ConstrainMode::WidthAndHeight: return MBGL_CONSTRAIN_MODE_WIDTH_AND_HEIGHT;
    case mbgl::ConstrainMode::Screen: return MBGL_CONSTRAIN_MODE_SCREEN;
  }
  throw std::runtime_error("Invalid enum value for mbgl::ConstrainMode");
}

mbgl::ConstrainMode mbgl_constrain_mode_to_cpp(MBGL_CONSTRAIN_MODE value) {
  switch (value) {
    case MBGL_CONSTRAIN_MODE_NONE: return mbgl::ConstrainMode::None;
    case MBGL_CONSTRAIN_MODE_HEIGHT_ONLY: return mbgl::ConstrainMode::HeightOnly;
    case MBGL_CONSTRAIN_MODE_WIDTH_AND_HEIGHT: return mbgl::ConstrainMode::WidthAndHeight;
    case MBGL_CONSTRAIN_MODE_SCREEN: return mbgl::ConstrainMode::Screen;
  }
  throw std::runtime_error("Invalid enum value for MBGL_CONSTRAIN_MODE");
}

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::ViewportMode
//--------------------------------------------------------------

MBGL_VIEWPORT_MODE mbgl_viewport_mode_to_c(mbgl::ViewportMode value) {
  switch (value) {
    case mbgl::ViewportMode::Default: return MBGL_VIEWPORT_MODE_DEFAULT;
    case mbgl::ViewportMode::FlippedY: return MBGL_VIEWPORT_MODE_FLIPPED_Y;
  }
  throw std::runtime_error("Invalid enum value for mbgl::ViewportMode");
}

mbgl::ViewportMode mbgl_viewport_mode_to_cpp(MBGL_VIEWPORT_MODE value) {
  switch (value) {
    case MBGL_VIEWPORT_MODE_DEFAULT: return mbgl::ViewportMode::Default;
    case MBGL_VIEWPORT_MODE_FLIPPED_Y: return mbgl::ViewportMode::FlippedY;
  }
  throw std::runtime_error("Invalid enum value for MBGL_VIEWPORT_MODE");
}

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::MapDebugOptions
//--------------------------------------------------------------

MBGL_MAP_DEBUG_OPTIONS mbgl_map_debug_options_to_c(mbgl::MapDebugOptions value) {
  switch (value) {
    case mbgl::MapDebugOptions::NoDebug: return MBGL_MAP_DEBUG_OPTIONS_NO_DEBUG;
    case mbgl::MapDebugOptions::TileBorders: return MBGL_MAP_DEBUG_OPTIONS_TILE_BORDERS;
    case mbgl::MapDebugOptions::ParseStatus: return MBGL_MAP_DEBUG_OPTIONS_PARSE_STATUS;
    case mbgl::MapDebugOptions::Timestamps: return MBGL_MAP_DEBUG_OPTIONS_TIMESTAMPS;
    case mbgl::MapDebugOptions::Collision: return MBGL_MAP_DEBUG_OPTIONS_COLLISION;
    case mbgl::MapDebugOptions::Overdraw: return MBGL_MAP_DEBUG_OPTIONS_OVERDRAW;
    case mbgl::MapDebugOptions::StencilClip: return MBGL_MAP_DEBUG_OPTIONS_STENCIL_CLIP;
    case mbgl::MapDebugOptions::DepthBuffer: return MBGL_MAP_DEBUG_OPTIONS_DEPTH_BUFFER;
  }
  throw std::runtime_error("Invalid enum value for mbgl::MapDebugOptions");
}

mbgl::MapDebugOptions mbgl_map_debug_options_to_cpp(MBGL_MAP_DEBUG_OPTIONS value) {
  switch (value) {
    case MBGL_MAP_DEBUG_OPTIONS_NO_DEBUG: return mbgl::MapDebugOptions::NoDebug;
    case MBGL_MAP_DEBUG_OPTIONS_TILE_BORDERS: return mbgl::MapDebugOptions::TileBorders;
    case MBGL_MAP_DEBUG_OPTIONS_PARSE_STATUS: return mbgl::MapDebugOptions::ParseStatus;
    case MBGL_MAP_DEBUG_OPTIONS_TIMESTAMPS: return mbgl::MapDebugOptions::Timestamps;
    case MBGL_MAP_DEBUG_OPTIONS_COLLISION: return mbgl::MapDebugOptions::Collision;
    case MBGL_MAP_DEBUG_OPTIONS_OVERDRAW: return mbgl::MapDebugOptions::Overdraw;
    case MBGL_MAP_DEBUG_OPTIONS_STENCIL_CLIP: return mbgl::MapDebugOptions::StencilClip;
    case MBGL_MAP_DEBUG_OPTIONS_DEPTH_BUFFER: return mbgl::MapDebugOptions::DepthBuffer;
  }
  throw std::runtime_error("Invalid enum value for MBGL_MAP_DEBUG_OPTIONS");
}

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::LatLng::WrapMode
//--------------------------------------------------------------

MBGL_LAT_LNG_WRAP_MODE mbgl_lat_lng_wrap_mode_to_c(mbgl::LatLng::WrapMode value) {
  switch (value) {
    case mbgl::LatLng::WrapMode::Unwrapped: return MBGL_LAT_LNG_WRAP_MODE_UNWRAPPED;
    case mbgl::LatLng::WrapMode::Wrapped: return MBGL_LAT_LNG_WRAP_MODE_WRAPPED;
  }
  throw std::runtime_error("Invalid enum value for mbgl::LatLng::WrapMode");
}

mbgl::LatLng::WrapMode mbgl_lat_lng_wrap_mode_to_cpp(MBGL_LAT_LNG_WRAP_MODE value) {
  switch (value) {
    case MBGL_LAT_LNG_WRAP_MODE_UNWRAPPED: return mbgl::LatLng::WrapMode::Unwrapped;
    case MBGL_LAT_LNG_WRAP_MODE_WRAPPED: return mbgl::LatLng::WrapMode::Wrapped;
  }
  throw std::runtime_error("Invalid enum value for MBGL_LAT_LNG_WRAP_MODE");
}

//--------------------------------------------------------------
// C-compatible enum implementation for mbgl::NorthOrientation
//--------------------------------------------------------------

MBGL_NORTH_ORIENTATION mbgl_north_orientation_to_c(mbgl::NorthOrientation value) {
  switch (value) {
    case mbgl::NorthOrientation::Upwards: return MBGL_NORTH_ORIENTATION_UPWARDS;
    case mbgl::NorthOrientation::Rightwards: return MBGL_NORTH_ORIENTATION_RIGHTWARDS;
    case mbgl::NorthOrientation::Downwards: return MBGL_NORTH_ORIENTATION_DOWNWARDS;
    case mbgl::NorthOrientation::Leftwards: return MBGL_NORTH_ORIENTATION_LEFTWARDS;
  }
  throw std::runtime_error("Invalid enum value for mbgl::NorthOrientation");
}

mbgl::NorthOrientation mbgl_north_orientation_to_cpp(MBGL_NORTH_ORIENTATION value) {
  switch (value) {
    case MBGL_NORTH_ORIENTATION_UPWARDS: return mbgl::NorthOrientation::Upwards;
    case MBGL_NORTH_ORIENTATION_RIGHTWARDS: return mbgl::NorthOrientation::Rightwards;
    case MBGL_NORTH_ORIENTATION_DOWNWARDS: return mbgl::NorthOrientation::Downwards;
    case MBGL_NORTH_ORIENTATION_LEFTWARDS: return mbgl::NorthOrientation::Leftwards;
  }
  throw std::runtime_error("Invalid enum value for MBGL_NORTH_ORIENTATION");
}

//--------------------------------------------------------------
// C-compatible opaque class implementation for mbgl::CanonicalTileID
//--------------------------------------------------------------

inline mbgl_canonical_tile_id_t mbgl_canonical_tile_id_to_c(mbgl::CanonicalTileID* instance) {
  return static_cast<mbgl_canonical_tile_id_t>(instance);
}

inline const mbgl::CanonicalTileID& mbgl_canonical_tile_id_to_cpp_const_ref(mbgl_canonical_tile_id_t instance) {
  return *static_cast<mbgl::CanonicalTileID*>(instance);
}

inline mbgl::CanonicalTileID mbgl_canonical_tile_id_to_cpp_copy(mbgl_canonical_tile_id_t instance) {
  return *static_cast<mbgl::CanonicalTileID*>(instance);
}

void mbgl_canonical_tile_id_destroy(mbgl_canonical_tile_id_t instance) {
  delete static_cast<mbgl::CanonicalTileID*>(instance);
}

//--------------------------------------------------------------
// C-compatible opaque class implementation for mbgl::UnwrappedTileID
//--------------------------------------------------------------

inline mbgl_unwrapped_tile_id_t mbgl_unwrapped_tile_id_to_c(mbgl::UnwrappedTileID* instance) {
  return static_cast<mbgl_unwrapped_tile_id_t>(instance);
}

inline const mbgl::UnwrappedTileID& mbgl_unwrapped_tile_id_to_cpp_const_ref(mbgl_unwrapped_tile_id_t instance) {
  return *static_cast<mbgl::UnwrappedTileID*>(instance);
}

inline mbgl::UnwrappedTileID mbgl_unwrapped_tile_id_to_cpp_copy(mbgl_unwrapped_tile_id_t instance) {
  return *static_cast<mbgl::UnwrappedTileID*>(instance);
}

void mbgl_unwrapped_tile_id_destroy(mbgl_unwrapped_tile_id_t instance) {
  delete static_cast<mbgl::UnwrappedTileID*>(instance);
}

//--------------------------------------------------------------
// C-compatible opaque class implementation for mbgl::OverscaledTileID
//--------------------------------------------------------------

inline mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_to_c(mbgl::OverscaledTileID* instance) {
  return static_cast<mbgl_overscaled_tile_id_t>(instance);
}

inline const mbgl::OverscaledTileID& mbgl_overscaled_tile_id_to_cpp_const_ref(mbgl_overscaled_tile_id_t instance) {
  return *static_cast<mbgl::OverscaledTileID*>(instance);
}

inline mbgl::OverscaledTileID mbgl_overscaled_tile_id_to_cpp_copy(mbgl_overscaled_tile_id_t instance) {
  return *static_cast<mbgl::OverscaledTileID*>(instance);
}

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_0(uint8_t overscaledZ, int16_t wrap, mbgl_canonical_tile_id_t canonical_tile_id) {
  return new mbgl::OverscaledTileID(overscaledZ, wrap, mbgl_canonical_tile_id_to_cpp_const_ref(canonical_tile_id));
}

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_1(uint8_t overscaledZ, int16_t wrap, uint8_t z, uint32_t x, uint32_t y) {
  return new mbgl::OverscaledTileID(overscaledZ, wrap, z, x, y);
}

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_2(uint8_t z, uint32_t x, uint32_t y) {
  return new mbgl::OverscaledTileID(z, x, y);
}

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_3(mbgl_canonical_tile_id_t canonical_tile_id) {
  return new mbgl::OverscaledTileID(mbgl_canonical_tile_id_to_cpp_const_ref(canonical_tile_id));
}

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_4(mbgl_canonical_tile_id_t canonical_tile_id) {
  return new mbgl::OverscaledTileID(mbgl_canonical_tile_id_to_cpp_copy(canonical_tile_id));
}

void mbgl_overscaled_tile_id_destroy(mbgl_overscaled_tile_id_t instance) {
  delete static_cast<mbgl::OverscaledTileID*>(instance);
}

//--------------------------------------------------------------
// C-compatible opaque class implementation for mbgl::LatLng
//--------------------------------------------------------------

inline mbgl_lat_lng_t mbgl_lat_lng_to_c(mbgl::LatLng* instance) {
  return static_cast<mbgl_lat_lng_t>(instance);
}

inline const mbgl::LatLng& mbgl_lat_lng_to_cpp_const_ref(mbgl_lat_lng_t instance) {
  return *static_cast<mbgl::LatLng*>(instance);
}

inline mbgl::LatLng mbgl_lat_lng_to_cpp_copy(mbgl_lat_lng_t instance) {
  return *static_cast<mbgl::LatLng*>(instance);
}

mbgl_lat_lng_t mbgl_lat_lng_create_0(double lat_, double lon_, MBGL_LAT_LNG_WRAP_MODE mode) {
  return new mbgl::LatLng(lat_, lon_, mbgl_lat_lng_wrap_mode_to_cpp(mode));
}

mbgl_lat_lng_t mbgl_lat_lng_create_1(mbgl_canonical_tile_id_t id) {
  return new mbgl::LatLng(mbgl_canonical_tile_id_to_cpp_const_ref(id));
}

mbgl_lat_lng_t mbgl_lat_lng_create_2(mbgl_unwrapped_tile_id_t id) {
  return new mbgl::LatLng(mbgl_unwrapped_tile_id_to_cpp_const_ref(id));
}

void mbgl_lat_lng_destroy(mbgl_lat_lng_t instance) {
  delete static_cast<mbgl::LatLng*>(instance);
}

//--------------------------------------------------------------
// C-compatible opaque class implementation for mbgl::LatLngBounds
//--------------------------------------------------------------

inline mbgl_lat_lng_bounds_t mbgl_lat_lng_bounds_to_c(mbgl::LatLngBounds* instance) {
  return static_cast<mbgl_lat_lng_bounds_t>(instance);
}

inline const mbgl::LatLngBounds& mbgl_lat_lng_bounds_to_cpp_const_ref(mbgl_lat_lng_bounds_t instance) {
  return *static_cast<mbgl::LatLngBounds*>(instance);
}

inline mbgl::LatLngBounds mbgl_lat_lng_bounds_to_cpp_copy(mbgl_lat_lng_bounds_t instance) {
  return *static_cast<mbgl::LatLngBounds*>(instance);
}

mbgl_lat_lng_bounds_t mbgl_lat_lng_bounds_create_0() {
  return new mbgl::LatLngBounds();
}

mbgl_lat_lng_bounds_t mbgl_lat_lng_bounds_create_1(mbgl_canonical_tile_id_t canonical_tile_id) {
  return new mbgl::LatLngBounds(mbgl_canonical_tile_id_to_cpp_const_ref(canonical_tile_id));
}

void mbgl_lat_lng_bounds_destroy(mbgl_lat_lng_bounds_t instance) {
  delete static_cast<mbgl::LatLngBounds*>(instance);
}

//--------------------------------------------------------------
// C-compatible struct implementation for mbgl::util::UnitBezier
//--------------------------------------------------------------

MBGL_UTIL_UNIT_BEZIER* mbgl_util_unit_bezier_create() {
  return new MBGL_UTIL_UNIT_BEZIER();
}

void mbgl_util_unit_bezier_destroy(MBGL_UTIL_UNIT_BEZIER* instance) {
  delete instance;
}

MBGL_UTIL_UNIT_BEZIER mbgl_util_unit_bezier_to_c(const mbgl::util::UnitBezier& instance) {
  MBGL_UTIL_UNIT_BEZIER c_instance;
  c_instance.p1x = instance.p1x;
  c_instance.p1y = instance.p1y;
  c_instance.p2x = instance.p2x;
  c_instance.p2y = instance.p2y;
  return c_instance;
}

mbgl::util::UnitBezier mbgl_util_unit_bezier_to_cpp(const MBGL_UTIL_UNIT_BEZIER& instance) {
  mbgl::util::UnitBezier cpp_instance;
  cpp_instance.p1x = instance.p1x;
  cpp_instance.p1y = instance.p1y;
  cpp_instance.p2x = instance.p2x;
  cpp_instance.p2y = instance.p2y;
  return cpp_instance;
}

//--------------------------------------------------------------
// C-compatible struct implementation for mbgl::AnimationOptions
//--------------------------------------------------------------

MBGL_ANIMATION_OPTIONS* mbgl_animation_options_create() {
  return new MBGL_ANIMATION_OPTIONS();
}

void mbgl_animation_options_destroy(MBGL_ANIMATION_OPTIONS* instance) {
  delete instance;
}

MBGL_ANIMATION_OPTIONS mbgl_animation_options_to_c(const mbgl::AnimationOptions& instance) {
  MBGL_ANIMATION_OPTIONS c_instance;
  c_instance.has_duration = instance.duration.has_value();
  c_instance.duration = std::chrono::duration_cast<std::chrono::milliseconds>(instance.duration.value()).count();
  c_instance.has_velocity = instance.velocity.has_value();
  c_instance.velocity = instance.velocity.value();
  c_instance.has_min_zoom = instance.minZoom.has_value();
  c_instance.min_zoom = instance.minZoom.value();
  c_instance.has_easing = instance.easing.has_value();
  c_instance.easing = mbgl_util_unit_bezier_to_c(instance.easing.value());
  return c_instance;
}

mbgl::AnimationOptions mbgl_animation_options_to_cpp(const MBGL_ANIMATION_OPTIONS& instance) {
  mbgl::AnimationOptions cpp_instance;
  if (instance.has_duration) cpp_instance.duration.emplace(instance.duration);
  else cpp_instance.duration = std::nullopt;
  if (instance.has_velocity) cpp_instance.velocity.emplace(instance.velocity);
  else cpp_instance.velocity = std::nullopt;
  if (instance.has_min_zoom) cpp_instance.minZoom.emplace(instance.min_zoom);
  else cpp_instance.minZoom = std::nullopt;
  if (instance.has_easing) cpp_instance.easing.emplace(mbgl_util_unit_bezier_to_cpp(instance.easing));
  else cpp_instance.easing = std::nullopt;
  return cpp_instance;
}

//--------------------------------------------------------------
// C-compatible struct implementation for mbgl::BoundOptions
//--------------------------------------------------------------

MBGL_BOUND_OPTIONS* mbgl_bound_options_create() {
  return new MBGL_BOUND_OPTIONS();
}

void mbgl_bound_options_destroy(MBGL_BOUND_OPTIONS* instance) {
  delete instance;
}

MBGL_BOUND_OPTIONS mbgl_bound_options_to_c(const mbgl::BoundOptions& instance) {
  MBGL_BOUND_OPTIONS c_instance;
  c_instance.has_bounds = instance.bounds.has_value();
  c_instance.bounds = mbgl_lat_lng_bounds_to_c(instance.bounds.value());
  c_instance.has_max_zoom = instance.maxZoom.has_value();
  c_instance.max_zoom = instance.maxZoom.value();
  c_instance.has_min_zoom = instance.minZoom.has_value();
  c_instance.min_zoom = instance.minZoom.value();
  c_instance.has_max_pitch = instance.maxPitch.has_value();
  c_instance.max_pitch = instance.maxPitch.value();
  c_instance.has_min_pitch = instance.minPitch.has_value();
  c_instance.min_pitch = instance.minPitch.value();
  return c_instance;
}

mbgl::BoundOptions mbgl_bound_options_to_cpp(const MBGL_BOUND_OPTIONS& instance) {
  mbgl::BoundOptions cpp_instance;
  if (instance.has_bounds) cpp_instance.bounds.emplace(mbgl_lat_lng_bounds_to_cpp_const_ref(instance.bounds));
  else cpp_instance.bounds = std::nullopt;
  if (instance.has_max_zoom) cpp_instance.maxZoom.emplace(instance.max_zoom);
  else cpp_instance.maxZoom = std::nullopt;
  if (instance.has_min_zoom) cpp_instance.minZoom.emplace(instance.min_zoom);
  else cpp_instance.minZoom = std::nullopt;
  if (instance.has_max_pitch) cpp_instance.maxPitch.emplace(instance.max_pitch);
  else cpp_instance.maxPitch = std::nullopt;
  if (instance.has_min_pitch) cpp_instance.minPitch.emplace(instance.min_pitch);
  else cpp_instance.minPitch = std::nullopt;
  return cpp_instance;
}
