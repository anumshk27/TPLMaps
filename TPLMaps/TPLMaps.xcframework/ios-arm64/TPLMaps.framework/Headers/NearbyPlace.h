//
//  NearbyPlace.h
//  TPLMaps
//
//  Created by Haider Shahzad on 03/03/2023.
//  Copyright © 2023 TPLMaps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 NearbyPlace object holds the required information about place near by 
 */
@interface NearbyPlace : NSObject

@property (nonatomic) NSString *division;

/**
 The complete address of the local entity.
 */
@property (nonatomic) NSString *address;

/**
 The province of the local entity.
 */
@property (nonatomic) NSString *province;

/**
 The city of the local entity.
 */
@property (nonatomic) NSString *city;

/**
 The street of the local entity.
 */
@property (nonatomic) NSString *street;

/**
 The district of the local entity.
 */
@property (nonatomic) NSString *district;

/**
 The tehsil of the local entity.
 */
@property (nonatomic) NSString *tehsil;

/**
 The sector of the local entity.
 */
@property (nonatomic) NSString *sector;

/**
 Initilize NearbyPlace object with NSDictionary
 */

- (id)initWithItems:(NSDictionary *)items;

/**
 Provide NSDictionary from NearbyPlace object
 */
- (NSDictionary *)getAllItems;

@end

NS_ASSUME_NONNULL_END
