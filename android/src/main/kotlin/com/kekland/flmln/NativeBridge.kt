object NativeBridge {
    init { 
      System.loadLibrary("c++_shared")
      System.loadLibrary("flmln")
    }

    @JvmStatic external fun nativeInitialize(ctx: android.content.Context)
}