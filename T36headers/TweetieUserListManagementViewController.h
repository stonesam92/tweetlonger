/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABStaticTableViewController.h"

@class ABCallback, NSMutableDictionary, TwitterAccount, TwitterUser;

@interface TweetieUserListManagementViewController : ABStaticTableViewController
{
    TwitterAccount *account;
    TwitterUser *user;
    ABCallback *dismissCallback;
    NSMutableDictionary *perListFollowsUserDictionary;
}

- (id)init;
- (void)dealloc;
- (id)_keyForList:(id)arg1;
- (int)_isFollowedByList:(id)arg1;
- (void)loadTableView;
- (void)viewDidLoad;
- (void)viewDidAppear:(BOOL)arg1;
- (void)viewWillDisappear:(BOOL)arg1;
- (void)listsDidUpdate:(id)arg1;
- (void)listDoesFollowUserResponse:(id)arg1 info:(id)arg2;
- (void)didCheckmarkElement:(id)arg1;
- (void)done:(id)arg1;
@property(retain, nonatomic) ABCallback *dismissCallback; // @synthesize dismissCallback;
@property(retain, nonatomic) TwitterUser *user; // @synthesize user;
@property(retain, nonatomic) TwitterAccount *account; // @synthesize account;

@end

