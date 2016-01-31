//
//  PostsIndexResponse.h
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NativePostsIndexResponse.h"

@interface PostsIndexResponse : NSObject<NativePostsIndexResponse>

+ (instancetype)responseOnSuccess:(void (^)(NSArray<NativePostModel *> *posts))onSuccess
						onFailure:(void (^)(void))onFailure;


@end
