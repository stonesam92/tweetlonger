/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "UIView.h"

@class NSArray, NSMutableArray;

@interface ABRowView : UIView
{
    id <ABRowViewDelegate> delegate;
    id target;
    SEL action;
    id userInfo;
    BOOL dynamicHeight;
    ABRowView *parentRow;
    NSMutableArray *childRows;
    float rowHeight;
    struct {
        unsigned int selectable:1;
        unsigned int highlighted:1;
        unsigned int selected:1;
        unsigned int deferUpdate:5;
        unsigned int cleanRowHeight:1;
        unsigned int plainSetFrame:1;
        unsigned int fadeNextContentsChange:1;
        unsigned int forceGroupedStyle:1;
    } _flags;
}

+ (id)row;
+ (id)sectionHeader:(id)arg1;
+ (id)spacerRow:(float)arg1;
+ (id)divider:(id)arg1;
+ (id)loadingRow;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;
- (void)dealloc;
@property(nonatomic) BOOL selectable;
- (void)beginChanges;
- (void)endChanges;
@property(readonly, nonatomic) BOOL isFirst;
@property(readonly, nonatomic) BOOL isLast;
@property(readonly, nonatomic) BOOL isGrouped;
@property(readonly, nonatomic) ABRowView *rootRow;
@property(copy, nonatomic) NSArray *childRows;
- (void)_childRowsChanged;
- (id)description;
- (void)_setupFrame:(id)arg1;
- (id)childContainer;
- (void)_add:(id)arg1;
- (void)_remove:(id)arg1;
- (void)_mightHaveRemovedAllChildren;
- (id)addChildRow:(id)arg1;
- (void)removeChildRow:(id)arg1;
- (void)replaceChildRow:(id)arg1 withRow:(id)arg2;
- (float)calculatedRowHeight;
@property(nonatomic) float rowHeight;
- (float)childWidth:(float)arg1;
- (float)xOffset;
- (float)_updateLayout:(float)arg1 width:(float)arg2 xOffset:(float)arg3;
- (void)layoutSubviews;
- (void)updateLayout;
- (void)setFrame:(struct CGRect)arg1;
@property(nonatomic) BOOL highlighted;
@property(nonatomic) BOOL selected;
- (void)setSelected:(BOOL)arg1 animated:(BOOL)arg2;
- (void)setNeedsDisplay;
- (void)_deselectRowsBesides:(id)arg1 animated:(BOOL)arg2;
- (void)deselectAllRowsAnimated:(BOOL)arg1;
- (void)deselectOtherRowsAnimated:(BOOL)arg1;
- (id)actionForLayer:(id)arg1 forKey:(id)arg2;
- (void)setTarget:(id)arg1 action:(SEL)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
@property(nonatomic) BOOL dynamicHeight; // @synthesize dynamicHeight;
@property(nonatomic) ABRowView *parentRow; // @synthesize parentRow;
@property(retain, nonatomic) id userInfo; // @synthesize userInfo;
@property(nonatomic) id <ABRowViewDelegate> delegate; // @synthesize delegate;

@end

