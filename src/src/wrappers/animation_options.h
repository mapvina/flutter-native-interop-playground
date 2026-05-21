#pragma once

#include "../flmln.h"
#include "types.h"

typedef void* mbgl_animation_options_t;

struct MBGL_ANIMATION_OPTIONS {
  bool has_duration;
  int64_t duration;

  bool has_easing;
  struct MBGL_UNIT_BEZIER easing;

  bool has_min_zoom;
  double min_zoom;

  bool has_velocity;
  double velocity;
};

FFI mbgl_animation_options_t mbgl_animation_options_create();
FFI void mbgl_animation_options_destroy(mbgl_animation_options_t _animationOptions);

FFI bool mbgl_animation_options_duration_is_set(mbgl_animation_options_t _animationOptions);
FFI int64_t mbgl_animation_options_duration_get(mbgl_animation_options_t _animationOptions);
FFI void mbgl_animation_options_duration_set(mbgl_animation_options_t _animationOptions, uint64_t duration);
FFI void mbgl_animation_options_duration_clear(mbgl_animation_options_t _animationOptions);

FFI bool mbgl_animation_options_easing_is_set(mbgl_animation_options_t _animationOptions);
FFI struct MBGL_UNIT_BEZIER mbgl_animation_options_easing_get(mbgl_animation_options_t _animationOptions);
FFI void mbgl_animation_options_easing_set(mbgl_animation_options_t _animationOptions, struct MBGL_UNIT_BEZIER bezier);
FFI void mbgl_animation_options_easing_clear(mbgl_animation_options_t _animationOptions);

FFI bool mbgl_animation_options_min_zoom_is_set(mbgl_animation_options_t _animationOptions);
FFI double mbgl_animation_options_min_zoom_get(mbgl_animation_options_t _animationOptions);
FFI void mbgl_animation_options_min_zoom_set(mbgl_animation_options_t _animationOptions, double minZoom);
FFI void mbgl_animation_options_min_zoom_clear(mbgl_animation_options_t _animationOptions);

FFI bool mbgl_animation_options_velocity_is_set(mbgl_animation_options_t _animationOptions);
FFI double mbgl_animation_options_velocity_get(mbgl_animation_options_t _animationOptions);
FFI void mbgl_animation_options_velocity_set(mbgl_animation_options_t _animationOptions, double velocity);
FFI void mbgl_animation_options_velocity_clear(mbgl_animation_options_t _animationOptions);
