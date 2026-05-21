#pragma once

#include "../flmln.h"

typedef void* mbgl_util_default_style_t;

FFI mbgl_util_default_style_t mbgl_util_default_style_create(const char* url, const char* name, int currentVersion);
FFI void mbgl_util_default_style_destroy(mbgl_util_default_style_t _defaultStyle);
