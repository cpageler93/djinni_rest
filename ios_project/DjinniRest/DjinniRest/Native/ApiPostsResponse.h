//
//  ApiPostsResponse.h
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NativeApiPostsResponse.h"

@interface ApiPostsResponse : NSObject<NativeApiPostsResponse>

+ (instancetype)indexResponseOnSuccess:(void (^)(NSArray<NativePostModel *> *posts))onIndexSuccess
							 onFailure:(void (^)(void))onFailure;

+ (instancetype)showResponseOnSuccess:(void (^)(NativePostModel *post))onShowSuccess
							onFailure:(void (^)(void))onFailure;



@end
