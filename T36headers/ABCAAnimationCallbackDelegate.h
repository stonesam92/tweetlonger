/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class ABCallback;

@interface ABCAAnimationCallbackDelegate : NSObject
{
    ABCallback *callback;
}

+ (id)delegateWithCallback:(id)arg1;
- (id)initWithCallback:(id)arg1;
- (void)dealloc;
- (void)animationDidStop:(id)arg1 finished:(BOOL)arg2;

@end

