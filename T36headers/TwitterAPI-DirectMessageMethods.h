/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterAPI.h"

@interface TwitterAPI (DirectMessageMethods)
- (id)directMessageResponseCallback;
- (id)directMessagesResponseCallback;
- (void)directMessagesSinceID:(id)arg1 maxID:(id)arg2 page:(id)arg3;
- (void)sentDirectMessagesSinceID:(id)arg1 maxID:(id)arg2 page:(id)arg3;
- (void)send:(id)arg1 toUserID:(id)arg2;
- (void)send:(id)arg1 toUsername:(id)arg2;
- (void)directMessageResponse:(id)arg1 info:(id)arg2;
- (void)destroyDirectMessage:(id)arg1;
- (void)directMessagesResponse:(id)arg1 info:(id)arg2;
@end

