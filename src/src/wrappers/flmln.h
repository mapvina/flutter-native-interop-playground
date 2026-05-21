#pragma once

#include "../flmln.h"
#include "types.h"

typedef void* flmln_map_observer_t;

FFI flmln_map_observer_t flmln_map_observer_create();
FFI void flmln_map_observer_destroy(flmln_map_observer_t _mapObserver);

typedef void* flmln_renderer_frontend_t;

FFI flmln_renderer_frontend_t flmln_renderer_frontend_create();
FFI void flmln_renderer_frontend_destroy(flmln_renderer_frontend_t _rendererFrontend);

FFI void flmln_renderer_frontend_render(flmln_renderer_frontend_t _rendererFrontend);
FFI void flmln_renderer_frontend_set_size_and_pixel_ratio(flmln_renderer_frontend_t _rendererFrontend, MBGL_SIZE size,
                                                          float pixelRatio);
FFI int64_t flmln_renderer_frontend_get_texture_id(flmln_renderer_frontend_t _rendererFrontend);
FFI void flmln_renderer_frontend_set_invalidate_callback(flmln_renderer_frontend_t _rendererFrontend,
                                                         void (*invalidateCallback)(void));
FFI void flmln_renderer_frontend_reduce_memory_use(flmln_renderer_frontend_t _rendererFrontend);
FFI void flmln_renderer_frontend_set_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend, bool enabled);
FFI bool flmln_renderer_frontend_get_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend);
