//
//  ApiResponse.m
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ApiResponse.h"

@interface ApiResponse() {
	
}

@property (copy, nonatomic) void (^onSuccessBlock)(NSString *result);
@property (copy, nonatomic) void (^onFailureBlock)(void);

@end

@implementation ApiResponse

+ (instancetype)apiResponseOnSuccess:(void (^)(NSString *))onSuccess
						   onFailure:(void (^)(void))onFailure
{
	return [[ApiResponse alloc] initWithOnSuccess:onSuccess
										onFailure:onFailure];
}

- (instancetype)initWithOnSuccess:(void (^)(NSString *result))onSuccess
						onFailure:(void (^)(void))onFailure
{
	if (self = [super init]) {
		self.onSuccessBlock = onSuccess;
		self.onFailureBlock = onFailure;
	}
	return self;
}

- (void)onSuccess:(NSString *)result
{
	self.onSuccessBlock(result);
}

- (void)onFailure
{
	self.onFailureBlock();
}

@end
