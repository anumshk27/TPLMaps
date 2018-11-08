//
//  Places.h
//  TPLMapsSearch
//
//  TPL Maps SDK for iOS 17/02/2017.
//  Copyright © 2017 Muhammad Anum. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Place : NSObject

@property (nonatomic) NSString * country;
@property (nonatomic) NSString * type;
@property (nonatomic) NSString * address;
@property (nonatomic) NSString * name;
@property (nonatomic) NSString * subarea;//parent2
@property (nonatomic) NSString * area;//parent3

@property (nonatomic) NSInteger  uid;
@property (nonatomic) NSInteger  fkey;
@property (nonatomic) NSInteger  priority;
@property (nonatomic) NSInteger  popularity;

@property (nonatomic) double  lat;
@property (nonatomic) double  lng;


- (id)initWithItems:(NSDictionary *)items;
- (NSDictionary *)getAllItems;


@end
