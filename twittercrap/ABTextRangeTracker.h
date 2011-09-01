/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSArray, NSMutableArray, NSMutableString;

@interface ABTextRangeTracker : NSObject
{
    id <ABTextRangeTrackerDelegate> delegate;
    NSMutableString *text;
    NSMutableArray *ranges;
}

- (id)init;
- (void)dealloc;
- (void)_deleteRange:(struct _NSRange)arg1;
- (void)_insertText:(id)arg1 atIndex:(int)arg2;
- (void)updateTextInRange:(struct _NSRange)arg1 withText:(id)arg2;
- (void)removeTextRange:(id)arg1;
- (void)addTextRange:(id)arg1;
- (void)addRange:(struct _NSRange)arg1 info:(id)arg2;
- (BOOL)textRangeExistsAtRange:(struct _NSRange)arg1;
@property(readonly, nonatomic) NSArray *ranges;

@end

