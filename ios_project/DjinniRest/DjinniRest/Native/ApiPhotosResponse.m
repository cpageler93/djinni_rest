//
//  ApiPhotosResponse.m
//  DjinniRest
//
//  Created by Christoph Pageler on 01/02/16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ApiPhotosResponse.h"

@interface ApiPhotosResponse ()

@property (copy, nonatomic) void (^onIndexSuccessBlock)(NSArray<NativePhotoModel *> *);
@property (copy, nonatomic) void (^onShowSuccessBlock)(NativePhotoModel *);
@property (copy, nonatomic) void (^onFailureBlock)(void);

@end

@implementation ApiPhotosResponse

+ (instancetype)indexResponseOnSuccess:(void (^)(NSArray<NativePhotoModel *> *posts))onIndexSuccess
							 onFailure:(void (^)(void))onFailure
{
	return [[ApiPhotosResponse alloc] initWithOnIndexSuccess:onIndexSuccess
											  onShowSuccess:nil
												  onFailure:onFailure];
}

+ (instancetype)showResponseOnSuccess:(void (^)(NativePhotoModel *post))onShowSuccess
							onFailure:(void (^)(void))onFailure
{
	return [[ApiPhotosResponse alloc] initWithOnIndexSuccess:nil
											  onShowSuccess:onShowSuccess
												  onFailure:onFailure];
}

- (instancetype)initWithOnIndexSuccess:(void (^)(NSArray<NativePhotoModel *> *))onIndexSuccess
						 onShowSuccess:(void (^)(NativePhotoModel *))onShowSuccess
							 onFailure:(void (^)(void))onFailure
{
	if (self = [super init]) {
		self.onIndexSuccessBlock = onIndexSuccess;
		self.onShowSuccessBlock = onShowSuccess;
		self.onFailureBlock = onFailure;
	}
	return self;
}

- (void)onIndexSuccess:(nonnull NSArray<NativePhotoModel *> *)result
{
	self.onIndexSuccessBlock(result);
}

- (void)onShowSuccess:(nonnull NativePhotoModel *)result
{
	self.onShowSuccessBlock(result);
}

- (void)onFailure
{
	self.onFailureBlock();
}

@end
