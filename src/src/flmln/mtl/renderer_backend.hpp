#pragma once

#include <Metal/Metal.hpp>
#include <mbgl/gfx/backend_scope.hpp>
#include <mbgl/gfx/offscreen_texture.hpp>
#include <mbgl/gfx/renderable.hpp>
#include <mbgl/mtl/context.hpp>
#include <mbgl/mtl/renderable_resource.hpp>
#include <mbgl/mtl/renderer_backend.hpp>
#include <mbgl/mtl/texture2d.hpp>

#include "../renderer_backend.hpp"

namespace flmln {
namespace mtl {

class RenderableResource : public mbgl::mtl::RenderableResource {
 public:
  RenderableResource(mbgl::mtl::Context& context_, mbgl::Size size) : context(context_) {
    offscreenTexture =
        context.createOffscreenTexture(size, mbgl::gfx::TextureChannelDataType::UnsignedByte, true, true);
  }

  // -- Overrides --

  ~RenderableResource() noexcept override = default;

  void bind() override { offscreenTexture->getResource<mbgl::mtl::RenderableResource>().bind(); }
  void swap() override { offscreenTexture->getResource<mbgl::mtl::RenderableResource>().swap(); }

  const mbgl::mtl::RendererBackend& getBackend() const override { return context.getBackend(); }

  const mbgl::mtl::MTLCommandBufferPtr& getCommandBuffer() const override {
    return offscreenTexture->getResource<mbgl::mtl::RenderableResource>().getCommandBuffer();
  }

  mbgl::mtl::MTLBlitPassDescriptorPtr getUploadPassDescriptor() const override {
    return offscreenTexture->getResource<mbgl::mtl::RenderableResource>().getUploadPassDescriptor();
  }

  const mbgl::mtl::MTLRenderPassDescriptorPtr& getRenderPassDescriptor() const override {
    return offscreenTexture->getResource<mbgl::mtl::RenderableResource>().getRenderPassDescriptor();
  }

  // -- New methods --
  mbgl::gfx::Texture2DPtr getTexture() const { return offscreenTexture->getTexture(); }
  mbgl::PremultipliedImage readStillImage() { return offscreenTexture->readStillImage(); }

 private:
  mbgl::mtl::Context& context;
  std::unique_ptr<mbgl::gfx::OffscreenTexture> offscreenTexture;
};

class RendererBackend : public flmln::RendererBackend, public mbgl::mtl::RendererBackend {
 public:
  RendererBackend(mbgl::gfx::ContextMode contextMode)
      : flmln::RendererBackend(), mbgl::mtl::RendererBackend(contextMode) {}

  ~RendererBackend() override {
    mbgl::gfx::BackendScope guard{*this, mbgl::gfx::BackendScope::ScopeType::Implicit};
    context.reset();
    resource.reset();
  }

  mbgl::gfx::RendererBackend* getRendererBackend() override { return this; }

  mbgl::gfx::Renderable& getDefaultRenderable() override {
    if (!resource) {
      resource = std::make_unique<RenderableResource>(static_cast<mbgl::mtl::Context&>(getContext()), size);
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

  MTL::Texture* getMTLTexture() const {
    auto texturePtr = getTexture();
    if (!texturePtr) return nullptr;

    auto mtlTexture = static_cast<mbgl::mtl::Texture2D*>(texturePtr.get());
    if (!mtlTexture) return nullptr;

    return mtlTexture->getMetalTexture();
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
  void updateAssumedState() override {}

 private:
  bool active = false;
};
}  // namespace mtl
}  // namespace flmln