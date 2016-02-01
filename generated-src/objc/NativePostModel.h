// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#import <Foundation/Foundation.h>

@interface NativePostModel : NSObject
- (nonnull instancetype)initWithId:(int64_t)id
                             title:(nonnull NSString *)title
                              body:(nonnull NSString *)body;
+ (nonnull instancetype)postModelWithId:(int64_t)id
                                  title:(nonnull NSString *)title
                                   body:(nonnull NSString *)body;

@property (nonatomic, readonly) int64_t id;

@property (nonatomic, readonly, nonnull) NSString * title;

@property (nonatomic, readonly, nonnull) NSString * body;

@end
