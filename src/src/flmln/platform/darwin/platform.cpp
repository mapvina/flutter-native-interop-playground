#include "../../platform.hpp"
#include "ffi.hpp"

namespace flmln {
void initializePlatform() {
  ffi_initialize();
}
}
