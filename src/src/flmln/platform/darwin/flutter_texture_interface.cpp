#include "flutter_texture_interface.hpp"

#include "../../flutter_texture_interface.hpp"

namespace flmln {
std::shared_ptr<flmln::FlutterTextureInterface> FlutterTextureInterface::Create() {
  return std::make_shared<flmln::darwin::FlutterTextureInterface>();
}
}  // namespace flmln