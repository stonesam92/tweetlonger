/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

#import "UIActionSheetDelegate-Protocol.h"

@class ABCallback, TwitterAccount, TwitterStatus, UIActionSheet, UINavigationController;

@interface TweetieStatusActions : NSObject <UIActionSheetDelegate>
{
    UIActionSheet *_retweetSheet;
    UIActionSheet *_actionSheet;
    UIActionSheet *_deleteSheet;
    TwitterStatus *status;
    TwitterAccount *account;
    UINavigationController *navigationController;
    ABCallback *onDelete;
}

+ (void)reply:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
+ (void)link:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3 showOpenButton:(BOOL)arg4;
+ (void)user:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
+ (void)favorite:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
+ (void)delete:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3 onDelete:(id)arg4;
+ (void)retweet:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
+ (void)action:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
+ (void)translationResponse:(id)arg1 info:(id)arg2;
+ (id)emailBodyForStatuses:(id)arg1 subject:(id *)arg2;
+ (void)sendEmailWithStatuses:(id)arg1 fromNavigationController:(id)arg2;
- (void)dealloc;
- (void)delete:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3 onDelete:(id)arg4;
- (void)retweet:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
- (void)action:(id)arg1 account:(id)arg2 sourceNavigationController:(id)arg3;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(int)arg2;

@end

