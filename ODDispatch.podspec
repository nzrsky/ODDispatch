
Pod::Spec.new do |s|
  s.name         = 'ODDispatch'
  s.version      = '1.0.0'
  s.summary      = 'GCD utils functions'
  s.homepage     = 'https://github.com/Rogaven/ODDispatch'
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { 'Alexey Nazaroff' => 'alexx.nazaroff@gmail.com' }
  s.source       = { :git => 'https://github.com/Rogaven/ODDispatch.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.6'
  s.watchos.deployment_target = '1.0'
  s.tvos.deployment_target = '1.0'

  s.requires_arc = true
  
  s.source_files = 'src/**/*'
  s.public_header_files = 'src/include/**/*'
  
  #s.dependency ''
end

