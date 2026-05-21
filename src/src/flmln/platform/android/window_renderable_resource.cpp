#include "window_renderable_resource.hpp"

#include "renderer_backend.hpp"

namespace flmln {
namespace android {
void WindowRenderableResource::bind() {
  backend.setFramebufferBinding(0);
  backend.setViewport(0, 0, backend.getSize());
}

void WindowRenderableResource::swap() { eglSwapBuffers(backend.eglDisplayHandle(), backend.windowSurface); }
}  // namespace android
}  // namespace flmln