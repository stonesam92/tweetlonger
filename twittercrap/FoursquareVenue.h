/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class FoursquareUser, NSMutableArray, NSString;

@interface FoursquareVenue : NSObject
{
    NSString *venueID;
    NSString *name;
    NSString *address;
    NSString *crossStreet;
    NSString *city;
    NSString *state;
    NSString *zip;
    NSString *phone;
    NSString *twitter;
    double latitude;
    double longitude;
    int numberOfCheckins;
    FoursquareUser *mayor;
    NSMutableArray *checkins;
    NSMutableArray *tips;
    NSMutableArray *specials;
}

- (void)dealloc;
- (id)_ab_improved_description_body;
- (id)description;
- (void)parseXML:(id)arg1 info:(id)arg2;
- (void)parseVenueXML:(id)arg1 info:(id)arg2;
- (void)parseStatsXML:(id)arg1 info:(id)arg2;
- (void)parseMayorXML:(id)arg1 info:(id)arg2;
@property(retain, nonatomic) FoursquareUser *mayor; // @synthesize mayor;
@property(nonatomic) int numberOfCheckins; // @synthesize numberOfCheckins;
@property(nonatomic) double longitude; // @synthesize longitude;
@property(nonatomic) double latitude; // @synthesize latitude;
@property(retain, nonatomic) NSString *twitter; // @synthesize twitter;
@property(retain, nonatomic) NSString *phone; // @synthesize phone;
@property(retain, nonatomic) NSString *zip; // @synthesize zip;
@property(retain, nonatomic) NSString *state; // @synthesize state;
@property(retain, nonatomic) NSString *city; // @synthesize city;
@property(retain, nonatomic) NSString *crossStreet; // @synthesize crossStreet;
@property(retain, nonatomic) NSString *address; // @synthesize address;
@property(retain, nonatomic) NSString *name; // @synthesize name;
@property(retain, nonatomic) NSString *venueID; // @synthesize venueID;

@end

