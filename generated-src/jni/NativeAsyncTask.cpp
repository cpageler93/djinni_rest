// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from thread.djinni

#include "NativeAsyncTask.hpp"  // my header

namespace djinni_generated {

NativeAsyncTask::NativeAsyncTask() : ::djinni::JniInterface<::djinni_rest_gen::AsyncTask, NativeAsyncTask>("com/mycompany/djinni_rest/AsyncTask$CppProxy") {}

NativeAsyncTask::~NativeAsyncTask() = default;


CJNIEXPORT void JNICALL Java_com_mycompany_djinni_1rest_AsyncTask_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::djinni_rest_gen::AsyncTask>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_mycompany_djinni_1rest_AsyncTask_00024CppProxy_native_1execute(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::djinni_rest_gen::AsyncTask>(nativeRef);
        ref->execute();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
