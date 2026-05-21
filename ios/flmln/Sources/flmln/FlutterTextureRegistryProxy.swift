import Foundation

#if canImport(FlutterMacOS)
  import FlutterMacOS
#else
  import Flutter
#endif

@_cdecl("FlutterTextureRegistryProxy_registerTexture")
public func FlutterTextureRegistryProxy_registerTexture(
  registryPtr: UnsafeRawPointer,
  texturePtr: UnsafeRawPointer
) -> Int64 {
  let registryProxy = Unmanaged<FlutterTextureRegistryProxy>.fromOpaque(registryPtr).takeUnretainedValue()
  let texture = Unmanaged<any FlutterTexture>.fromOpaque(texturePtr).takeUnretainedValue()
  return registryProxy.registerTexture(texture: texture)
}

@_cdecl("FlutterTextureRegistryProxy_textureFrameAvailable")
public func FlutterTextureRegistryProxy_textureFrameAvailable(
  registryPtr: UnsafeRawPointer,
  textureId: Int64
) {
  let registryProxy = Unmanaged<FlutterTextureRegistryProxy>.fromOpaque(registryPtr).takeUnretainedValue()
  registryProxy.textureFrameAvailable(textureId: textureId)
}

@_cdecl("FlutterTextureRegistryProxy_unregisterTexture")
public func FlutterTextureRegistryProxy_unregisterTexture(
  registryPtr: UnsafeRawPointer,
  textureId: Int64
) {
  let registryProxy = Unmanaged<FlutterTextureRegistryProxy>.fromOpaque(registryPtr).takeUnretainedValue()
  registryProxy.unregisterTexture(textureId: textureId)
}

@objc public class FlutterTextureRegistryProxy: NSObject {
  public init(textures: FlutterTextureRegistry) {
    self.textures = textures
  }

  let textures: FlutterTextureRegistry

  @objc public func registerTexture(texture: any FlutterTexture) -> Int64 {
    return self.textures.register(texture)
  }

  @objc public func textureFrameAvailable(textureId: Int64) {
    return self.textures.textureFrameAvailable(textureId)
  }

  @objc public func unregisterTexture(textureId: Int64) {
    return self.textures.unregisterTexture(textureId)
  }
}
