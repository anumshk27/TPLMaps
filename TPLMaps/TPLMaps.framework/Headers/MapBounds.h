//
//  TPLMapBounds.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 15/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class CoordinateGeometry;

/**
 * Represents a rectangular bounds on map.
 * Gives methods to get bounds from different map properties i.e coordinate, geometery
 */
@interface MapBounds : NSObject

/** The North-East corner of the bounds. It can't be modified after initializtion */
@property(nonatomic, readonly) CLLocationCoordinate2D northEastCorner;

/** The South-West corner of the bounds. It can't be modified after initializtion */
@property(nonatomic, readonly) CLLocationCoordinate2D southWestCorner;

/** Initialize map bounds with coordinates */
- (instancetype)initWithCoordinate1:(CLLocationCoordinate2D)coordinate1
                        coordinate2:(CLLocationCoordinate2D)coordinate2;

/** Initialize map bounds from the coordinates in the path */
- (instancetype)initWithCoordinateGeometry:(CoordinateGeometry *)geometry;


/** Returns TPLMapBounds by including the passed coordinate */
- (void)includeCoordinate:(CLLocationCoordinate2D)coordinate;

/** Returns TPLMapBounds by including coordinates from the geometry*/
- (void)includeCoordinateGeometry:(CoordinateGeometry *)geometry;




@end
