//
//  ApiPostsResponse.m
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ApiPostsResponse.h"

@interface ApiPostsResponse() {
	
}

@property (copy, nonatomic) void (^onIndexSuccessBlock)(NSArray<NativePostModel *> *);
@property (copy, nonatomic) void (^onShowSuccessBlock)(NativePostModel *);
@property (copy, nonatomic) void (^onFailureBlock)(void);


@end

@implementation ApiPostsResponse

+ (instancetype)indexResponseOnSuccess:(void (^)(NSArray<NativePostModel *> *posts))onIndexSuccess
							 onFailure:(void (^)(void))onFailure
{
	return [[ApiPostsResponse alloc] initWithOnIndexSuccess:onIndexSuccess
											  onShowSuccess:nil
												  onFailure:onFailure];
}

+ (instancetype)showResponseOnSuccess:(void (^)(NativePostModel *post))onShowSuccess
							onFailure:(void (^)(void))onFailure
{
	return [[ApiPostsResponse alloc] initWithOnIndexSuccess:nil
											  onShowSuccess:onShowSuccess
												  onFailure:onFailure];
}

- (instancetype)initWithOnIndexSuccess:(void (^)(NSArray<NativePostModel *> *))onIndexSuccess
						 onShowSuccess:(void (^)(NativePostModel *))onShowSuccess
						onFailure:(void (^)(void))onFailure
{
	if (self = [super init]) {
		self.onIndexSuccessBlock = onIndexSuccess;
		self.onShowSuccessBlock = onShowSuccess;
		self.onFailureBlock = onFailure;
	}
	return self;
}

- (void)onIndexSuccess:(nonnull NSArray<NativePostModel *> *)result
{
	self.onIndexSuccessBlock(result);
}

- (void)onShowSuccess:(nonnull NativePostModel *)result
{
	self.onShowSuccessBlock(result);
}

- (void)onFailure
{
	self.onFailureBlock();
}

@end
