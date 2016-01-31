//
//  ViewController.m
//  DjinniRest
//
//  Created by Christoph Pageler on 25.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ViewController.h"
#import "NativeApi.h"
#import "ThreadLauncher.h"
#import "ApiResponse.h"
#import "PostsIndexResponse.h"
#import "Http.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
	[super viewDidLoad];
	
	ThreadLauncher *threadLauncher = [[ThreadLauncher alloc] init];
	Http *http = [[Http alloc] init];
	
	NativeApi *nativeApi = [NativeApi createApi:threadLauncher
										   http:http];
	
//	NSLog(@"1");
//	
//	[nativeApi doSomething:[ApiResponse apiResponseOnSuccess:^(NSString *result) {
//		
//		NSString *threadName = [NSThread currentThread].name;
//		
//		NSLog(@"objc success: %@ in thread %@", result, threadName);
//				
//	} onFailure:^{
//		NSLog(@"objc failure");
//	}]];
//	
//	NSLog(@"2");
	
	[nativeApi getPostsIndex:[PostsIndexResponse responseOnSuccess:^(NSArray<NativePostModel *> *posts) {
		NSLog(@"Posts: %@", posts);
		[self logThreadName];
	} onFailure:^{
		NSLog(@"failure");
		[self logThreadName];
	}]];
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

- (void)logThreadName
{
	NSString *threadName = [NSThread currentThread].name;
	if ([NSThread currentThread].isMainThread) {
		threadName = @"Main Thread";
	}
	NSLog(@"Current ObjC Thread: %@", threadName);
}

@end
