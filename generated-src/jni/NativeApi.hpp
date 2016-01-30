// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#pragma once

#include "api.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeApi final : ::djinni::JniInterface<::djinni_rest_gen::Api, NativeApi> {
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::Api>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::Api>;
    using JniType = jobject;

    using Boxed = NativeApi;

    ~NativeApi();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeApi>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeApi>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeApi();
    friend ::djinni::JniClass<NativeApi>;
    friend ::djinni::JniInterface<::djinni_rest_gen::Api, NativeApi>;

};

}  // namespace djinni_generated
