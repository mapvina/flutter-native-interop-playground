#include "default_style.h"

#include <mbgl/util/default_style.hpp>

mbgl_util_default_style_t mbgl_util_default_style_create(const char* url, const char* name, int currentVersion) {
  auto* defaultStyle = new mbgl::util::DefaultStyle(std::string(url), std::string(name), currentVersion);
  return reinterpret_cast<mbgl_util_default_style_t>(defaultStyle);
}

void mbgl_util_default_style_destroy(mbgl_util_default_style_t _defaultStyle) {
  auto* defaultStyle = reinterpret_cast<mbgl::util::DefaultStyle*>(_defaultStyle);
  delete defaultStyle;
}
