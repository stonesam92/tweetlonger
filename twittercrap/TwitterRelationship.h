/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSString;

@interface TwitterRelationship : NSObject
{
    NSString *username;
    BOOL following;
    BOOL followedBy;
}

+ (id)relationshipsWithXML:(id)arg1;
+ (void)parseRelationshipsXML:(id)arg1 info:(id)arg2;
- (void)parseRelationshipXML:(id)arg1 info:(id)arg2;
- (id)description;
@property(nonatomic) BOOL followedBy; // @synthesize followedBy;
@property(nonatomic) BOOL following; // @synthesize following;
@property(retain, nonatomic) NSString *username; // @synthesize username;

@end

