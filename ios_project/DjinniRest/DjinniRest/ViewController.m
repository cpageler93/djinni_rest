//
//  ViewController.m
//  DjinniRest
//
//  Created by Christoph Pageler on 25.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ViewController.h"
#import "DRPostsService.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
	[super viewDidLoad];
	
	DRPostsService *postService = [DRPostsService create];
	NSArray *postsIndex = [postService getPostsIndex];
	NSLog(@"Posts Index: %@", postsIndex);
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

@end
