// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#import "NativeApi+Private.h"
#import "NativeApi.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "NativeApi+Private.h"
#import "NativeThreadLauncher+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface NativeApi ()

- (id)initWithCpp:(const std::shared_ptr<::djinni_rest_gen::Api>&)cppRef;

@end

@implementation NativeApi {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::djinni_rest_gen::Api>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::djinni_rest_gen::Api>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable NativeApi *)createApi:(nullable id<NativeThreadLauncher>)launcher {
    try {
        auto r = ::djinni_rest_gen::Api::create_api(::djinni_generated::ThreadLauncher::toCpp(launcher));
        return ::djinni_generated::Api::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)doSomething {
    try {
        _cppRefHandle.get()->do_something();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Api::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Api::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<NativeApi>(cpp);
}

}  // namespace djinni_generated

@end
