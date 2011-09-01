/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABTableViewCell.h"

@class TwitterAccount, TwitterStatus, UIView;

@interface TweetieStatusCell : ABTableViewCell
{
    id <TweetieStatusCellContextActionDelegate> contextActionDelegate;
    TwitterAccount *account;
    TwitterStatus *status;
    BOOL disableMentionHighlighting;
    UIView *contextModeView;
}

+ (id)textFont;
+ (id)nameFont;
+ (id)dateFont;
+ (struct CGRect)textRectGivenTotalWidth:(float)arg1;
+ (float)heightForStatus:(id)arg1 inTableView:(id)arg2;
- (void)dealloc;
- (void)_animateTransition:(int)arg1;
- (void)beginContextMode;
- (void)endContextMode;
@property(retain, nonatomic) TwitterStatus *status; // @synthesize status;
- (void)userDidUpdateNotification:(id)arg1;
- (void)drawContentView:(struct CGRect)arg1;
@property(nonatomic) BOOL disableMentionHighlighting; // @synthesize disableMentionHighlighting;
@property(nonatomic) id <TweetieStatusCellContextActionDelegate> contextActionDelegate; // @synthesize contextActionDelegate;
@property(retain, nonatomic) TwitterAccount *account; // @synthesize account;

@end

