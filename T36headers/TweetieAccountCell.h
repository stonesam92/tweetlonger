/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "UITableViewCell.h"

@class TwitterAccount;

@interface TweetieAccountCell : UITableViewCell
{
    TwitterAccount *account;
}

- (void)updateProfileImage;
- (void)willTransitionToState:(unsigned int)arg1;
@property(nonatomic) TwitterAccount *account; // @synthesize account;

@end

