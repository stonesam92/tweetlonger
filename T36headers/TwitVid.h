/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABImageService.h"

@interface TwitVid : ABImageService
{
}

- (void)authenticateWithAccount:(id)arg1 callback:(id)arg2;
- (id)parseAuthenticationData:(id)arg1;
- (void)parseAuthenticationXML:(id)arg1 info:(id)arg2;
- (void)authenticateResponse:(id)arg1 info:(id)arg2;
- (void)_postVideo:(id)arg1 message:(id)arg2 callback:(id)arg3;
- (id)parseVideoResponse:(id)arg1;
- (void)parseVideoResponseXML:(id)arg1 info:(id)arg2;
- (void)postVideoResponse:(id)arg1 info:(id)arg2;
- (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;
- (void)postVideoAuthenticationResponse:(id)arg1 info:(id)arg2;

@end

