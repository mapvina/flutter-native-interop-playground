#pragma once

#include <android/native_window.h>
#include <android/native_window_jni.h>

#include <attach_env.hpp>
#include <jni.hpp>
#include <jni/jni.hpp>

namespace flmln {
namespace android {
class AndroidSurface {
 public:
  static constexpr auto Name() { return "android/view/Surface"; };
};

class FlutterTexture {
 public:
  static constexpr auto Name() { return "com/kekland/flmln/FlMlnFlutterTexture"; }
  static void registerNative(jni::JNIEnv& env) { jni::Class<FlutterTexture>::Singleton(env); }

  FlutterTexture() {
    mbgl::android::UniqueEnv env{mbgl::android::AttachEnv()};

    static auto& cls = jni::Class<FlutterTexture>::Singleton(*env);
    static auto constructor = cls.GetConstructor(*env);

    javaObject = jni::NewGlobal<jni::EnvAttachingDeleter>(*env, cls.New(*env, constructor));
  };

  ~FlutterTexture() {
    release();
    javaObject.reset();
  }

  int64_t getTextureId() {
    mbgl::android::UniqueEnv env{mbgl::android::AttachEnv()};

    static auto& cls = jni::Class<FlutterTexture>::Singleton(*env);
    static auto getTextureId = cls.GetMethod<jni::jlong()>(*env, "getTextureId");
    auto result = javaObject.Call(*env, getTextureId);

    return static_cast<int64_t>(result);
  }

  ANativeWindow* getNativeWindow() {
    mbgl::android::UniqueEnv env{mbgl::android::AttachEnv()};

    static auto& cls = jni::Class<FlutterTexture>::Singleton(*env);
    static auto getSurfaceMethod = cls.GetMethod<jni::Object<flmln::android::AndroidSurface>()>(*env, "getSurface");

    auto surface = javaObject.Call(*env, getSurfaceMethod);
    return ANativeWindow_fromSurface(env.get(), reinterpret_cast<jobject>(surface.get()));
  }

 private:
  void release() {
    mbgl::android::UniqueEnv env{mbgl::android::AttachEnv()};

    static auto& cls = jni::Class<FlutterTexture>::Singleton(*env);
    static auto release = cls.GetMethod<void()>(*env, "release");
    javaObject.Call(*env, release);
  }

  jni::Global<jni::Object<FlutterTexture>, jni::EnvAttachingDeleter> javaObject;
};
}  // namespace android
}  // namespace flmln