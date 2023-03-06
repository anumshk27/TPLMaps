//
//  TPLDirection.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 28/06/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/**
 * Enum provide RouteType type ROUTE_TYPE_FASTEST ,ROUTE_TYPE_SHORTEST or ROUTE_TYPE_UNDETERMINED.
 */
typedef NS_ENUM(NSUInteger, RouteType) {
    /** The fastest route to your destination based on speed and traffic condition. */
    ROUTE_TYPE_FASTEST = 0,
    /** The shortest route to your destination based on distance. */
    ROUTE_TYPE_SHORTEST,
    /** The fastest route to your destination based on speed. */
    ROUTE_TYPE_UNDETERMINED
};


/**
 Provides detailed infromation of Directions.
 */
@interface Direction : NSObject

/**
 * Provides information if contains a middle location.
 */
@property (nonatomic, strong) NSString* via;
/**
 * Provides information about the total length of Direction.
 */
@property (nonatomic, strong) NSNumber* length;
/**
 * Provides information about the total travelling time required to the destination.
 */
@property (nonatomic, strong) NSNumber* time;
/**
 * Provides information about the direction segments to the destination.
 */
@property (nonatomic, strong) NSArray* segments;
/**
 * Provides information about the road names in the Direction.
 */
@property (nonatomic, strong) NSArray* roadNames;
/**
 * provides information about the Type of Route e.g : ROUTE_TYPE_FASTEST ,ROUTE_TYPE_SHORTEST or ROUTE_TYPE_UNDETERMINED
 */
@property (nonatomic, assign) RouteType routeType;

/** The Directions API is a service that calculates directions between locations using an HTTP request.
 it will return all possible routes, maximum three routes will be generated. Selected RouteType will be placed at first index. Routes array will contain Direction objects.
 User can draw route using Direction object.

 @param orgin The start point of the route.
 @param destination The end point of the route.
 @param heading An integer value between 0 and 359 that represents degrees from north where north is 0 degrees and the heading is specified clockwise from north. For example, setting the heading of 270 degrees creates a route that initially heads west.
 @param routeType Type of the route required e.g ROUTE_TYPE_SHORTEST, ROUTE_TYPE_FASTEST, ROUTE_TYPE_UNDETERMINED.
 */
+ (void)fetchRouteFrom:(CLLocationCoordinate2D)orgin to:(CLLocationCoordinate2D)destination heading:(float)heading routeType:(RouteType)routeType completionBlock:(void (^)(NSArray* routes,NSError* error))completionBlock;

@end
