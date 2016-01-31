// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#include "http.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol NativeHttp;

namespace djinni_generated {

class Http
{
public:
    using CppType = std::shared_ptr<::djinni_rest_gen::Http>;
    using CppOptType = std::shared_ptr<::djinni_rest_gen::Http>;
    using ObjcType = id<NativeHttp>;

    using Boxed = Http;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

