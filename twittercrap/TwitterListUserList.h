/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSArray, NSString, TwitterList;

@interface TwitterListUserList : NSObject
{
    TwitterList *list;
    NSString *nextCursor;
    NSString *previousCursor;
    NSArray *users;
}

- (void)dealloc;
@property(copy, nonatomic) NSArray *users; // @synthesize users;
@property(retain, nonatomic) NSString *previousCursor; // @synthesize previousCursor;
@property(retain, nonatomic) NSString *nextCursor; // @synthesize nextCursor;
@property(nonatomic) TwitterList *list; // @synthesize list;

@end

