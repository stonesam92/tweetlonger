/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABStaticTableViewElement.h"

@class NSString, UIImage;

@interface ABStaticTableViewSliderElement : ABStaticTableViewElement
{
    NSString *key;
    UIImage *leftImage;
    UIImage *rightImage;
}

- (void)dealloc;
- (BOOL)isSelectable;
- (id)cellForTableView:(id)arg1;
@property(retain, nonatomic) UIImage *rightImage; // @synthesize rightImage;
@property(retain, nonatomic) UIImage *leftImage; // @synthesize leftImage;
@property(copy, nonatomic) NSString *key; // @synthesize key;

@end

