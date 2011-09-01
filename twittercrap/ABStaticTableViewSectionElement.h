/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABStaticTableViewElement.h"

@class ABStaticTableViewExpandDisclosureElement, NSMutableArray, NSString;

@interface ABStaticTableViewSectionElement : ABStaticTableViewElement
{
    NSMutableArray *elements;
    NSString *footerText;
    BOOL collapsed;
    ABStaticTableViewExpandDisclosureElement *collapsedDisclosureElement;
}

- (void)dealloc;
- (void)addElement:(id)arg1;
- (int)replaceElement:(id)arg1 withElement:(id)arg2;
- (id)elements;
- (void)removeAllElements;
- (void)expandSection:(id)arg1;
- (void)collapseSection:(id)arg1;
@property(retain, nonatomic) ABStaticTableViewExpandDisclosureElement *collapsedDisclosureElement; // @synthesize collapsedDisclosureElement;
@property(nonatomic) BOOL collapsed; // @synthesize collapsed;
@property(copy, nonatomic) NSString *footerText; // @synthesize footerText;

@end

