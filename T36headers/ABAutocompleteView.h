/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "UIView.h"

@class ABAutocompleteTableView, UITextView;

@interface ABAutocompleteView : UIView
{
    UITextView *textView;
    ABAutocompleteTableView *_tableView;
    BOOL autocompleting;
}

- (id)initWithFrame:(struct CGRect)arg1;
@property(readonly, nonatomic) ABAutocompleteTableView *tableView;
- (void)_scrollSelectionToVisible;
- (BOOL)updateAutocomplete;
- (BOOL)endAutocomplete;
@property(nonatomic) UITextView *textView; // @synthesize textView;

@end

