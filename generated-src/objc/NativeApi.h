// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#import <Foundation/Foundation.h>
@class NativeApi;
@protocol NativeApiPhotosResponse;
@protocol NativeApiPostsResponse;
@protocol NativeHttp;
@protocol NativeThreadLauncher;


@interface NativeApi : NSObject

+ (nullable NativeApi *)createApi:(nullable id<NativeThreadLauncher>)launcher
                             http:(nullable id<NativeHttp>)http;

- (void)getPostsIndex:(nullable id<NativeApiPostsResponse>)apiPostsResponse;

- (void)getPostsShow:(int64_t)postId
    apiPostsResponse:(nullable id<NativeApiPostsResponse>)apiPostsResponse;

- (void)getPhotosIndex:(nullable id<NativeApiPhotosResponse>)apiPhotosResponse;

- (void)getPhotosShow:(int64_t)photoId
    apiPhotosResponse:(nullable id<NativeApiPhotosResponse>)apiPhotosResponse;

@end
