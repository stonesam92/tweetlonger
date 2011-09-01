/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSArray, NSString, TwitterUser;

@interface TwitterUserRecommendation : NSObject
{
    TwitterUser *user;
    NSString *token;
    NSArray *connections;
}

+ (id)parseRecommendationsXML:(id)arg1;
+ (void)parseRecommendationsXML:(id)arg1 info:(id)arg2;
- (void)dealloc;
- (id)description;
- (void)parseRecommendationXML:(id)arg1 info:(id)arg2;
@property(retain, nonatomic) NSArray *connections; // @synthesize connections;
@property(retain, nonatomic) NSString *token; // @synthesize token;
@property(retain, nonatomic) TwitterUser *user; // @synthesize user;

@end

