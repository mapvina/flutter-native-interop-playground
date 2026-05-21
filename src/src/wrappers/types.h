#pragma once

#include "../flmln.h"
#include "stdint.h"

struct MBGL_SIZE {
  uint32_t width;
  uint32_t height;
};

struct MBGL_SCREEN_COORDINATE {
  double x;
  double y;
};

struct MBGL_LATLNG {
  double lat;
  double lng;
};

struct MBGL_EDGE_INSETS {
  double top;
  double left;
  double bottom;
  double right;
};

struct MBGL_UNIT_BEZIER {
  double p1x;
  double p1y;
  double p2x;
  double p2y;
};

struct ArrayVoidPtr {
  void** data;
  size_t length;
};
