/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABTableViewCell.h"

@class TwitterStatus;

@interface TwitterStatusCell : ABTableViewCell
{
    TwitterStatus *status;
    id delegate;
}

- (Class)cellViewClass;
- (void)dealloc;
@property(retain, nonatomic) TwitterStatus *status; // @synthesize status;
- (void)userDidUpdate:(id)arg1;
- (id)ab_copyForStayOnScreen:(BOOL)arg1;
@property(nonatomic) id delegate; // @synthesize delegate;

@end

