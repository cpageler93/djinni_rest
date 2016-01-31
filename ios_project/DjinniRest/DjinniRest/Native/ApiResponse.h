//
//  ApiResponse.h
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NativeApiResponse.h"

@interface ApiResponse : NSObject<NativeApiResponse>

+ (instancetype)apiResponseOnSuccess:(void (^)(NSString *result))onSuccess
						   onFailure:(void (^)(void))onFailure;

@end
