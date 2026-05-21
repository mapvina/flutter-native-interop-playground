package com.kekland.flmln;

import androidx.annotation.Keep;

public class FlMlnPluginGlobals {
    private static FlutterTextureRegistryProxy textureRegistryProxy;

    static void setFlutterTextureRegistryProxy(FlutterTextureRegistryProxy proxy) {
        textureRegistryProxy = proxy;
    }

    @Keep
    static FlutterTextureRegistryProxy getFlutterTextureRegistryProxy() {
        return textureRegistryProxy;
    }
}
