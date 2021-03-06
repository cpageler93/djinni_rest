// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from thread.djinni

#include "thread_launcher.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol NativeThreadLauncher;

namespace djinni_generated {

class ThreadLauncher
{
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::ThreadLauncher>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::ThreadLauncher>;
    using ObjcType = id<NativeThreadLauncher>;

    using Boxed = ThreadLauncher;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

