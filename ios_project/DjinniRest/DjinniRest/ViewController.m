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
	
	[[DjinniRestService sharedInstance] getPhotosIndex:^(NSArray<NativePhotoModel *> *photos) {
		
		[photos enumerateObjectsUsingBlock:^(NativePhotoModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
			if (idx == 0) {
				[[DjinniRestService sharedInstance] getImageFromUrl:[NSURL URLWithString:obj.url] completion:^(UIImage *image) {
					NSLog(@"show image: %@", image);
				}];
			} else {
				*stop = YES;
			}
		}];
	}];
	
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
