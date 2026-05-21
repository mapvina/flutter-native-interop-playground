#pragma once

#include <EGL/egl.h>

#include <mbgl/gfx/backend_scope.hpp>
#include <mbgl/gl/context.hpp>
#include <mbgl/gl/renderable_resource.hpp>
#include <mbgl/gl/renderer_backend.hpp>
#include <mbgl/gl/texture2d.hpp>
#include <mbgl/util/logging.hpp>
#include <mbgl/util/string.hpp>
#include <mbgl/util/util.hpp>

#include "../renderer_backend.hpp"

namespace flmln {
namespace gl {

// Copy from mapvina-native/platform/linux/src/headless_backend_egl.cpp
class EGLDisplayConfig {
 private:
  // Key for singleton construction.
  struct Key {
    explicit Key() = default;
  };

 public:
  EGLDisplayConfig(Key) {
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
      throw std::runtime_error("Failed to obtain a valid EGL display.\n");
    }

    EGLint major, minor, numConfigs;
    if (!eglInitialize(display, &major, &minor)) {
      throw std::runtime_error("eglInitialize() failed.\n");
    }

    if (!eglBindAPI(EGL_OPENGL_ES_API)) {
      mbgl::Log::Error(mbgl::Event::OpenGL,
                       "eglBindAPI(EGL_OPENGL_ES_API) returned error " + std::to_string(eglGetError()));
      throw std::runtime_error("eglBindAPI() failed");
    }

    const EGLint attribs[] = {EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE,
                              EGL_PBUFFER_BIT | EGL_WINDOW_BIT, EGL_NONE};

    // Note: we're choosing an arbitrary pixel format, since we're not using
    // the default surface anyway; all rendering will be directed to
    // framebuffers which have their own configuration.
    if (!eglChooseConfig(display, attribs, &config, 1, &numConfigs) || numConfigs != 1) {
      throw std::runtime_error("Failed to choose ARGB config.\n");
    }
  }

  ~EGLDisplayConfig() { eglTerminate(display); }

  static std::shared_ptr<const EGLDisplayConfig> create() {
    static std::weak_ptr<const EGLDisplayConfig> instance;
    auto shared = instance.lock();
    if (!shared) {
      instance = shared = std::make_shared<EGLDisplayConfig>(Key{});
    }
    return shared;
  }

 public:
  EGLDisplay display = EGL_NO_DISPLAY;
  EGLConfig config = 0;
};

class RenderableResource : public mbgl::gl::RenderableResource {
 public:
  RenderableResource(mbgl::gl::Context& context_, mbgl::Size size) : context(context_) {
    offscreenTexture = context.createOffscreenTexture(size, mbgl::gfx::TextureChannelDataType::UnsignedByte);
  }

  ~RenderableResource() noexcept override = default;

  // -- Overrides --
  void bind() override { offscreenTexture->getResource<mbgl::gl::RenderableResource>().bind(); }
  void swap() override { offscreenTexture->getResource<mbgl::gl::RenderableResource>().swap(); }

  // -- New methods --
  mbgl::gfx::Texture2DPtr getTexture() const { return offscreenTexture->getTexture(); }
  mbgl::PremultipliedImage readStillImage() { return offscreenTexture->readStillImage(); }

 private:
  mbgl::gl::Context& context;
  std::unique_ptr<mbgl::gfx::OffscreenTexture> offscreenTexture;
};

class RendererBackend : public flmln::RendererBackend, public mbgl::gl::RendererBackend {
 public:
  RendererBackend(mbgl::gfx::ContextMode contextMode)
      : flmln::RendererBackend(), mbgl::gl::RendererBackend(contextMode) {
    const EGLint attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    eglContext = eglCreateContext(eglDisplay->display, eglDisplay->config, EGL_NO_CONTEXT, attribs);
    if (eglContext == EGL_NO_CONTEXT) {
      std::ostringstream logMsg;
      logMsg << "eglCreateContext() returned error 0x" << std::hex << eglGetError();
      mbgl::Log::Error(mbgl::Event::OpenGL, logMsg.str());

      throw std::runtime_error("Error creating the EGL context object.\n");
    }

    const EGLint surfAttribs[] = {EGL_WIDTH, 8, EGL_HEIGHT, 8, EGL_LARGEST_PBUFFER, EGL_TRUE, EGL_NONE};
    eglSurface = eglCreatePbufferSurface(eglDisplay->display, eglDisplay->config, surfAttribs);
    if (eglSurface == EGL_NO_SURFACE) {
      throw std::runtime_error("Could not create surface: " + mbgl::util::toString(eglGetError()));
    }
  }

  ~RendererBackend() noexcept override {
    mbgl::gfx::BackendScope guard{*this, mbgl::gfx::BackendScope::ScopeType::Implicit};
    context.reset();
    resource.reset();

    if (eglSurface != EGL_NO_SURFACE) {
      if (!eglDestroySurface(eglDisplay->display, eglSurface)) {
        mbgl::Log::Error(mbgl::Event::OpenGL, "Failed to destroy EGL surface.");
      }
      eglSurface = EGL_NO_SURFACE;
    }
    if (!eglDestroyContext(eglDisplay->display, eglContext)) {
      mbgl::Log::Error(mbgl::Event::OpenGL, "Failed to destroy EGL context.");
    }
  }

  mbgl::gl::ProcAddress getExtensionFunctionPointer(const char* name) override { return eglGetProcAddress(name); }

  mbgl::gfx::RendererBackend* getRendererBackend() override { return this; }
  mbgl::gfx::Renderable& getDefaultRenderable() override {
    if (!resource) {
      resource = std::make_unique<RenderableResource>(static_cast<mbgl::gl::Context&>(getContext()), size);
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

  mbgl::platform::GLuint getGLTextureID() const {
    auto texturePtr = getTexture();
    if (!texturePtr) return 0;

    auto glTexture = static_cast<mbgl::gl::Texture2D*>(texturePtr.get());
    if (!glTexture) return 0;

    return glTexture->getTextureID();
  }

  mbgl::PremultipliedImage readStillImage() override {
    if (resource) {
      auto renderableResource = static_cast<RenderableResource*>(resource.get());
      if (renderableResource) return renderableResource->readStillImage();
    }

    return mbgl::PremultipliedImage{};
  }

  void activate() override {
    if (!eglMakeCurrent(eglDisplay->display, eglSurface, eglSurface, eglContext)) {
      throw std::runtime_error("Switching OpenGL context failed.\n");
    }
  }
  void deactivate() override {
    if (!eglMakeCurrent(eglDisplay->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT)) {
      throw std::runtime_error("Removing OpenGL context failed.\n");
    }
  }

  void updateAssumedState() override {}

  EGLDisplay eglDisplayHandle() const { return eglDisplay->display; }
  EGLConfig eglConfigHandle() const { return eglDisplay->config; }
  EGLContext eglContextHandle() const { return eglContext; }

 private:
  const std::shared_ptr<const EGLDisplayConfig> eglDisplay = EGLDisplayConfig::create();
  EGLContext eglContext = EGL_NO_CONTEXT;
  EGLSurface eglSurface = EGL_NO_SURFACE;
};
}  // namespace gl
}  // namespace flmln
