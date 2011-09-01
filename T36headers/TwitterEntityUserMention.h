/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterEntity.h"

@class NSString;

@interface TwitterEntityUserMention : TwitterEntity
{
    NSString *fullName;
    NSString *username;
    NSString *userID;
}

+ (void)parseEntityXML:(id)arg1 info:(id)arg2;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (void)parseEntityJSON:(id)arg1 info:(id)arg2;
- (void)parseDict:(id)arg1;
- (id)displayString;
- (int)rangeFlavor;
- (id)description;
@property(retain, nonatomic) NSString *userID; // @synthesize userID;
@property(retain, nonatomic) NSString *username; // @synthesize username;
@property(retain, nonatomic) NSString *fullName; // @synthesize fullName;

@end

