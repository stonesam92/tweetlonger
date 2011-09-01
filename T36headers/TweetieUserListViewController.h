/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABSearchableTableViewController.h"

@class NSArray, NSMutableArray, NSMutableSet, TwitterAccount;

@interface TweetieUserListViewController : ABSearchableTableViewController
{
    TwitterAccount *account;
    NSArray *searchUsers;
    NSArray *nonSearchUsers;
    NSArray *filteredUsers;
    NSMutableSet *simpleFollowSet;
    NSMutableArray *_followButtons;
    float currentProgress;
    struct {
        unsigned int mode:3;
        unsigned int isShowingSearchResults:1;
    } _flags;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(int)arg1;
- (id)init;
- (void)dealloc;
- (id)persistentProxy;
- (void)decodeWithPersistentProxy:(id)arg1;
- (id)arbitraryUserFormatString;
- (id)placeholderSearchStringForFilterBar;
- (BOOL)showComposeButton;
- (void)viewDidLoad;
- (void)compose:(id)arg1;
- (void)viewWillDisappear:(BOOL)arg1;
- (void)viewWillAppear:(BOOL)arg1;
- (void)loadMore:(id)arg1;
- (id)userForRow:(int)arg1;
- (void)searchDisplayController:(id)arg1 didLoadSearchResultsTableView:(id)arg2;
- (BOOL)couldBeUsername;
- (BOOL)searchDisplayController:(id)arg1 shouldReloadTableForSearchString:(id)arg2;
- (void)searchDisplayControllerDidBeginSearch:(id)arg1;
- (void)searchDisplayControllerWillEndSearch:(id)arg1;
- (id)usernameFromSearchText;
- (int)numberOfSectionsInTableView:(id)arg1;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (void)_updateButtonTitle:(id)arg1 animated:(BOOL)arg2;
- (void)follow_unfollow:(id)arg1;
- (void)updateButtonTitlesForUsernames:(id)arg1;
- (void)userDidFollow:(id)arg1;
- (void)userDidUnfollow:(id)arg1;
- (void)disableButtons;
- (void)enableButtons;
- (id)tableView:(id)arg1 cellForUser:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)selectUser:(id)arg1;
- (void)selectUsername:(id)arg1;
- (BOOL)automaticallyDeselect;
- (void)findUsers;
- (void)browseSUL;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)_returnToFilteringMode;
- (void)findUsersResponse:(id)arg1 info:(id)arg2;
- (void)searchBarSearchButtonClicked:(id)arg1;
@property(nonatomic) float currentProgress; // @synthesize currentProgress;
@property(retain, nonatomic) NSMutableSet *simpleFollowSet; // @synthesize simpleFollowSet;
@property(retain, nonatomic) NSArray *filteredUsers; // @synthesize filteredUsers;
@property(retain, nonatomic) NSArray *nonSearchUsers; // @synthesize nonSearchUsers;
@property(retain, nonatomic) NSArray *searchUsers; // @synthesize searchUsers;
@property(retain, nonatomic) TwitterAccount *account; // @synthesize account;

@end

