//
//  TPLMapBounds.h
//  TPLMapsSDK
//
//  Created by Muhammad Sajad on 15/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class TPLCoordinateGeometry;

/**
 * Represents a rectangular bounds on map.
 * Gives methods to get bounds from different map properties i.e coordinate, geometery
 */
@interface TPLMapBounds : NSObject

/** The North-East corner of the bounds. It can't be modified after initializtion */
@property(nonatomic, readonly) CLLocationCoordinate2D northEastCorner;

/** The South-West corner of the bounds. It can't be modified after initializtion */
@property(nonatomic, readonly) CLLocationCoordinate2D southWestCorner;

/** Initialize map bounds with coordinates */
- (instancetype)initWithCoordinate1:(CLLocationCoordinate2D)coordinate1
                        coordinate2:(CLLocationCoordinate2D)coordinate2;

/** Initialize map bounds from the coordinates in the path */
- (instancetype)initWithCoordinateGeometry:(TPLCoordinateGeometry *)geometry;


/** Returns TPLMapBounds by including the passed coordinate */
- (void)includeCoordinate:(CLLocationCoordinate2D)coordinate;

/** Returns TPLMapBounds by including coordinates from the geometry*/
- (void)includeCoordinateGeometry:(TPLCoordinateGeometry *)geometry;




@end
