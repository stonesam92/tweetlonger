/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSDateFormatter, NSDictionary, NSMutableArray, NSMutableString, NSString;

@interface ABXMLParser : NSObject
{
    NSMutableArray *errors;
    NSMutableArray *callbacks;
    NSMutableString *_characters;
    BOOL canPushCallback;
    BOOL didPushCallback;
    NSString *elementName;
    NSDictionary *attributes;
    NSDateFormatter *httpLikeDateFormatter;
}

+ (id)parseData:(id)arg1 withCallback:(id)arg2;
- (id)init;
- (void)dealloc;
- (id)parseData:(id)arg1 withCallback:(id)arg2;
- (void)pushCallback:(id)arg1 repeatElement:(BOOL)arg2;
- (void)ignoreTag;
@property(readonly, nonatomic) NSString *characters;
- (void)startElement:(id)arg1 attributes:(id)arg2;
- (void)endElement:(id)arg1;
- (void)characters:(id)arg1;
- (void)error:(id)arg1;
- (BOOL)boolAttributeForKey:(id)arg1;
- (id)httpLikeDate;
@property(readonly, nonatomic) NSDictionary *attributes; // @synthesize attributes;
@property(readonly, nonatomic) NSString *elementName; // @synthesize elementName;

@end

