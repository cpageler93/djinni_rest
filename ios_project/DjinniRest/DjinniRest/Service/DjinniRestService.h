//
//  DjinniRestService.h
//  DjinniRest
//
//  Created by Christoph Pageler on 01/02/16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "NativePhotoModel.h"
#import "NativePostModel.h"

@interface DjinniRestService : NSObject

+ (instancetype)sharedInstance;

- (void)getPhotosIndex:(void (^)(NSArray<NativePhotoModel *> *photos))completion;

- (void)getImageFromUrl:(NSURL *)imageUrl
			 completion:(void (^)(UIImage *image))completion;

- (BOOL)isPostValid:(NativePostModel *)postModel;

- (NativePostModel *)modifyPost:(NativePostModel *)postModel;

@end
