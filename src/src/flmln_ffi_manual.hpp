#pragma once

#include <mbgl/util/unitbezier.hpp>

#include "flmln_ffi_gen.h"

MBGL_UTIL_UNIT_BEZIER* mbgl_util_unit_bezier_create(double x1, double y1, double x2, double y2) {
  return new MBGL_UTIL_UNIT_BEZIER{x1, y1, x2, y2};
}

void mbgl_util_unit_bezier_destroy(MBGL_UTIL_UNIT_BEZIER* instance) { delete instance; }

mbgl::util::UnitBezier mbgl_util_unit_bezier_to_cpp(const MBGL_UTIL_UNIT_BEZIER& instance) {
  return mbgl::util::UnitBezier(instance.p1x, instance.p1y, instance.p2x, instance.p2y);
}

MBGL_UTIL_UNIT_BEZIER mbgl_util_unit_bezier_to_c(const mbgl::util::UnitBezier& instance) {
  auto [p1x, p1y] = instance.getP1();
  auto [p2x, p2y] = instance.getP2();
  return MBGL_UTIL_UNIT_BEZIER{p1x, p1y, p2x, p2y};
}
