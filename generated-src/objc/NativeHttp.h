// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#import "NativeHttpMethod.h"
#import <Foundation/Foundation.h>
@protocol NativeHttpCallback;


@protocol NativeHttp

- (void)send:(NativeHttpMethod)httpMethod
         url:(nonnull NSString *)url
    callback:(nullable id<NativeHttpCallback>)callback;

@end
