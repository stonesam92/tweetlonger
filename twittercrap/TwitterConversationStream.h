/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterAccountStream.h"

#import "NSCoding-Protocol.h"

@class TwitterStatus;

@interface TwitterConversationStream : TwitterAccountStream <NSCoding>
{
    TwitterStatus *baseStatus;
    TwitterStatus *_nextStatus;
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)getNext;
- (void)handleStatus:(id)arg1;
- (void)gotNext:(id)arg1 info:(id)arg2;
@property(nonatomic) TwitterStatus *baseStatus; // @synthesize baseStatus;
- (void)_loadNewer;
- (void)_loadOlder;
- (BOOL)supportsFillingInGaps;
- (id)autosaveName;

@end

