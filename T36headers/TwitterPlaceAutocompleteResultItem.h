/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterAutocompleteResultItem.h"

@interface TwitterPlaceAutocompleteResultItem : TwitterAutocompleteResultItem
{
    int placeType;
    double latitude;
    double longitude;
}

+ (id)itemWithID:(id)arg1 placeType:(int)arg2 autocompleteText:(id)arg3 subtext:(id)arg4 priority:(int)arg5 latitude:(id)arg6 longitude:(id)arg7;
+ (id)itemWithPlace:(id)arg1;
@property(nonatomic) double longitude; // @synthesize longitude;
@property(nonatomic) double latitude; // @synthesize latitude;
@property(nonatomic) int placeType; // @synthesize placeType;

@end

