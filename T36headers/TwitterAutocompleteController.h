/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

#import "ABAutocompleteTableViewDelegate-Protocol.h"
#import "UIPopoverControllerDelegate-Protocol.h"

@class ABAutocompletePopover, ABAutocompleteView, NSMutableSet, TwitterAccount, TwitterAutocompleteResultsController, TwitterComposition, UINavigationController, UITextView;

@interface TwitterAutocompleteController : NSObject <ABAutocompleteTableViewDelegate, UIPopoverControllerDelegate>
{
    id <ABAutocompleteControllerDelegate><ABPlacePickerDelegate> delegate;
    UITextView *_textView;
    TwitterComposition *_composition;
    TwitterAccount *_account;
    NSMutableSet *_fastPrefixStartSet;
    BOOL isMatchingWord;
    int savedAutocorrectionType;
    int savedAutocapitalizationType;
    UINavigationController *navigationController;
    ABAutocompletePopover *autocompletePopover;
    ABAutocompleteView *autocompleteView;
    TwitterAutocompleteResultsController *resultsController;
    BOOL forcedPlaceAutocomplete;
    BOOL forcedNameAutocomplete;
    BOOL forcedHashtagAutocomplete;
    int autocompleteStartIndex;
    int autocompleteType;
}

- (id)init;
- (id)initWithTextView:(id)arg1 composition:(id)arg2 account:(id)arg3;
- (id)initWithFrame:(struct CGRect)arg1 textView:(id)arg2 composition:(id)arg3 account:(id)arg4;
- (void)dealloc;
- (BOOL)popoverControllerShouldDismissPopover:(id)arg1;
- (void)updateFastPrefixStartSet:(id)arg1;
- (id)resultsTableView;
- (void)autocompleteResults:(id)arg1 info:(id)arg2;
- (void)_end;
- (void)_updateResults:(id)arg1;
- (void)didChangeSelection;
- (void)_startOrUpdate;
- (void)_forceAutoComplete;
- (void)forceEnablePlaceAutocomplete;
- (void)forceEnableNameAutocomplete;
- (void)forceEnableHashtagAutocomplete;
- (id)wordAtIndex:(int)arg1;
- (BOOL)wordIsPlaceTrigger:(id)arg1;
- (BOOL)_couldBeAPlainWordMatch:(id)arg1;
- (void)_updateAutocompleter:(id)arg1;
- (void)textViewDidChange:(id)arg1;
- (struct _NSRange)insertAutocompleteItem:(id)arg1 atRange:(struct _NSRange)arg2;
- (void)didSelectAutocompleteItem:(id)arg1;
- (void)foundUsers:(id)arg1 info:(id)arg2;
- (void)foundPlaces:(id)arg1 searchQuery:(id)arg2;
@property(readonly, nonatomic) ABAutocompletePopover *autocompletePopover; // @synthesize autocompletePopover;
@property(readonly, nonatomic) ABAutocompleteView *autocompleteView; // @synthesize autocompleteView;
@property(nonatomic) UINavigationController *navigationController; // @synthesize navigationController;
@property(nonatomic) id <ABAutocompleteControllerDelegate><ABPlacePickerDelegate> delegate; // @synthesize delegate;

@end

