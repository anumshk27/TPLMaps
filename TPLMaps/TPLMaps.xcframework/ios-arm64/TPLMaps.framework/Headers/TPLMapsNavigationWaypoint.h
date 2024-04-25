//
//  DestinationObj.h
//  TPLMaps
//
//  Created by Haider Shahzad on 13/03/2024.
//  Copyright © 2024 TPLMaps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM (NSUInteger, PointType) {
    CURRENT_LOCATION = 0,
    START_POINT,
    END_POINT
};

@interface TPLMapsNavigationWaypoint : NSObject

@property (nonatomic, readonly) CLLocation *location;

@property (nonatomic, assign) PointType pointType;
@property (nonatomic, assign) CLLocationCoordinate2D coordinates;

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *address;

- (instancetype)initWithCoordinates:(CLLocationCoordinate2D)coordinates name:(NSString *)name address:(NSString *)address pointType:(PointType)pointType;

@end
