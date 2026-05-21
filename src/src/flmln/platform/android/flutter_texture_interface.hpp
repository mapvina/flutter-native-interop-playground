#pragma once

#include <android/native_window.h>

#include <jni.hpp>

#include "../../flutter_texture_interface.hpp"
#include "../../renderer_backend.hpp"
#include "flutter_texture.hpp"

namespace flmln {
namespace android {
class FlutterTextureInterface : public flmln::FlutterTextureInterface {
 public:
  FlutterTextureInterface() {
    texture = std::make_unique<flmln::android::FlutterTexture>();
    textureId = texture->getTextureId();
    window = texture->getNativeWindow();
  }
  ~FlutterTextureInterface() override {
    if (window) {
      ANativeWindow_release(window);
      window = nullptr;
    }

    texture.reset();
  }

  int64_t getTextureId() const override { return textureId; }
  void update(flmln::RendererBackend& backend) override {
    // No-op, backend blits directly to Flutter texture.
  }

  ANativeWindow* getNativeWindow() const { return window; }

  void setSize(int32_t width, int32_t height) {
    if (window) {
      ANativeWindow_setBuffersGeometry(window, width, height, WINDOW_FORMAT_RGBA_8888);
    }
  }

 private:
  std::unique_ptr<flmln::android::FlutterTexture> texture;
  ANativeWindow* window = nullptr;
  int64_t textureId = -1;
};
}  // namespace android
}  // namespace flmln