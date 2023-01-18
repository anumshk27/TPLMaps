//
//  Geocoder.h
//  TPLMaps SDK
//
//  Created by TPL Maps on 8/02/20.
//  Copyright © 2020 TPL Maps. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "Place.h"

typedef void (^GeocodeCompletionHandler)(NSArray< Place *> * placemarks, NSError * error);

/**
 By using Geocoder, you can convert street addresses to geo-coordinates.
 */
@interface Geocoder : NSObject

/**
 Submits a reverse-geocoding request for the specified location.
 
 @param location The location object containing the coordinate data to look up.
 @param completionHandler The handler block to execute with the results. The geocoder executes this handler regardless of whether the request was successful or unsuccessful.
 */
+(void)reverseGeocodeLocation:(CLLocation*)location completionHandler:(GeocodeCompletionHandler)completionHandler;

/**
Cancel on going geocode request.
*/
+ (void)cancelGeocode;

/*!
 *  Unavailable. Use -reverseGeocodeLocation instead.
 */
- (instancetype)init __attribute__((unavailable("Use -reverseGeocodeLocation instead.")));

/*!
 *  Unavailable. Use -reverseGeocodeLocation instead.
 */
+ (instancetype)new __attribute__((unavailable("Use -reverseGeocodeLocation instead.")));




@end


