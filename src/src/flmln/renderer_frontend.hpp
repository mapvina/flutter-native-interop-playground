#pragma once

#include <mbgl/gfx/backend_scope.hpp>
#include <mbgl/gfx/renderable.hpp>
#include <mbgl/map/map.hpp>
#include <mbgl/renderer/renderer.hpp>
#include <mbgl/renderer/renderer_frontend.hpp>

#include "flutter_texture_interface.hpp"
#include "renderer_backend.hpp"

namespace flmln {
class RendererFrontend : public mbgl::RendererFrontend {
 public:
  RendererFrontend(const std::optional<std::string>& localFontFamily) : size({0, 0}), pixelRatio(0.0f) {
    textureInterface = flmln::FlutterTextureInterface::Create();
    backend = flmln::RendererBackend::create(textureInterface, mbgl::gfx::ContextMode::Unique);
    renderer = std::make_unique<mbgl::Renderer>(*getBackend(), 2.0f, localFontFamily);
  }

  // Return the RendererBackend for this frontend.
  mbgl::gfx::RendererBackend* getBackend() { return backend->getRendererBackend(); }

  // Set the size and pixel ratio for the backend. If the same values are passed, does nothing.
  void setSizeAndPixelRatio(mbgl::Size size, float pixelRatio) {
    if (this->size != size || this->pixelRatio != pixelRatio) {
      this->size = size;
      this->pixelRatio = pixelRatio;
      auto scaledSize = mbgl::Size{
          static_cast<uint32_t>(size.width * pixelRatio),
          static_cast<uint32_t>(size.height * pixelRatio),
      };

      backend->setSize(scaledSize);
    }
  }

  // Render a frame using the current update parameters.
  void renderFrame() {
    if (renderer && updateParameters) {
      mbgl::gfx::BackendScope guard{*getBackend()};

      auto updateParameters_ = updateParameters;
      renderer->render(updateParameters_);
      textureInterface->update(*backend);
      renderScheduled = false;
    }
  }

  void reset() override {
    assert(renderer);
    renderer.reset();
  }

  void update(std::shared_ptr<mbgl::UpdateParameters> updateParameters_) override {
    updateParameters = std::move(updateParameters_);
    if (invalidateCallback) {
      if (renderScheduled) return;
      renderScheduled = true;
      invalidateCallback();
    }
  }

  const mbgl::TaggedScheduler& getThreadPool() const override { return backend->getRendererBackend()->getThreadPool(); }

  void setObserver(mbgl::RendererObserver& observer_) override {
    assert(renderer);
    renderer->setObserver(&observer_);
  }

  int64_t getTextureId() const { return textureInterface->getTextureId(); }

  void setInvalidateCallback(std::function<void()> callback) { invalidateCallback = std::move(callback); }

  void reduceMemoryUse() {
    assert(renderer);
    renderer->reduceMemoryUse();
  }

  void setTileCacheEnabled(bool enabled) {
    assert(renderer);
    renderer->setTileCacheEnabled(enabled);
  }

  bool getTileCacheEnabled() const {
    assert(renderer);
    return renderer->getTileCacheEnabled();
  }

 private:
  mbgl::Size size;
  float pixelRatio;
  std::shared_ptr<flmln::FlutterTextureInterface> textureInterface;
  std::unique_ptr<flmln::RendererBackend> backend;
  std::unique_ptr<mbgl::Renderer> renderer;
  std::shared_ptr<mbgl::UpdateParameters> updateParameters;
  std::function<void()> invalidateCallback;
  bool renderScheduled = false;
};
}  // namespace flmln
