/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@class ABCallback, ABStaticTableViewController, NSString;

@interface ABStaticTableViewElement : NSObject
{
    id userInfo;
    NSString *title;
    NSString *subtitle;
    id target;
    SEL action;
    ABStaticTableViewController *associatedViewController;
    ABCallback *callback;
    float height;
}

+ (id)element;
- (void)performCallback:(id)arg1;
- (void)dealloc;
@property(readonly, nonatomic) BOOL isSelectable;
- (float)heightInTableView:(id)arg1;
- (id)cellForTableView:(id)arg1;
- (void)didSelectInTableView:(id)arg1;
- (void)willSelectInTableView:(id)arg1;
- (void)didTapAccessoryInTableView:(id)arg1;
@property(nonatomic) float height; // @synthesize height;
@property(retain, nonatomic) ABCallback *callback; // @synthesize callback;
@property(nonatomic) ABStaticTableViewController *associatedViewController; // @synthesize associatedViewController;
@property(retain, nonatomic) id userInfo; // @synthesize userInfo;
@property(nonatomic) SEL action; // @synthesize action;
@property(nonatomic) id target; // @synthesize target;
@property(copy, nonatomic) NSString *subtitle; // @synthesize subtitle;
@property(copy, nonatomic) NSString *title; // @synthesize title;

@end

