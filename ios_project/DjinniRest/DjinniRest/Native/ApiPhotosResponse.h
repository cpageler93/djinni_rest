//
//  ApiPhotosResponse.h
//  DjinniRest
//
//  Created by Christoph Pageler on 01/02/16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NativeApiPhotosResponse.h"

@interface ApiPhotosResponse : NSObject<NativeApiPhotosResponse>

+ (instancetype)indexResponseOnSuccess:(void (^)(NSArray<NativePhotoModel *> *photos))onIndexSuccess
							 onFailure:(void (^)(void))onFailure;

+ (instancetype)showResponseOnSuccess:(void (^)(NativePhotoModel *photo))onShowSuccess
							onFailure:(void (^)(void))onFailure;

@end
