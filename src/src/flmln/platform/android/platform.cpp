#include "../../platform.hpp"

#include <bitmap.hpp>
#include <bitmap_factory.hpp>
#include <java/util.hpp>
#include <java_types.hpp>
#include <jni.hpp>
#include <jni_native.hpp>
#include <logger.hpp>
#include <text/local_glyph_rasterizer_jni.hpp>

#include "flutter_texture.hpp"

extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*) {
  assert(vm != nullptr);
  mbgl::android::theJVM = vm;
  return JNI_VERSION_1_6;
}

namespace mbgl {
namespace android {
void RegisterNativeHTTPRequest(JNIEnv&);
}
}  // namespace mbgl

void initializeJNI(JNIEnv* _env) {
  jni::JNIEnv& env = *_env;
  mbgl::android::java::registerNatives(env);
  mbgl::android::java::util::registerNative(env);
  mbgl::android::LocalGlyphRasterizer::registerNative(env);
  mbgl::android::RegisterNativeHTTPRequest(env);

  mbgl::android::Bitmap::registerNative(env);
  mbgl::android::BitmapFactory::registerNative(env);

  mbgl::android::Logger::registerNative(env);

  flmln::android::FlutterTexture::registerNative(env);
}

extern "C" JNIEXPORT void JNICALL Java_NativeBridge_nativeInitialize(JNIEnv* env, jclass cls, jobject appContext) {
  initializeJNI(env);
}

namespace flmln {
void initializePlatform() {}
}  // namespace flmln
