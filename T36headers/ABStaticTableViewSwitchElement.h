/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABStaticTableViewElement.h"

@class NSString;

@interface ABStaticTableViewSwitchElement : ABStaticTableViewElement
{
    NSString *key;
    BOOL on;
    BOOL invert;
}

- (void)dealloc;
- (void)performCallback:(id)arg1;
- (BOOL)isSelectable;
- (BOOL)hasValidKey;
- (BOOL)switchValue;
- (id)cellForTableView:(id)arg1;
- (void)switchAction:(id)arg1;
@property(nonatomic) BOOL on; // @synthesize on;
@property(nonatomic) BOOL invert; // @synthesize invert;
@property(copy, nonatomic) NSString *key; // @synthesize key;

@end

