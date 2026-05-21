#pragma once

#include <mbgl/gfx/offscreen_texture.hpp>
#include <mbgl/gfx/renderable.hpp>
#include <mbgl/gfx/renderer_backend.hpp>
#include <mbgl/util/size.hpp>

#include "flutter_texture_interface.hpp"

namespace flmln {
class FlutterTextureInterface;

class RendererBackend : public mbgl::gfx::Renderable {
 public:
  RendererBackend() : mbgl::gfx::Renderable({0, 0}, nullptr) {}
  virtual ~RendererBackend() = default;

  static std::unique_ptr<RendererBackend> create(std::shared_ptr<flmln::FlutterTextureInterface> textureInterface,
                                                 mbgl::gfx::ContextMode contextMode);

  virtual mbgl::gfx::RendererBackend* getRendererBackend() = 0;
  virtual mbgl::gfx::Texture2DPtr getTexture() const = 0;
  virtual mbgl::PremultipliedImage readStillImage() = 0;

  virtual void setSize(mbgl::Size size_) {
    size = size_;
    resource.reset();
  }
};
}  // namespace flmln