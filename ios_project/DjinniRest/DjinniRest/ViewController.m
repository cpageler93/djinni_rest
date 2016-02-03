//
//  ViewController.m
//  DjinniRest
//
//  Created by Christoph Pageler on 25.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ViewController.h"
#import "DjinniRestService.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
	[super viewDidLoad];
	
//	NativePostModel *post = [NativePostModel postModelWithId:0
//													   title:@"Title"
//														body:@"Body"];
//	BOOL isPostValid = [[DjinniRestService sharedInstance] isPostValid:post];
//	NSLog(@"Post %@ is valid: %d", post, isPostValid);
//	
//	NativePostModel *modifiedPost = [[DjinniRestService sharedInstance] modifyPost:post];
//	NSLog(@"Modified Post: %@", modifiedPost);
	
	NativeHelloModel *helloModel = [[DjinniRestService sharedInstance] sayHello:@"Hello World"];
	NSLog(@"Hello Model: %@", helloModel);
	
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
