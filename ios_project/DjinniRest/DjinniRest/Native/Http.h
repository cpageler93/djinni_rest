//
//  Http.h
//  DjinniRest
//
//  Created by Christoph Pageler on 30.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NativeHttp.h"

@interface Http : NSObject<NativeHttp>

- (void)getImageDataFromURL:(NSURL *)url
				 completion:(void (^)(NSData *imageData))completion;

@end
