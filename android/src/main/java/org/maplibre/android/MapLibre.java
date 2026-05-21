package com.mapvina.android;

import android.content.Context;
import androidx.annotation.NonNull;

public final class MapVina {
  private static volatile Context appContext;
  private static volatile ModuleProvider moduleProvider;

  public static void init(@NonNull Context context) {
    appContext = context.getApplicationContext();
  }

  @NonNull  
  public static Context getApplicationContext() {
    return appContext;
  }

  @NonNull
  public static ModuleProvider getModuleProvider() {
    if (moduleProvider == null) {
      moduleProvider = new ModuleProviderImpl();
    }
    return moduleProvider;
  }

}