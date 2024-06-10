#
#  Be sure to run `pod spec lint TPLMaps.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "TPLMaps"
  s.version      = "4.3.2"
  s.summary      = "TPL Maps, a product of TPL Trakker Ltd. is Pakistan’s first indigenous digital mapping solution."

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description  = <<-DESC
  TPL Maps, a product of TPL Trakker Ltd. is Pakistan’s first indigenous digital mapping solution. TPL Maps has been created using state of the art technology that will not only provide real time intelligent routing but also give users access to live traffic updates, turn-by-turn navigation and smart search options. TPL Maps will help users reach their desired destination by utilizing the smart search option that has over 1.35 million Points of Interests (POIs) to choose from across Pakistan. TPL Maps has been created locally and covers over 500 cities and 800,000 distinct housing addresses spread over a road network of 280,000 km. In addition TPL Maps also includes 2D models of over 55,000 POIs which will further assist users identify and reach their desired location in the shortest time period possible. TPL Maps provides voice guided turn-by-turn navigation while taking into considerations the live traffic information in the system as well as road priority levels and other variables to provide the optimum route according to the requirements of each individual user.
                   DESC

  s.homepage     = "https://github.com/anumshk27/TPLMaps"
  # s.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"
  s.screenshots = [ 'https://api.tplmaps.com/apiportal/assets/images/logo-af7d4a2a6d.svg']

  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Licensing your code is important. See http://choosealicense.com for more info.
  #  CocoaPods will detect a license file if there is a named LICENSE*
  #  Popular ones are 'MIT', 'BSD' and 'Apache License, Version 2.0'.
  #

  # s.license      = { :type => "MIT", :file => "LICENSE" }
  s.license = { :type => 'MIT', :text => <<-LICENSE
                
                   MIT License

Copyright (c) 2017 TPLMaps

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
                 LICENSE
               }


  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the authors of the library, with email addresses. Email addresses
  #  of the authors are extracted from the SCM log. E.g. $ git log. CocoaPods also
  #  accepts just a name if you'd rather not provide an email address.
  #
  #  Specify a social_media_url where others can refer to, for example a twitter
  #  profile URL.
  #

  s.author             = { "TPLMaps" => "tplmaps.dev@gmail.com" }
  # Or just: s.author    = "Muhammad Anum"
  # s.authors            = { "Muhammad Anum" => "anumshk27@gmail.com" }
  #s.social_media_url   = "https://www.facebook.com/TPLMaps/"

  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If this Pod runs only on iOS or OS X, then specify the platform and
  #  the deployment target. You can optionally include the target after the platform.
  #

  # s.platform     = :ios
  # s.platform     = :ios, "5.0"

  #  When using multiple platforms
  # s.ios.deployment_target = "10.0"
  # s.osx.deployment_target = "10.7"
  # s.watchos.deployment_target = "2.0"
  # s.tvos.deployment_target = "9.0"


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  
  s.platform = :ios, '12.0'
  s.ios.deployment_target = '12.0'
  s.source       = { :git => "https://github.com/anumshk27/TPLMaps.git", :tag => '4.3.2' }
  s.ios.vendored_frameworks = 'TPLMaps/TPLMaps.xcframework'
  s.resource = 'TPLMaps/TPLMaps.bundle'
  s.ios.framework    = 'UIKit', 'CoreLocation', 'SystemConfiguration', 'CFNetwork', 'CoreGraphics' , 'QuartzCore', 'GLKit', 'OpenGLES' , 'JavaScriptCore'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  #s.source_files = 'TPLMaps/TPLMaps.framework'
  # s.public_header_files = 'TPLMaps/TPLMaps.framework/Headers/Public/*.h'
 
  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  CocoaPods is smart about how it includes source code. For source files
  #  giving a folder will include any swift, h, m, mm, c & cpp files.
  #  For header files it will include any header in the folder.
  #  Not including the public_header_files will make all headers public.
  #

  #   s.source_files  = "Classes", "Classes/**/*.{h,m}"
  #   s.exclude_files = "Classes/Exclude"

  # s.public_header_files = "Classes/**/*.h"


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # s.resource  = "icon.png"
  # s.resources = "Resources/*.png"

  # s.preserve_paths = "FilesToSave", "MoreFilesToSave"



  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  # s.library   = "iconv"
  # s.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

   s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"

end
