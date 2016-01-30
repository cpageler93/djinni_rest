// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#include "async_task.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class NativeAsyncTask;

namespace djinni_generated {

class AsyncTask
{
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::AsyncTask>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::AsyncTask>;
    using ObjcType = NativeAsyncTask*;

    using Boxed = AsyncTask;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

