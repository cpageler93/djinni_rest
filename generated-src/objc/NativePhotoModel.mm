// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#import "NativePhotoModel.h"


@implementation NativePhotoModel

- (nonnull instancetype)initWithId:(int64_t)id
                           albumId:(int64_t)albumId
                             title:(nonnull NSString *)title
                               url:(nonnull NSString *)url
                      thumbnailUrl:(nonnull NSString *)thumbnailUrl
{
    if (self = [super init]) {
        _id = id;
        _albumId = albumId;
        _title = [title copy];
        _url = [url copy];
        _thumbnailUrl = [thumbnailUrl copy];
    }
    return self;
}

+ (nonnull instancetype)photoModelWithId:(int64_t)id
                                 albumId:(int64_t)albumId
                                   title:(nonnull NSString *)title
                                     url:(nonnull NSString *)url
                            thumbnailUrl:(nonnull NSString *)thumbnailUrl
{
    return [[self alloc] initWithId:id
                            albumId:albumId
                              title:title
                                url:url
                       thumbnailUrl:thumbnailUrl];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p id:%@ albumId:%@ title:%@ url:%@ thumbnailUrl:%@>", self.class, self, @(self.id), @(self.albumId), self.title, self.url, self.thumbnailUrl];
}

@end
