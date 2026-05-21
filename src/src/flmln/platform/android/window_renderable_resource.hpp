#pragma once

#include <mbgl/gl/renderable_resource.hpp>

// forward declare
namespace flmln {
namespace android {
class RendererBackend;
}
}  // namespace flmln

namespace flmln {
namespace android {

class WindowRenderableResource : public mbgl::gl::RenderableResource {
 public:
  WindowRenderableResource(flmln::android::RendererBackend& backend_) : backend(backend_) {}
  ~WindowRenderableResource() noexcept override = default;

  void bind() override;
  void swap() override;

 private:
  flmln::android::RendererBackend& backend;
};
}  // namespace android
};  // namespace flmln