/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@interface ABImageService : NSObject
{
}

+ (id)service;
+ (id)fullSizeImageURLForURL:(id)arg1;
+ (id)thumbnailImageURLForURL:(id)arg1;
+ (BOOL)isImageServiceLink:(id)arg1;
+ (BOOL)entitiesMightContainMedia:(id)arg1;
+ (BOOL)stringMightContainMedia:(id)arg1;
+ (id)isVideoServiceLink:(id)arg1;
+ (BOOL)isMediaLink:(id)arg1;
+ (BOOL)isHotLink:(id)arg1;
+ (BOOL)isYFrogImageLink:(id)arg1;
+ (BOOL)isTwitPicLink:(id)arg1;
+ (BOOL)isTwitgooLink:(id)arg1;
+ (BOOL)isImglyLink:(id)arg1;
+ (BOOL)isPixImLink:(id)arg1;
+ (BOOL)isTweetphotoLink:(id)arg1;
+ (BOOL)isPikchurLink:(id)arg1;
+ (BOOL)isMobypictureLink:(id)arg1;
+ (id)currentService;
+ (int)approximateImageLinkLength;
+ (int)approximateVideoLinkLength;
+ (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
+ (id)currentVideoService;
+ (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;

@end

