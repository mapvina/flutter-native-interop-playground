#include "renderer_backend.hpp"

#include "../../flutter_texture_interface.hpp"
#include "../../renderer_backend.hpp"

namespace flmln {
std::unique_ptr<flmln::RendererBackend> RendererBackend::create(
    std::shared_ptr<flmln::FlutterTextureInterface> textureInterface, mbgl::gfx::ContextMode contextMode) {
  return std::make_unique<flmln::android::RendererBackend>(textureInterface, contextMode);
}
}  // namespace flmln