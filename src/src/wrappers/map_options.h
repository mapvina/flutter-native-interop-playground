#pragma once

#include "../flmln.h"
#include "enums.h"
#include "types.h"

typedef void* mbgl_map_options_t;

FFI mbgl_map_options_t mbgl_map_options_create();
FFI void mbgl_map_options_destroy(mbgl_map_options_t _mapOptions);

FFI enum MBGL_CONSTRAIN_MODE mbgl_map_options_constrain_mode_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_constrain_mode_set(mbgl_map_options_t _mapOptions, enum MBGL_CONSTRAIN_MODE mode);

FFI bool mbgl_map_options_cross_source_collisions_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_cross_source_collisions_set(mbgl_map_options_t _mapOptions, bool enabled);

FFI enum MBGL_MAP_MODE mbgl_map_options_map_mode_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_map_mode_set(mbgl_map_options_t _mapOptions, enum MBGL_MAP_MODE mode);

FFI enum MBGL_NORTH_ORIENTATION mbgl_map_options_north_orientation_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_north_orientation_set(mbgl_map_options_t _mapOptions,
                                                enum MBGL_NORTH_ORIENTATION orientation);

FFI float mbgl_map_options_pixel_ratio_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_pixel_ratio_set(mbgl_map_options_t _mapOptions, float pixelRatio);

FFI struct MBGL_SIZE mbgl_map_options_size_get(mbgl_map_options_t _mapOptions);
FFI void mbgl_map_options_size_set(mbgl_map_options_t _mapOptions, struct MBGL_SIZE size);
