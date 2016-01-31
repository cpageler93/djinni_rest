// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#include "NativeApi.hpp"  // my header
#include "Marshal.hpp"
#include "NativeApi.hpp"
#include "NativeApiPostsResponse.hpp"
#include "NativeHttp.hpp"
#include "NativeThreadLauncher.hpp"

namespace djinni_generated {

NativeApi::NativeApi() : ::djinni::JniInterface<::djinni_rest_gen::Api, NativeApi>("com/mycompany/djinni_rest/Api$CppProxy") {}

NativeApi::~NativeApi() = default;


CJNIEXPORT void JNICALL Java_com_mycompany_djinni_1rest_Api_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::djinni_rest_gen::Api>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_mycompany_djinni_1rest_Api_createApi(JNIEnv* jniEnv, jobject /*this*/, jobject j_launcher, jobject j_http)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::djinni_rest_gen::Api::create_api(::djinni_generated::NativeThreadLauncher::toCpp(jniEnv, j_launcher),
                                                    ::djinni_generated::NativeHttp::toCpp(jniEnv, j_http));
        return ::djinni::release(::djinni_generated::NativeApi::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_mycompany_djinni_1rest_Api_00024CppProxy_native_1getPostsIndex(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_apiPostsResponse)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::djinni_rest_gen::Api>(nativeRef);
        ref->get_posts_index(::djinni_generated::NativeApiPostsResponse::toCpp(jniEnv, j_apiPostsResponse));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_mycompany_djinni_1rest_Api_00024CppProxy_native_1getPostsShow(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_postId, jobject j_apiPostsResponse)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::djinni_rest_gen::Api>(nativeRef);
        ref->get_posts_show(::djinni::I64::toCpp(jniEnv, j_postId),
                            ::djinni_generated::NativeApiPostsResponse::toCpp(jniEnv, j_apiPostsResponse));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
