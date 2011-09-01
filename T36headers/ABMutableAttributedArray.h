/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSMutableArray.h"

@class NSMutableDictionary;

@interface ABMutableAttributedArray : NSMutableArray
{
    NSMutableArray *_array;
    NSMutableDictionary *userInfo;
}

- (id)init;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned int)arg1;
- (void)insertObject:(id)arg1 atIndex:(unsigned int)arg2;
- (void)removeObjectAtIndex:(unsigned int)arg1;
- (void)addObject:(id)arg1;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(unsigned int)arg1 withObject:(id)arg2;
@property(retain, nonatomic) NSMutableDictionary *userInfo; // @synthesize userInfo;
@property(retain, nonatomic) NSMutableArray *_array; // @synthesize _array;

@end

