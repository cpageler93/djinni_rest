./build_ios/libdjinnirest.xcodeproj: libdjinnirest.gyp ./deps/djinni/support-lib/support_lib.gyp djinni/djinni_rest.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./libdjinnirest.gyp

ios: ./build_ios/libdjinnirest.xcodeproj
	xcodebuild -workspace ios_project/DjinniRest.xcworkspace \
	-scheme DjinniRest \
	-configuration 'Debug' \
	-sdk iphoneos

# ANDROID
GypAndroid.mk: libdjinnirest.gyp ./deps/djinni/support-lib/support_lib.gyp djinni/djinni_rest.djinni
	sh ./run_djinni.sh
	ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) deps/gyp/gyp --depth=. -f android -DOS=android -Ideps/djinni/common.gypi ./libdjinnirest.gyp --root-target=libdjinnirest_jni

android: GypAndroid.mk
	cd android_project/DjinniRest/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python deps/djinni/example/glob.py ./ '*.apk'
