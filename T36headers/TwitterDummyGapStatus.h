/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterDummyStatus.h"

@interface TwitterDummyGapStatus : TwitterDummyStatus
{
    struct {
        unsigned int isLoading:1;
        unsigned int shouldRemove:1;
    } _gapFlags;
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (BOOL)isGap;
- (BOOL)isEqual:(id)arg1;
@property(nonatomic) BOOL loading;
- (BOOL)_shouldFilterOutOfStream;

@end

