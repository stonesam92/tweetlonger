/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject-Protocol.h"

@protocol ABNetworkImageViewDelegate <NSObject>

@optional
- (void)networkImageViewDidLoadImage:(id)arg1;
- (void)networkImageView:(id)arg1 loadingProgress:(float)arg2;
- (void)networkImageView:(id)arg1 errorLoadingImage:(id)arg2;
@end

