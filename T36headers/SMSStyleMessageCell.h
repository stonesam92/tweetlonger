/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "ABTableViewCell.h"

#import "ABUITextRendererDelegate-Protocol.h"

@class ABUITextRenderer, NSAttributedString, NSDate, NSObject<TouchAndHoldCellDelegate>, NSString, TwitterDirectMessage, UIImage;

@interface SMSStyleMessageCell : ABTableViewCell <ABUITextRendererDelegate>
{
    ABUITextRenderer *renderer;
    id <ABActiveTextRange> touchedActiveRange;
    TwitterDirectMessage *message;
    NSString *nameText;
    NSString *messageText;
    UIImage *image;
    NSDate *date;
    NSObject<TouchAndHoldCellDelegate> *delegate;
    BOOL mine;
    BOOL selected;
}

+ (id)messageFont;
+ (id)nameFont;
+ (struct CGRect)messageRectForWidth:(float)arg1;
+ (struct CGSize)sizeForMessage:(id)arg1 maxWidth:(float)arg2;
+ (float)heightForMessage:(id)arg1 inTableView:(id)arg2 error:(BOOL)arg3;
- (BOOL)hasError;
- (void)dealloc;
@property(retain, nonatomic) NSAttributedString *attributedMessageText;
- (id)activeRangesForTextRenderer:(id)arg1;
- (struct CGRect)imageRect;
- (float)errorPadding;
- (struct CGRect)_bubbleRect:(struct CGSize)arg1;
- (struct CGRect)bubbleRect;
- (struct CGSize)textSize;
- (void)drawContentView:(struct CGRect)arg1;
- (id)timeStampString;
- (void)touchAndHold:(id)arg1;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)didTapActiveRange:(id)arg1;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
@property(nonatomic) BOOL selected; // @synthesize selected;
@property(nonatomic) NSObject<TouchAndHoldCellDelegate> *delegate; // @synthesize delegate;
@property(nonatomic) BOOL mine; // @synthesize mine;
@property(retain, nonatomic) NSDate *date; // @synthesize date;
@property(retain, nonatomic) UIImage *image; // @synthesize image;
@property(retain, nonatomic) NSString *messageText; // @synthesize messageText;
@property(retain, nonatomic) NSString *nameText; // @synthesize nameText;
@property(retain, nonatomic) id <ABActiveTextRange> touchedActiveRange; // @synthesize touchedActiveRange;
@property(retain, nonatomic) TwitterDirectMessage *message; // @synthesize message;

@end

