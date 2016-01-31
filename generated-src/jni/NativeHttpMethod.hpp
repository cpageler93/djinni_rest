// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#pragma once

#include "djinni_support.hpp"
#include "http_method.hpp"

namespace djinni_generated {

class NativeHttpMethod final : ::djinni::JniEnum {
public:
    using CppType = ::djinni_rest_gen::HttpMethod;
    using JniType = jobject;

    using Boxed = NativeHttpMethod;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeHttpMethod>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeHttpMethod>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeHttpMethod() : JniEnum("com/mycompany/djinni_rest/HttpMethod") {}
    friend ::djinni::JniClass<NativeHttpMethod>;
};

}  // namespace djinni_generated