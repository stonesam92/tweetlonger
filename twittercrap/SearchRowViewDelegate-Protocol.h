/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject-Protocol.h"

@protocol SearchRowViewDelegate <NSObject>
- (id)account;
- (void)searchRowViewDidBegin:(id)arg1;
- (void)searchRowViewDidCancel:(id)arg1;
- (void)searchFor:(id)arg1;
- (void)searchNearby:(id)arg1 coordinates:(CDStruct_2c43369c)arg2;
- (void)gotoUsername:(id)arg1;
- (void)gotoUser:(id)arg1;
@end

