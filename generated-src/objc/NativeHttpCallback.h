// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from djinni_rest.djinni

#import <Foundation/Foundation.h>


@protocol NativeHttpCallback

- (void)onSuccess:(int16_t)httpCode
             data:(nonnull NSString *)data;

- (void)onFailure;

@end