package com.kekland.flmln;

import androidx.annotation.Keep;

import io.flutter.view.TextureRegistry;

public class FlutterTextureRegistryProxy {
    FlutterTextureRegistryProxy(TextureRegistry registry) {
        this.registry = registry;
    }
    
    private TextureRegistry registry;

    @Keep
    public TextureRegistry.ImageTextureEntry createImageTexture() {
        return registry.createImageTexture();
    }

    @Keep
    public TextureRegistry.SurfaceTextureEntry createSurfaceTextureEntry() {
        return registry.createSurfaceTexture();
    }

    @Keep
    public TextureRegistry.SurfaceProducer createSurfaceProducer() {
        return registry.createSurfaceProducer();
    }
}
