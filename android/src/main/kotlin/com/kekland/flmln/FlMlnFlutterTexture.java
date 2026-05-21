package com.kekland.flmln;

import android.graphics.SurfaceTexture;
import android.view.Surface;

import androidx.annotation.Keep;

import io.flutter.view.TextureRegistry;

@Keep
public class FlMlnFlutterTexture {
    @Keep
    public FlMlnFlutterTexture() {
        entry = FlMlnPluginGlobals.getFlutterTextureRegistryProxy().createSurfaceTextureEntry();
    }

    @Keep
    void release() {
        entry.release();
    }

    @Keep
    long getTextureId() {
        return entry.id();
    }

    @Keep
    SurfaceTexture getSurfaceTexture() {
        return entry.surfaceTexture();
    }

    @Keep
    Surface getSurface() {
        return new Surface(getSurfaceTexture());
    }

    private final TextureRegistry.SurfaceTextureEntry entry;
}
