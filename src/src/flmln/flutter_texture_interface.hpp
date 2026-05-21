#pragma once

#include <cstdint>

namespace flmln {
class RendererBackend;

class FlutterTextureInterface {
 public:
  FlutterTextureInterface() = default;
  virtual ~FlutterTextureInterface() = default;

  static std::shared_ptr<FlutterTextureInterface> Create();

  // Returns the associated FlutterTexture id.
  virtual int64_t getTextureId() const = 0;
  virtual void update(flmln::RendererBackend& backend) = 0;
};
}  // namespace flmln