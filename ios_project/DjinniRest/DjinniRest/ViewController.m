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
#import "ApiPostsResponse.h"
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
	
	[nativeApi getPostsIndex:[ApiPostsResponse indexResponseOnSuccess:^(NSArray<NativePostModel *> *posts) {
		
		NSLog(@"Posts: %@", posts);
		[self logThreadName];
		
	} onFailure:^{
		
		NSLog(@"failure");
		[self logThreadName];
		
	}]];
	
	[nativeApi getPostsShow:1
		   apiPostsResponse:[ApiPostsResponse showResponseOnSuccess:^(NativePostModel *post) {
		
		NSLog(@"Post: %@", post);
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
