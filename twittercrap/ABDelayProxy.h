/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABProxy.h"

@interface ABDelayProxy : ABProxy
{
    double delay;
}

- (void)forwardInvocation:(id)arg1;
- (void)performInvocationAfterDelay:(id)arg1;
@property(nonatomic) double delay; // @synthesize delay;

@end

