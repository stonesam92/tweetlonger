/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "TwitterStatus.h"

@interface TwitterStatus (JSON)
+ (void)parseStatusesJSON:(id)arg1 info:(id)arg2;
+ (void)parsePromotedStatusJSON:(id)arg1 info:(id)arg2;
+ (void)parseStatusJSON:(id)arg1 info:(id)arg2;
+ (void)parseSearchJSON:(id)arg1 info:(id)arg2;
+ (void)parseSearchStatusesJSON:(id)arg1 info:(id)arg2;
- (void)parseStatusJSON:(id)arg1 info:(id)arg2;
- (id)_partialFromUser;
- (void)parseStatusSearchJSON:(id)arg1 info:(id)arg2;
- (void)parseMetadataJSON:(id)arg1 info:(id)arg2;
@end

