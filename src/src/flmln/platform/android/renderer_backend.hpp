#pragma once

#include <EGL/egl.h>
#include <android/native_window.h>

#include <mbgl/gl/context.hpp>
#include <mbgl/gl/renderable_resource.hpp>
#include <mbgl/util/logging.hpp>
#include <mbgl/util/string.hpp>

#include "../../flutter_texture_interface.hpp"
#include "../../gl/renderer_backend_egl.hpp"
#include "../../renderer_backend.hpp"
#include "flutter_texture_interface.hpp"
#include "window_renderable_resource.hpp"

namespace flmln {
namespace android {
class RendererBackend : public flmln::gl::RendererBackend {
 public:
  RendererBackend(std::shared_ptr<flmln::FlutterTextureInterface> textureInterface, mbgl::gfx::ContextMode contextMode)
      : flmln::gl::RendererBackend(contextMode) {
    this->textureInterface = std::dynamic_pointer_cast<flmln::android::FlutterTextureInterface>(textureInterface);
    if (this->textureInterface) {
      window = this->textureInterface->getNativeWindow();

      if (window) {
        ANativeWindow_acquire(window);
        createWindowSurface();
      }
    }
  }

  ~RendererBackend() noexcept override {
    destroyWindowSurface();
    if (window) {
      ANativeWindow_release(window);
      window = nullptr;
    }
  }

  void activate() override {
    if (windowSurface != EGL_NO_SURFACE) {
      if (!eglMakeCurrent(eglDisplayHandle(), windowSurface, windowSurface, eglContextHandle())) {
        throw std::runtime_error("eglMakeCurrent(window) failed");
      }
    } else {
      flmln::gl::RendererBackend::activate();
    }
  }

  void setSize(mbgl::Size size_) override {
    flmln::gl::RendererBackend::setSize(size_);
    textureInterface->setSize(size_.width, size_.height);
  }

  mbgl::gfx::Renderable& getDefaultRenderable() override {
    if (!resource) {
      if (windowSurface != EGL_NO_SURFACE) {
        resource = std::make_unique<WindowRenderableResource>(*this);
      } else {
        flmln::gl::RendererBackend::getDefaultRenderable();
      }
    }

    return *this;
  }

 private:
  void createWindowSurface() {
    if (!window || windowSurface != EGL_NO_SURFACE) return;

    windowSurface = eglCreateWindowSurface(eglDisplayHandle(), eglConfigHandle(), window, nullptr);
    if (windowSurface == EGL_NO_SURFACE) {
      throw std::runtime_error("Could not create EGL window surface: " + mbgl::util::toString(eglGetError()));
    }

    resource.reset();
  }

  void destroyWindowSurface() {
    if (windowSurface != EGL_NO_SURFACE) {
      eglDestroySurface(eglDisplayHandle(), windowSurface);
      windowSurface = EGL_NO_SURFACE;
    }
  }

  std::shared_ptr<flmln::android::FlutterTextureInterface> textureInterface;
  ANativeWindow* window = nullptr;
  EGLSurface windowSurface = EGL_NO_SURFACE;

  friend class flmln::android::WindowRenderableResource;
};
}  // namespace android
}  // namespace flmln