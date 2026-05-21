import Foundation

#if canImport(Flutter)
  import Flutter
#endif

#if canImport(FlutterMacOS)
  import FlutterMacOS
#endif

@_cdecl("FlMlnDarwinPluginGlobals_getTextureRegistry")
public func FlMlnDarwinPluginGlobals_getTextureRegistry() -> UnsafeRawPointer? {
  guard let proxy = FlMlnDarwinPluginGlobals.textureRegistry else {
    return nil
  }
  return UnsafeRawPointer(Unmanaged.passUnretained(proxy).toOpaque())
}

@objc public class FlMlnDarwinPluginGlobals: NSObject {
  @objc public static var textureRegistry: FlutterTextureRegistryProxy?
}
