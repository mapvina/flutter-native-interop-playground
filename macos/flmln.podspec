Pod::Spec.new do |s|
  s.name             = 'flmln'
  s.version          = '0.0.1'
  s.summary          = 'Bindings for using mapvina-native in Flutter on macOS'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'kekland' => 'kk.erzhan@gmail.com' }
  s.source           = { :path => '.' }

  s.osx.source_files = ['flmln/Sources/flmln/*']
  s.osx.vendored_frameworks = 'flmln/Artifacts/flmln.xcframework'
  s.osx.dependency 'FlutterMacOS'
  s.osx.deployment_target = '10.15'

  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }
end
