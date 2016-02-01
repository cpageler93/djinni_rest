//
//  DjinniRestService.m
//  DjinniRest
//
//  Created by Christoph Pageler on 01/02/16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "DjinniRestService.h"

#import "NativeApi.h"
#import "ThreadLauncher.h"
#import "ApiPostsResponse.h"
#import "ApiPhotosResponse.h"
#import "Http.h"

@interface DjinniRestService ()

@property (strong, nonatomic) NativeApi *nativeApi;
@property (strong, nonatomic) ThreadLauncher *threadLauncher;
@property (strong, nonatomic) Http *http;

@end

@implementation DjinniRestService

+ (instancetype)sharedInstance
{
	static DjinniRestService *_sharedInstance;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		_sharedInstance = [[DjinniRestService alloc] init];
	});
	return _sharedInstance;
}

- (instancetype)init
{
	if (self = [super init]) {
		
		self.threadLauncher = [[ThreadLauncher alloc] init];
		self.http = [[Http alloc] init];
		self.nativeApi = [NativeApi createApi:self.threadLauncher
										 http:self.http];
	}
	return self;
}

- (void)getPhotosIndex:(void (^)(NSArray<NativePhotoModel *> *photos))completion
{
	[self.nativeApi getPhotosIndex:[ApiPhotosResponse indexResponseOnSuccess:^(NSArray<NativePhotoModel *> *photos) {
		
		completion(photos);
		
	} onFailure:^{
		NSLog(@"FAUILEUR");
	}]];
}

- (void)getImageFromUrl:(NSURL *)imageUrl
			 completion:(void (^)(UIImage *image))completion
{
	[self.http getImageDataFromURL:imageUrl
						completion:^(NSData *imageData)
	{
		UIImage *image = [UIImage imageWithData:imageData];
		completion(image);
	}];
}

- (BOOL)isPostValid:(NativePostModel *)postModel
{
	return [self.nativeApi isPostValid:postModel];
}

- (NativePostModel *)modifyPost:(NativePostModel *)postModel
{
	return [self.nativeApi modifyPost:postModel];
}

@end
