/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "UIViewController.h"

#import "ABTableViewPinchPreview-Protocol.h"
#import "UIActionSheetDelegate-Protocol.h"
#import "UITableViewDataSource-Protocol.h"
#import "UITableViewDelegate-Protocol.h"

@class ABTableViewPinchPreviewController, ABTableViewPullToRefreshController, ABTableViewStayOnScreenController, NSArray, NSString, SearchRowView, TwitterAccount, TwitterPadTweetViewController, TwitterStatus, UITableView, UIWindow;

@interface TwitterPadStatusListViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, ABTableViewPinchPreview, UIActionSheetDelegate>
{
    TwitterAccount *account;
    UITableView *_tableView;
    UIWindow *pinchWindow;
    NSArray *statuses;
    NSArray *_setStatusesOnEndScrolling;
    TwitterStatus *longPressTweet;
    NSString *longPressString;
    SearchRowView *searchHeader;
    TwitterPadTweetViewController *currentPinchTweetViewController;
    ABTableViewPullToRefreshController *pullToRefreshController;
    ABTableViewStayOnScreenController *stayOnScreenController;
    ABTableViewPinchPreviewController *pinchPreviewController;
}

- (void)_resetSubviews;
- (void)dealloc;
- (BOOL)showFilterBar;
- (BOOL)canPullToRefresh;
- (void)ab_scrollToTop;
- (BOOL)showToolbar;
- (id)toolbarView;
- (void)loadView;
- (void)viewDidUnload;
- (void)viewDidAppear:(BOOL)arg1;
- (void)viewWillDisappear:(BOOL)arg1;
- (void)loadOlder:(id)arg1;
- (void)loadNewer:(id)arg1;
- (void)fillInGap:(id)arg1;
- (void)viewedMostRecent:(id)arg1;
- (BOOL)isLoadingNewer;
- (BOOL)canSetStatuses;
@property(retain, nonatomic) NSArray *statuses; // @synthesize statuses;
- (void)scrollViewDidScroll:(id)arg1;
- (void)_setPendingStatusesIfNeeded;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(BOOL)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndScrollingAnimation:(id)arg1;
- (BOOL)pinchPreviewController:(id)arg1 willStartPreviewForCell:(id)arg2;
- (id)pinchPreviewController:(id)arg1 viewControllerForCell:(id)arg2;
- (id)pinchPreviewController:(id)arg1 containerViewForPinchedCell:(id)arg2;
- (id)pinchPreviewController:(id)arg1 footerFlapControllerForPinchedCell:(id)arg2;
- (id)pinchPreviewController:(id)arg1 headerFlapForPinchedCell:(id)arg2;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)_selectItemWithoutNavigating:(id)arg1;
- (id)indexPathForItem:(id)arg1;
- (void)pullToRefreshController:(id)arg1 didActivate:(BOOL)arg2;
- (void)ab_willPopToRightColumn;
- (void)twitterPadTableViewDidChangeFrame:(id)arg1;
- (void)_viewStatus:(id)arg1 linkRange:(id)arg2;
- (void)_didTapLink:(id)arg1 info:(id)arg2;
- (void)twitterStatusCell:(id)arg1 didTapLink:(id)arg2;
- (void)twitterStatusCell:(id)arg1 didLongPressLink:(id)arg2;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(int)arg2;
- (id)indexPathForStatusWithID:(id)arg1;
- (float)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)ab_didPopDetails;
- (void)twitterStatusCellDidTapBody:(id)arg1;
- (void)twitterStatusCellDidTapAvatar:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)autosaveName;
- (void)saveScrollPosition;
- (void)restoreScrollPosition;
@property(retain, nonatomic) TwitterPadTweetViewController *currentPinchTweetViewController; // @synthesize currentPinchTweetViewController;
@property(retain, nonatomic) TwitterAccount *account; // @synthesize account;

@end

