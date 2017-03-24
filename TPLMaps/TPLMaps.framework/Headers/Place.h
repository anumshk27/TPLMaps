//
//  Places.h
//  TPLMapsSearch
//
//  TPL Maps SDK for iOS 17/02/2017.
//  Copyright © 2017 TPL Maps. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Place : NSObject


@property (nonatomic) NSString * area;
@property (nonatomic) NSInteger city_id;
@property (nonatomic) NSString * city_name;
@property (nonatomic) NSString * country;
@property (nonatomic) NSInteger  fkey;
@property (nonatomic) NSInteger  placeId;
@property (nonatomic) float      lat;
@property (nonatomic) float      lng;
@property (nonatomic) NSString * locname;
@property (nonatomic) NSString * province;
@property (nonatomic) NSString * subarea;
@property (nonatomic) NSString * subcategory;
@property (nonatomic) NSInteger subcategory_id;
@property (nonatomic) NSString * type;



- (id)initWithItems:(NSDictionary *)items;
- (NSDictionary *)getAllItems;

/*
 area = "";
 "city_id" = 90004;
 "city_name" = Colombo;
 country = Pakistan;
 fkey = 50000687;
 id = 3899319;
 lat = "6.869968799999951";
 lng = "79.8882835";
 locname = Nugegoda;
 province = Western;
 subarea = "";
 subcategory = location;
 "subcategory_id" = 0;
 type = scale;
 */

@end
