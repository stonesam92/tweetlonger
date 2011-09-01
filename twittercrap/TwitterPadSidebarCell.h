/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABTableViewCell.h"

@class TwitterAccount, TwitterPadSidebarViewController;

@interface TwitterPadSidebarCell : ABTableViewCell
{
    TwitterAccount *account;
    TwitterPadSidebarViewController *delegate;
}

- (id)initWithStyle:(int)arg1 reuseIdentifier:(id)arg2;
- (void)dealloc;
- (BOOL)associatedAccountIsSelected;
- (BOOL)isFirst;
- (BOOL)isLast;
- (void)drawContentView:(struct CGRect)arg1;
@property(nonatomic) TwitterPadSidebarViewController *delegate; // @synthesize delegate;
@property(retain, nonatomic) TwitterAccount *account; // @synthesize account;

@end

