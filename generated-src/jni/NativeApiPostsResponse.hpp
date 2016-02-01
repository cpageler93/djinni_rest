// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include "api_posts_response.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeApiPostsResponse final : ::djinni::JniInterface<::djinni_rest_gen::ApiPostsResponse, NativeApiPostsResponse> {
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::ApiPostsResponse>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::ApiPostsResponse>;
    using JniType = jobject;

    using Boxed = NativeApiPostsResponse;

    ~NativeApiPostsResponse();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeApiPostsResponse>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeApiPostsResponse>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeApiPostsResponse();
    friend ::djinni::JniClass<NativeApiPostsResponse>;
    friend ::djinni::JniInterface<::djinni_rest_gen::ApiPostsResponse, NativeApiPostsResponse>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::djinni_rest_gen::ApiPostsResponse
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void on_index_success(const std::vector<::djinni_rest_gen::PostModel> & result) override;
        void on_show_success(const ::djinni_rest_gen::PostModel & result) override;
        void on_failure() override;

    private:
        friend ::djinni::JniInterface<::djinni_rest_gen::ApiPostsResponse, ::djinni_generated::NativeApiPostsResponse>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/mycompany/djinni_rest/ApiPostsResponse") };
    const jmethodID method_onIndexSuccess { ::djinni::jniGetMethodID(clazz.get(), "onIndexSuccess", "(Ljava/util/ArrayList;)V") };
    const jmethodID method_onShowSuccess { ::djinni::jniGetMethodID(clazz.get(), "onShowSuccess", "(Lcom/mycompany/djinni_rest/PostModel;)V") };
    const jmethodID method_onFailure { ::djinni::jniGetMethodID(clazz.get(), "onFailure", "()V") };
};

}  // namespace djinni_generated
