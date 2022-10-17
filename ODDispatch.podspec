
Pod::Spec.new do |s|
  s.name         = 'ODDispatch'
  s.version      = '1.0.2'
  s.summary      = 'GCD/DispatchQueue syntax sugar for ObjC'
  s.homepage     = 'https://github.com/nzrsky/ODDispatch'
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { 'Alexey Nazarov' => 'alexx.nazaroff@gmail.com' }
  s.source       = { :git => 'https://github.com/nzrsky/ODDispatch.git', :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/nzrsky'
  s.ios.deployment_target = '10.0'
  s.osx.deployment_target = '10.10'
  s.watchos.deployment_target = '5.0'
  s.tvos.deployment_target = '10.0'

  s.requires_arc = true
  s.source_files = 'src/**/*.{h,m}'

  s.frameworks = 'Foundation'
  
  pch_TARGETS = <<-EOS
#ifndef TARGET_OS_IOS
    #define TARGET_OS_IOS TARGET_OS_IPHONE
#endif
#ifndef TARGET_OS_WATCH
    #define TARGET_OS_WATCH 0
#endif
#ifndef TARGET_OS_TV
    #define TARGET_OS_TV 0
#endif
EOS
  s.prefix_header_contents = pch_TARGETS
	
  s.dependency 'ODStringify', '~> 1.1.5'
end

