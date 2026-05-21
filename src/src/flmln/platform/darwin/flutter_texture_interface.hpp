#pragma once

#include <Metal/Metal.hpp>
#include <cstdint>
#include <iostream>

#include "../../flutter_texture_interface.hpp"
#include "../../mtl/renderer_backend.hpp"
#include "../../renderer_backend.hpp"
#include "ffi.hpp"

namespace flmln {
namespace darwin {

class FlutterTextureInterface : public flmln::FlutterTextureInterface {
 public:
  FlutterTextureInterface() {
    textureRegistry = ffi_FlMlnDarwinPluginGlobals_getTextureRegistry();
    flutterTexture = ffi_FlMlnMetalFlutterTexture_create();
    textureId = ffi_FlutterTextureRegistryProxy_registerTexture(textureRegistry, flutterTexture);
  }
  ~FlutterTextureInterface() override {
    ffi_FlutterTextureRegistryProxy_unregisterTexture(textureRegistry, textureId);
    ffi_FlMlnMetalFlutterTexture_destroy(flutterTexture);
  }

  int64_t getTextureId() const override { return textureId; }

  void update(flmln::RendererBackend& backend) override {
    auto mtlBackend = static_cast<flmln::mtl::RendererBackend*>(&backend);
    auto mtlTexture = mtlBackend->getMTLTexture();
    if (mtlTexture) {
      ffi_FlMlnMetalFlutterTexture_updateBuffer(flutterTexture, mtlTexture);
      ffi_FlutterTextureRegistryProxy_textureFrameAvailable(textureRegistry, textureId);
    }
  }

 private:
  int64_t textureId;
  texture_registry_proxy_t textureRegistry;
  flmln_metal_flutter_texture_t flutterTexture;
};
}  // namespace darwin
}  // namespace flmln
