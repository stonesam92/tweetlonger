/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TweetieAbstractSearchController.h"

@class NSArray;

@interface TweetieSearchPeopleController : TweetieAbstractSearchController
{
    NSArray *cachedUsers;
    NSArray *matchingUsers;
    NSArray *searchResults;
    struct {
        unsigned int mode:3;
    } _flags;
}

- (void)dealloc;
- (BOOL)couldBeUsername;
- (id)usersMatching:(id)arg1;
- (id)matchingUsers;
- (void)updateMatchingUsers;
- (void)searchBar:(id)arg1 textDidChange:(id)arg2;
- (int)numberOfSectionsInTableView:(id)arg1;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)findUsers;
- (void)_returnToRecentsMode;
- (void)findUsersResponse:(id)arg1 info:(id)arg2;
- (void)searchBarSearchButtonClicked:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (float)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;

@end

