Pod::Spec.new do |s|
  s.name     = 'CorePlot'
  s.version  = '1.4'
  s.license  = 'BSD'
  s.summary  = 'Cocoa plotting framework for Mac OS X and iOS.'
  s.homepage = 'http://code.google.com/p/core-plot/'
  s.authors  = { 'Drew McCormack' => 'drewmccormack@mac.com',
                 'Brad Larson'    => 'larson@sunsetlakesoftware.com',
                 'Eric Skroch'    => 'eskroch@mac.com',
                 'Barry Wark'     => 'barrywark@gmail.com' }
  s.source   = { :git => 'https://github.com/Backelite/core-plot.git' }

  s.description = 'Core Plot is a plotting framework for OS X and iOS. It provides 2D visualization ' \
                  'of data, and is tightly integrated with Apple technologies like Core Animation, ' \
                  'Core Data, and Cocoa Bindings.'

  s.source_files = 'Source/framework/Source/*.{h,m}'
  s.preserve_paths = 'Source/framework/TestResources'
  s.exclude_files = '**/*{TestCase,Tests}.{h,m}'
  s.ios.source_files = 'Source/framework/CorePlot-CocoaTouch.h', 'Source/framework/iPhoneOnly/*.{h,m}'
  s.osx.source_files = 'Source/framework/CorePlot.h', 'Source/framework/MacOnly/*.{h,m}'
  s.framework   = 'QuartzCore'
  s.requires_arc = false

  s.prepare_command = <<-CMD
    dtrace -h -s Source/framework/TestResources/CorePlotProbes.d -o Source/framework/Source/CorePlotProbes.h
  CMD
end
