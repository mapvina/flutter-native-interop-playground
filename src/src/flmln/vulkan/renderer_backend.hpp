#pragma once

#include <mbgl/gfx/backend_scope.hpp>
#include <mbgl/util/util.hpp>
#include <mbgl/vulkan/context.hpp>
#include <mbgl/vulkan/renderable_resource.hpp>
#include <mbgl/vulkan/renderer_backend.hpp>
#include <mbgl/vulkan/texture2d.hpp>

#include "../renderer_backend.hpp"

namespace flmln {
namespace vulkan {

class RenderableResource : public mbgl::vulkan::SurfaceRenderableResource {
 public:
  RenderableResource(flmln::vulkan::RendererBackend backend, mbgl::vulkan::Context& context_, mbgl::Size size)
      : context(context_), mbgl::vulkan::SurfaceRenderableResource(backend) {
    offscreenTexture = context.createOffscreenTexture(size, mbgl::gfx::TextureChannelDataType::UnsignedByte);
  }

  ~RenderableResource() noexcept override = default;

  // -- Overrides --
  void bind() override { offscreenTexture->getResource<mbgl::vulkan::RenderableResource>().bind(); }
  void swap() override { offscreenTexture->getResource<mbgl::vulkan::RenderableResource>().swap(); }
  const vk::UniqueFramebuffer& getFramebuffer() const override {
    return offscreenTexture->getResource<mbgl::vulkan::RenderableResource>().getFramebuffer();
  }

  // -- New methods --
  mbgl::gfx::Texture2DPtr getTexture() const { return offscreenTexture->getTexture(); }
  mbgl::PremultipliedImage readStillImage() { return offscreenTexture->readStillImage(); }

 private:
  mbgl::vulkan::Context& context;
  std::unique_ptr<mbgl::gfx::OffscreenTexture> offscreenTexture;
};

class RendererBackend : public flmln::RendererBackend, public mbgl::vulkan::RendererBackend {
  RendererBackend(mbgl::gfx::ContextMode contextMode)
      : flmln::RendererBackend(), mbgl::vulkan::RendererBackend(contextMode) {}

  ~RendererBackend() noexcept override {
    mbgl::gfx::BackendScope guard{*this, mbgl::gfx::BackendScope::ScopeType::Implicit};
    context.reset();
    resource.reset();
  }

  mbgl::gfx::RendererBackend* getRendererBackend() override { return this; }
  mbgl::gfx::Renderable& getDefaultRenderable() override {
    if (!resource) {
      resource = std::make_unique<RenderableResource>(this, static_cast<mbgl::vulkan::Context&>(getContext()), size);
    }

    return *this;
  }

  mbgl::gfx::Texture2DPtr getTexture() const override {
    if (resource) {
      auto renderableResource = static_cast<RenderableResource*>(resource.get());
      if (renderableResource) return renderableResource->getTexture();
    }

    return nullptr;
  }

  mbgl::PremultipliedImage readStillImage() override {
    if (resource) {
      auto renderableResource = static_cast<RenderableResource*>(resource.get());
      if (renderableResource) return renderableResource->readStillImage();
    }

    return mbgl::PremultipliedImage{};
  }

  void activate() override { active = true; }
  void deactivate() override { active = false; }

 private:
  bool active = false;
};
}  // namespace vulkan
}  // namespace flmln