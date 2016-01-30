//
//  ThreadLauncher.m
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "ThreadLauncher.h"

@implementation ThreadLauncher

- (void)startThread:(NSString *)name runFn:(NativeAsyncTask *)runFn
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundeclared-selector"
	NSThread *thread = [[NSThread alloc] initWithTarget:runFn
											   selector:@selector(execute)
												 object:nil];
#pragma clang diagnostic pop
	if (name) {
		thread.name = name;
	}
	[thread start];
}

@end
