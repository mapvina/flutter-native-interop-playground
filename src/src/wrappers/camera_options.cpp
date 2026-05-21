#include "camera_options.h"

#include <mbgl/map/camera.hpp>

#include "types.h"

mbgl_camera_options_t mbgl_camera_options_create() {
  auto* options = new mbgl::CameraOptions();
  return reinterpret_cast<mbgl_camera_options_t>(options);
}

void mbgl_camera_options_destroy(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  delete options;
}

bool mbgl_camera_options_anchor_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->anchor.has_value();
}

MBGL_SCREEN_COORDINATE mbgl_camera_options_anchor_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  MBGL_SCREEN_COORDINATE coord = {0, 0};
  if (options->anchor.has_value()) {
    coord.x = options->anchor->x;
    coord.y = options->anchor->y;
  }
  return coord;
}

void mbgl_camera_options_anchor_set(mbgl_camera_options_t _cameraOptions, struct MBGL_SCREEN_COORDINATE coord) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withAnchor(mbgl::ScreenCoordinate{coord.x, coord.y});
}

void mbgl_camera_options_anchor_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withAnchor(std::nullopt);
}

bool mbgl_camera_options_bearing_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->bearing.has_value();
}

double mbgl_camera_options_bearing_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  if (options->bearing.has_value()) {
    return *(options->bearing);
  }
  return 0.0;
}

void mbgl_camera_options_bearing_set(mbgl_camera_options_t _cameraOptions, double bearing) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withBearing(bearing);
}

void mbgl_camera_options_bearing_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withBearing(std::nullopt);
}

bool mbgl_camera_options_center_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->center.has_value();
}

MBGL_LATLNG mbgl_camera_options_center_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  MBGL_LATLNG latlng = {0, 0};
  if (options->center.has_value()) {
    latlng.lat = options->center->latitude();
    latlng.lng = options->center->longitude();
  }
  return latlng;
}

void mbgl_camera_options_center_set(mbgl_camera_options_t _cameraOptions, MBGL_LATLNG latlng) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withCenter(mbgl::LatLng{latlng.lat, latlng.lng});
}

void mbgl_camera_options_center_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withCenter(std::nullopt);
}

bool mbgl_camera_options_padding_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->padding.has_value();
}

MBGL_EDGE_INSETS mbgl_camera_options_padding_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  MBGL_EDGE_INSETS padding = {0, 0, 0, 0};
  if (options->padding.has_value()) {
    padding.top = options->padding->top();
    padding.left = options->padding->left();
    padding.bottom = options->padding->bottom();
    padding.right = options->padding->right();
  }
  return padding;
}

void mbgl_camera_options_padding_set(mbgl_camera_options_t _cameraOptions, struct MBGL_EDGE_INSETS padding) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withPadding(mbgl::EdgeInsets{padding.top, padding.left, padding.bottom, padding.right});
}

void mbgl_camera_options_padding_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withPadding(std::nullopt);
}

bool mbgl_camera_options_pitch_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->pitch.has_value();
}

double mbgl_camera_options_pitch_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  if (options->pitch.has_value()) {
    return *(options->pitch);
  }
  return 0.0;
}

void mbgl_camera_options_pitch_set(mbgl_camera_options_t _cameraOptions, double pitch) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withPitch(pitch);
}

void mbgl_camera_options_pitch_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withPitch(std::nullopt);
}

bool mbgl_camera_options_zoom_is_set(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  return options->zoom.has_value();
}

double mbgl_camera_options_zoom_get(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  if (options->zoom.has_value()) {
    return *(options->zoom);
  }
  return 0.0;
}

void mbgl_camera_options_zoom_set(mbgl_camera_options_t _cameraOptions, double zoom) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withZoom(zoom);
}

void mbgl_camera_options_zoom_clear(mbgl_camera_options_t _cameraOptions) {
  auto* options = reinterpret_cast<mbgl::CameraOptions*>(_cameraOptions);
  options->withZoom(std::nullopt);
}
