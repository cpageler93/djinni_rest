// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include "djinni_support.hpp"
#include "http_callback.hpp"

namespace djinni_generated {

class NativeHttpCallback final : ::djinni::JniInterface<::djinni_rest_gen::HttpCallback, NativeHttpCallback> {
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::HttpCallback>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::HttpCallback>;
    using JniType = jobject;

    using Boxed = NativeHttpCallback;

    ~NativeHttpCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeHttpCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeHttpCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeHttpCallback();
    friend ::djinni::JniClass<NativeHttpCallback>;
    friend ::djinni::JniInterface<::djinni_rest_gen::HttpCallback, NativeHttpCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::djinni_rest_gen::HttpCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void on_success(int16_t http_code, const std::string & data) override;
        void on_failure() override;

    private:
        friend ::djinni::JniInterface<::djinni_rest_gen::HttpCallback, ::djinni_generated::NativeHttpCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/mycompany/djinni_rest/HttpCallback") };
    const jmethodID method_onSuccess { ::djinni::jniGetMethodID(clazz.get(), "onSuccess", "(SLjava/lang/String;)V") };
    const jmethodID method_onFailure { ::djinni::jniGetMethodID(clazz.get(), "onFailure", "()V") };
};

}  // namespace djinni_generated
