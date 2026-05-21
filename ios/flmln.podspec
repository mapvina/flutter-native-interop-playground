Pod::Spec.new do |s|
  s.name             = 'flmln'
  s.version          = '0.0.1'
  s.summary          = 'Bindings for using mapvina-native in Flutter on iOS'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'kekland' => 'kk.erzhan@gmail.com' }
  s.source           = { :path => '.' }

  s.ios.source_files = ['flmln/Sources/flmln/*']
  s.ios.vendored_frameworks = 'flmln/Artifacts/flmln.xcframework'
  s.ios.dependency 'Flutter'
  s.ios.deployment_target = '12.0'

  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }
end
