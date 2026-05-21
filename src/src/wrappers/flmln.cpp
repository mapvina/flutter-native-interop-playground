#include "flmln.h"

#include "../flmln.h"
#include "../flmln/map_observer.hpp"
#include "../flmln/renderer_frontend.hpp"

flmln_map_observer_t flmln_map_observer_create() {
  return reinterpret_cast<flmln_map_observer_t>(new flmln::MapObserver());
}

void flmln_map_observer_destroy(flmln_map_observer_t _mapObserver) {
  delete reinterpret_cast<flmln::MapObserver*>(_mapObserver);
}

flmln_renderer_frontend_t flmln_renderer_frontend_create() {
  return reinterpret_cast<flmln_renderer_frontend_t>(new flmln::RendererFrontend(std::nullopt));
}

void flmln_renderer_frontend_destroy(flmln_renderer_frontend_t _rendererFrontend) {
  delete reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
}

void flmln_renderer_frontend_render(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->renderFrame();
}

void flmln_renderer_frontend_set_size_and_pixel_ratio(flmln_renderer_frontend_t _rendererFrontend, MBGL_SIZE size,
                                                      float pixelRatio) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setSizeAndPixelRatio({size.width, size.height}, pixelRatio);
}

int64_t flmln_renderer_frontend_get_texture_id(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  return rendererFrontend->getTextureId();
}

void flmln_renderer_frontend_set_invalidate_callback(flmln_renderer_frontend_t _rendererFrontend, void (*callback)()) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setInvalidateCallback([callback]() { callback(); });
}

void flmln_renderer_frontend_reduce_memory_use(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->reduceMemoryUse();
}

void flmln_renderer_frontend_set_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend, bool enabled) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  rendererFrontend->setTileCacheEnabled(enabled);
}

bool flmln_renderer_frontend_get_tile_cache_enabled(flmln_renderer_frontend_t _rendererFrontend) {
  auto* rendererFrontend = reinterpret_cast<flmln::RendererFrontend*>(_rendererFrontend);
  return rendererFrontend->getTileCacheEnabled();
}
