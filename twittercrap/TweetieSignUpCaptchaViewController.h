/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABStaticTableViewController.h"

@class ABCallback, NSString, NSURL, UIImage, UITextField, UIView;

@interface TweetieSignUpCaptchaViewController : ABStaticTableViewController
{
    NSString *captchaToken;
    NSURL *captchaImageURL;
    UIImage *captchaImage;
    UIView *header;
    UITextField *_solutionField;
    ABCallback *callback;
    CDStruct_1b8233f7 _flags;
}

- (void)dealloc;
@property(retain, nonatomic) UIImage *captchaImage; // @synthesize captchaImage;
- (void)handleImage:(id)arg1 info:(id)arg2;
- (void)loadTableView;
- (void)viewDidLoad;
- (BOOL)shouldAutorotateToInterfaceOrientation:(int)arg1;
- (void)viewDidAppear:(BOOL)arg1;
- (void)cancel:(id)arg1;
- (void)done:(id)arg1;
@property(retain, nonatomic) ABCallback *callback; // @synthesize callback;
@property(retain, nonatomic) NSURL *captchaImageURL; // @synthesize captchaImageURL;
@property(retain, nonatomic) NSString *captchaToken; // @synthesize captchaToken;

@end

