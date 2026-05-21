package com.kekland.flmln

import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result

import com.mapvina.android.MapVina

import android.util.Log

class FlMlnPlugin : FlutterPlugin {
    override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
        Thread.currentThread().contextClassLoader = this::class.java.classLoader
        NativeBridge.nativeInitialize(flutterPluginBinding.applicationContext)

        MapVina.init(flutterPluginBinding.applicationContext)
        FlMlnPluginGlobals.setFlutterTextureRegistryProxy(FlutterTextureRegistryProxy(flutterPluginBinding.textureRegistry))
    }

    override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
        // no-op
    }
}
