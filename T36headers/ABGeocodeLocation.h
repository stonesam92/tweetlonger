/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class NSString;

@interface ABGeocodeLocation : NSObject
{
    double latitude;
    double longitude;
    int accuracy;
    NSString *address;
}

- (void)dealloc;
- (void)parseXML:(id)arg1 info:(id)arg2;
- (double)accuracyInMeters;
@property(nonatomic) int accuracy; // @synthesize accuracy;
@property(copy, nonatomic) NSString *address; // @synthesize address;
@property(nonatomic) double longitude; // @synthesize longitude;
@property(nonatomic) double latitude; // @synthesize latitude;

@end

