/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABImageService.h"

@interface Mobypicture : ABImageService
{
}

+ (id)adjustedImageURLForURL:(id)arg1 insertPath:(id)arg2;
+ (id)fullSizeImageURLForURL:(id)arg1;
+ (id)thumbnailImageURLForURL:(id)arg1;
- (id)apiRoot;
- (id)apiKey;
- (id)OAuthEchoServiceProvider;
- (void)_postMedia:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)didPostMedia:(id)arg1 info:(id)arg2;
- (void)parseMobyXML:(id)arg1 info:(id)arg2;

@end

