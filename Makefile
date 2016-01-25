./build_ios/libdjinnirest.xcodeproj: libdjinnirest.gyp ./deps/djinni/support-lib/support_lib.gyp djinni_rest.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./libdjinnirest.gyp

ios: ./build_ios/libdjinnirest.xcodeproj
	xcodebuild -workspace ios_project/DjinniRest.xcworkspace \
	-scheme DjinniRest \
	-configuration 'Debug' \
	-sdk iphoneos