import Flutter
import Foundation

public class FlMlnPluginIOS: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let instance = FlMlnPluginIOS()
    FlMlnDarwinPluginGlobals.textureRegistry = FlutterTextureRegistryProxy(textures: registrar.textures())
  }
}
