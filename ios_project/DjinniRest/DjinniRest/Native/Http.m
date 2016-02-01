//
//  Http.m
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import "Http.h"
#import "NativeHttpCallback.h"

@implementation Http

- (void)send:(NativeHttpMethod)httpMethod
		 url:(NSString *)url
 callback:(id<NativeHttpCallback>)callback
{
	NSURLRequest *urlRequest = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]];
	
	switch (httpMethod) {
		case NativeHttpMethodGet:
		{
			[self get:urlRequest callback:callback];
			break;
		}
		default:
		{
			[callback onFailure];
			break;
		}
	}
}

- (void)get:(NSURLRequest *)urlRequest callback:(id<NativeHttpCallback>)callback
{
	[[[NSURLSession sharedSession] dataTaskWithRequest:urlRequest
									 completionHandler:^(NSData * _Nullable data,
														 NSURLResponse * _Nullable response,
														 NSError * _Nullable error)
	{
		if (error) {
			dispatch_sync(dispatch_get_main_queue(), ^{
				[callback onFailure];
			});
		} else {
			
			int16_t httpCode = [(NSHTTPURLResponse*) response statusCode];
			NSString * strData = [[NSString alloc] initWithData:data
													   encoding:NSUTF8StringEncoding];
			
			dispatch_sync(dispatch_get_main_queue(), ^{
				[callback onSuccess:httpCode
							   data:strData];
			});
		}
	}] resume];
}

- (void)getImageDataFromURL:(NSURL *)url
				 completion:(void (^)(NSData *imageData))completion
{
	[[[NSURLSession sharedSession] dataTaskWithRequest:[NSURLRequest requestWithURL:url]
									 completionHandler:^(NSData * _Nullable data,
														 NSURLResponse * _Nullable response,
														 NSError * _Nullable error)
	{
		
		if (error) {
			NSLog(@"ERROR");
		} else {
			completion(data);
		}
		
	}] resume];
}

@end
