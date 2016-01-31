//
//  PostsIndexResponse.m
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "PostsIndexResponse.h"

@interface PostsIndexResponse() {
	
}

@property (copy, nonatomic) void (^onSuccessBlock)(NSArray<NativePostModel *> *);
@property (copy, nonatomic) void (^onFailureBlock)(void);


@end

@implementation PostsIndexResponse

+ (instancetype)responseOnSuccess:(void (^)(NSArray<NativePostModel *> *))onSuccess
						onFailure:(void (^)(void))onFailure
{
	return [[PostsIndexResponse alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
}

- (instancetype)initWithOnSuccess:(void (^)(NSArray<NativePostModel *> *))onSuccess
						onFailure:(void (^)(void))onFailure
{
	if (self = [super init]) {
		self.onSuccessBlock = onSuccess;
		self.onFailureBlock = onFailure;
	}
	return self;
}

- (void)onSuccess:(NSArray<NativePostModel *> *)result
{
	self.onSuccessBlock(result);
}

- (void)onFailure
{
	self.onFailureBlock();
}

@end
