import CoreImage
import CoreVideo
import CoreGraphics
import Foundation
import Metal

#if canImport(FlutterMacOS)
  import FlutterMacOS
#else
  import Flutter
#endif

@_cdecl("FlMlnMetalFlutterTexture_create")
public func FlMlnMetalFlutterTexture_create() -> UnsafeRawPointer {
  let texture = FlMlnMetalFlutterTexture()
  return UnsafeRawPointer(Unmanaged.passRetained(texture).toOpaque())
}

@_cdecl("FlMlnMetalFlutterTexture_destroy")
public func FlMlnMetalFlutterTexture_destroy(texturePtr: UnsafeRawPointer) {
  Unmanaged<FlMlnMetalFlutterTexture>.fromOpaque(texturePtr).release()
}

@_cdecl("FlMlnMetalFlutterTexture_updateBuffer")
public func FlMlnMetalFlutterTexture_updateBuffer(
  texturePtr: UnsafeRawPointer,
  mtlTexturePtr: UnsafeRawPointer
) {
  let texture = Unmanaged<FlMlnMetalFlutterTexture>.fromOpaque(texturePtr).takeUnretainedValue()
  let mtlTexture = Unmanaged<MTLTexture>.fromOpaque(mtlTexturePtr).takeUnretainedValue()
  texture.updateBuffer(texture: mtlTexture)
}

@objc public class FlMlnMetalFlutterTexture: NSObject, FlutterTexture {
  public override init() {
    let options: [CIContextOption: Any] = [
      .outputColorSpace: CGColorSpace(name: CGColorSpace.sRGB)!,
    ]

    self.ciContext = CIContext(mtlDevice: MTLCreateSystemDefaultDevice()!, options: options)
    super.init()
  }

  private var buffer: CVPixelBuffer?
  private let ciContext: CIContext

  private var bufferPool: CVPixelBufferPool?
  private var bufferPoolWidth: Int = 0
  private var bufferPoolHeight: Int = 0

  public func updateBuffer(texture: MTLTexture) {
    let width = texture.width
    let height = texture.height

    // Create or update the buffer pool if arguments have changed
    if bufferPool == nil || bufferPoolWidth != width || bufferPoolHeight != height {
      bufferPool = nil

      let poolAttributes: [String: Any] = [
        kCVPixelBufferPoolMinimumBufferCountKey as String: 1
      ]

      let bufferAttributes: [String: Any] = [
        kCVPixelBufferWidthKey as String: width,
        kCVPixelBufferHeightKey as String: height,
        kCVPixelBufferPixelFormatTypeKey as String: kCVPixelFormatType_32BGRA,
        kCVPixelBufferBytesPerRowAlignmentKey as String: 4,
        kCVPixelBufferCGBitmapContextCompatibilityKey as String: true,
        kCVPixelBufferCGImageCompatibilityKey as String: true,
        kCVPixelBufferMetalCompatibilityKey as String: true,
        kCVPixelBufferOpenGLCompatibilityKey as String: true,
        kCVImageBufferCGColorSpaceKey as String: CGColorSpace(name: CGColorSpace.sRGB)!,
      ]

      let status = CVPixelBufferPoolCreate(
        kCFAllocatorDefault,
        poolAttributes as CFDictionary,
        bufferAttributes as CFDictionary,
        &bufferPool
      )

      guard status == kCVReturnSuccess else {
        print("Error creating pixel buffer pool: \(status)")
        return
      }

      bufferPoolWidth = width
      bufferPoolHeight = height
    }

    // Obtain new pixel buffer
    var newBuffer: CVPixelBuffer?
    let status = CVPixelBufferPoolCreatePixelBuffer(kCFAllocatorDefault, bufferPool!, &newBuffer)
    guard status == kCVReturnSuccess, let buffer = newBuffer else {
      print("Error creating pixel buffer from pool: \(status)")
      return
    }

    // Render into buffer
    CVPixelBufferLockBaseAddress(buffer, [])

    let ciImageOptions: [CIImageOption: Any] = [
      .colorSpace: CGColorSpace(name: CGColorSpace.sRGB)!
    ]

    let ciImage = CIImage(mtlTexture: texture, options: ciImageOptions)!
    let transform = CGAffineTransform(translationX: 0, y: ciImage.extent.height).scaledBy(
      x: 1, y: -1)
    let flippedImage = ciImage.transformed(by: transform)
    ciContext.render(flippedImage, to: buffer)
    CVPixelBufferUnlockBaseAddress(buffer, [])

    // Store the buffer
    self.buffer = buffer
  }

  public func copyPixelBuffer() -> Unmanaged<CVPixelBuffer>? {
    guard let buffer = self.buffer else { return nil }
    return Unmanaged.passRetained(buffer)
  }
}
