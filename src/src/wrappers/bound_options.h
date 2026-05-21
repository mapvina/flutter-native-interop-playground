#pragma once

#include "../flmln.h"
#include "types.h"

typedef void* mbgl_bound_options_t;

FFI mbgl_bound_options_t mbgl_bound_options_create();
FFI void mbgl_bound_options_destroy(mbgl_bound_options_t _boundOptions);