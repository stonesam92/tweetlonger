/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterPadStatusStreamViewController.h"

@class TwitterUser, TwitterUserTimelineStream;

@interface TwitterPadUserFavoritesViewController : TwitterPadStatusStreamViewController
{
    TwitterUser *user;
    TwitterUserTimelineStream *stream;
}

- (void)dealloc;
- (id)statusStream;
- (BOOL)showFilterBar;
@property(retain, nonatomic) TwitterUser *user; // @synthesize user;

@end

