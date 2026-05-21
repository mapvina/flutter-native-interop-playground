import FlutterMacOS
import Foundation

public class FlMlnPluginMacOS: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let instance = FlMlnPluginMacOS()
    FlMlnDarwinPluginGlobals.textureRegistry = FlutterTextureRegistryProxy(textures: registrar.textures)
  }
}
