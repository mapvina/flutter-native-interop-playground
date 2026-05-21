#pragma once

#include "stdint.h"
#include "stdbool.h"

// C-compatible enum definition for mbgl::MapMode
typedef enum MBGL_MAP_MODE {
  MBGL_MAP_MODE_CONTINUOUS = 0,
  MBGL_MAP_MODE_STATIC = 1,
  MBGL_MAP_MODE_TILE = 2,
} MBGL_MAP_MODE;

// C-compatible enum definition for mbgl::ConstrainMode
typedef enum MBGL_CONSTRAIN_MODE {
  MBGL_CONSTRAIN_MODE_NONE = 0,
  MBGL_CONSTRAIN_MODE_HEIGHT_ONLY = 1,
  MBGL_CONSTRAIN_MODE_WIDTH_AND_HEIGHT = 2,
  MBGL_CONSTRAIN_MODE_SCREEN = 3,
} MBGL_CONSTRAIN_MODE;

// C-compatible enum definition for mbgl::ViewportMode
typedef enum MBGL_VIEWPORT_MODE {
  MBGL_VIEWPORT_MODE_DEFAULT = 0,
  MBGL_VIEWPORT_MODE_FLIPPED_Y = 1,
} MBGL_VIEWPORT_MODE;

// C-compatible enum definition for mbgl::MapDebugOptions
typedef enum MBGL_MAP_DEBUG_OPTIONS {
  MBGL_MAP_DEBUG_OPTIONS_NO_DEBUG = 0,
  MBGL_MAP_DEBUG_OPTIONS_TILE_BORDERS = 2,
  MBGL_MAP_DEBUG_OPTIONS_PARSE_STATUS = 4,
  MBGL_MAP_DEBUG_OPTIONS_TIMESTAMPS = 8,
  MBGL_MAP_DEBUG_OPTIONS_COLLISION = 16,
  MBGL_MAP_DEBUG_OPTIONS_OVERDRAW = 32,
  MBGL_MAP_DEBUG_OPTIONS_STENCIL_CLIP = 64,
  MBGL_MAP_DEBUG_OPTIONS_DEPTH_BUFFER = 128,
} MBGL_MAP_DEBUG_OPTIONS;

// C-compatible enum definition for mbgl::LatLng::WrapMode
typedef enum MBGL_LAT_LNG_WRAP_MODE {
  MBGL_LAT_LNG_WRAP_MODE_UNWRAPPED = 0,
  MBGL_LAT_LNG_WRAP_MODE_WRAPPED = -1,
} MBGL_LAT_LNG_WRAP_MODE;

// C-compatible enum definition for mbgl::NorthOrientation
typedef enum MBGL_NORTH_ORIENTATION {
  MBGL_NORTH_ORIENTATION_UPWARDS = 0,
  MBGL_NORTH_ORIENTATION_RIGHTWARDS = 1,
  MBGL_NORTH_ORIENTATION_DOWNWARDS = 2,
  MBGL_NORTH_ORIENTATION_LEFTWARDS = 3,
} MBGL_NORTH_ORIENTATION;

// C-compatible opaque class definition for mbgl::CanonicalTileID
typedef void* mbgl_canonical_tile_id_t;

void mbgl_canonical_tile_id_destroy(mbgl_canonical_tile_id_t instance);

// C-compatible opaque class definition for mbgl::UnwrappedTileID
typedef void* mbgl_unwrapped_tile_id_t;

void mbgl_unwrapped_tile_id_destroy(mbgl_unwrapped_tile_id_t instance);

// C-compatible opaque class definition for mbgl::OverscaledTileID
typedef void* mbgl_overscaled_tile_id_t;

mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_0(uint8_t overscaledZ, int16_t wrap, mbgl_canonical_tile_id_t canonical_tile_id);
mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_1(uint8_t overscaledZ, int16_t wrap, uint8_t z, uint32_t x, uint32_t y);
mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_2(uint8_t z, uint32_t x, uint32_t y);
mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_3(mbgl_canonical_tile_id_t canonical_tile_id);
mbgl_overscaled_tile_id_t mbgl_overscaled_tile_id_create_4(mbgl_canonical_tile_id_t canonical_tile_id);
void mbgl_overscaled_tile_id_destroy(mbgl_overscaled_tile_id_t instance);

// C-compatible opaque class definition for mbgl::LatLng
typedef void* mbgl_lat_lng_t;

mbgl_lat_lng_t mbgl_lat_lng_create_0(double lat_, double lon_, MBGL_LAT_LNG_WRAP_MODE mode);
mbgl_lat_lng_t mbgl_lat_lng_create_1(mbgl_canonical_tile_id_t id);
mbgl_lat_lng_t mbgl_lat_lng_create_2(mbgl_unwrapped_tile_id_t id);
void mbgl_lat_lng_destroy(mbgl_lat_lng_t instance);

// C-compatible opaque class definition for mbgl::LatLngBounds
typedef void* mbgl_lat_lng_bounds_t;

mbgl_lat_lng_bounds_t mbgl_lat_lng_bounds_create_0();
mbgl_lat_lng_bounds_t mbgl_lat_lng_bounds_create_1(mbgl_canonical_tile_id_t canonical_tile_id);
void mbgl_lat_lng_bounds_destroy(mbgl_lat_lng_bounds_t instance);

// C-compatible struct definition for mbgl::util::UnitBezier
typedef struct MBGL_UTIL_UNIT_BEZIER {
  double p1x;
  double p1y;
  double p2x;
  double p2y;
} MBGL_UTIL_UNIT_BEZIER;

MBGL_UTIL_UNIT_BEZIER* mbgl_util_unit_bezier_create();
void mbgl_util_unit_bezier_destroy(MBGL_UTIL_UNIT_BEZIER* instance);

// C-compatible struct definition for mbgl::AnimationOptions
typedef struct MBGL_ANIMATION_OPTIONS {
  bool has_duration;
  MBGL_DURATION duration;
  bool has_velocity;
  double velocity;
  bool has_min_zoom;
  double min_zoom;
  bool has_easing;
  MBGL_UTIL_UNIT_BEZIER easing;
} MBGL_ANIMATION_OPTIONS;

MBGL_ANIMATION_OPTIONS* mbgl_animation_options_create();
void mbgl_animation_options_destroy(MBGL_ANIMATION_OPTIONS* instance);

// C-compatible struct definition for mbgl::BoundOptions
typedef struct MBGL_BOUND_OPTIONS {
  bool has_bounds;
  mbgl_lat_lng_bounds_t bounds;
  bool has_max_zoom;
  double max_zoom;
  bool has_min_zoom;
  double min_zoom;
  bool has_max_pitch;
  double max_pitch;
  bool has_min_pitch;
  double min_pitch;
} MBGL_BOUND_OPTIONS;

MBGL_BOUND_OPTIONS* mbgl_bound_options_create();
void mbgl_bound_options_destroy(MBGL_BOUND_OPTIONS* instance);
