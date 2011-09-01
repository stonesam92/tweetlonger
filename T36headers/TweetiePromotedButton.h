/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "UIButton.h"

@class ABCallback;

@interface TweetiePromotedButton : UIButton
{
    ABCallback *callback;
}

+ (id)textColor;
+ (id)textShadowColor;
+ (id)font;
+ (id)promotedLabelAt:(struct CGPoint)arg1 callback:(id)arg2;
- (void)didClickPromotedLabel:(id)arg1;
- (void)fitText;
- (void)drawRect:(struct CGRect)arg1;
- (void)dealloc;
@property(retain, nonatomic) ABCallback *callback; // @synthesize callback;

@end

