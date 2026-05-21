#include "animation_options.h"

#include <mbgl/map/camera.hpp>
#include <mbgl/util/unitbezier.hpp>

#include "types.h"

mbgl_animation_options_t mbgl_animation_options_create() {
  auto* options = new mbgl::AnimationOptions();
  return reinterpret_cast<mbgl_animation_options_t>(options);
}

void mbgl_animation_options_destroy(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  delete options;
}

bool mbgl_animation_options_duration_is_set(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  return options->duration.has_value();
}

int64_t mbgl_animation_options_duration_get(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  if (options->duration.has_value()) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(*(options->duration)).count();
  }
  return -1;
}

void mbgl_animation_options_duration_set(mbgl_animation_options_t _animationOptions, int64_t durationMs) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->duration = std::chrono::milliseconds(durationMs);
}

void mbgl_animation_options_duration_clear(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->duration = std::nullopt;
}

bool mbgl_animation_options_easing_is_set(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  return options->easing.has_value();
}

MBGL_UNIT_BEZIER mbgl_animation_options_easing_get(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  MBGL_UNIT_BEZIER bezier = {0, 0, 0, 0};
  if (options->easing.has_value()) {
    const mbgl::util::UnitBezier& ub = *(options->easing);
    auto [p1x, p1y] = ub.getP1();
    auto [p2x, p2y] = ub.getP2();
    bezier.p1x = p1x;
    bezier.p1y = p1y;
    bezier.p2x = p2x;
    bezier.p2y = p2y;
  }
  return bezier;
}

void mbgl_animation_options_easing_set(mbgl_animation_options_t _animationOptions, struct MBGL_UNIT_BEZIER bezier) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->easing.emplace(bezier.p1x, bezier.p1y, bezier.p2x, bezier.p2y);
}

void mbgl_animation_options_easing_clear(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->easing = std::nullopt;
}

bool mbgl_animation_options_min_zoom_is_set(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  return options->minZoom.has_value();
}

double mbgl_animation_options_min_zoom_get(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  if (options->minZoom.has_value()) {
    return *(options->minZoom);
  }
  return -1.0;
}

void mbgl_animation_options_min_zoom_set(mbgl_animation_options_t _animationOptions, double minZoom) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->minZoom = minZoom;
}

void mbgl_animation_options_min_zoom_clear(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->minZoom = std::nullopt;
}

bool mbgl_animation_options_velocity_is_set(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  return options->velocity.has_value();
}

double mbgl_animation_options_velocity_get(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  if (options->velocity.has_value()) {
    return *(options->velocity);
  }
  return -1.0;
}

void mbgl_animation_options_velocity_set(mbgl_animation_options_t _animationOptions, double velocity) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->velocity = velocity;
}

void mbgl_animation_options_velocity_clear(mbgl_animation_options_t _animationOptions) {
  auto* options = reinterpret_cast<mbgl::AnimationOptions*>(_animationOptions);
  options->velocity = std::nullopt;
}
