#pragma once

#include "../flmln.h"
#include "flmln.h"
#include "map_options.h"
#include "resource_options.h"

typedef void* mbgl_map_t;

FFI mbgl_map_t mbgl_map_create(flmln_renderer_frontend_t _rendererFrontend, flmln_map_observer_t _mapObserver,
                               mbgl_map_options_t _mapOptions, mbgl_resource_options_t _resourceOptions);

FFI void mbgl_map_destroy(mbgl_map_t _map);