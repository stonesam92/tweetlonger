/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterAccountStream.h"

@class TwitterList;

@interface TwitterListStream : TwitterAccountStream
{
    TwitterList *list;
}

- (void)_loadNewer;
- (void)_loadBeforeGap:(id)arg1;
- (void)_loadOlder;
- (id)autosaveName;
@property(nonatomic) TwitterList *list; // @synthesize list;

@end

