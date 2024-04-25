//
//  TPLDirection.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 28/06/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
//#import "RouteNavigator.h"

/**
 * Enum provide RouteType type ROUTE_TYPE_FASTEST ,ROUTE_TYPE_SHORTEST or ROUTE_TYPE_UNDETERMINED.
 */
typedef NS_ENUM(NSUInteger, RouteType) {
    /** The fastest route to your destination based on speed and traffic condition. */
    ROUTE_TYPE_FASTEST = 0,
    /** The second fastest route to your destination based on speed and traffic condition. */
    ROUTE_TYPE_SECOND_FASTEST,
    /** The shortest route to your destination based on distance. */
    ROUTE_TYPE_SHORTEST,
    /** The fastest route to your destination based on speed. */
    ROUTE_TYPE_UNDETERMINED
};


/**
 Provides detailed infromation of Directions.
 */
@interface TPLDirection : NSObject

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

@property (nonatomic, strong, readonly) NSString *typeDescription;


/**
 * The Directions API is a service that calculates directions between locations using an HTTP request.
 * It will return all possible routes, with the selected route type placed at the first index.
 * Routes array will contain Route objects.
 * User can draw route using Route object.
 *
 * @param orgin The start point of the route.
 * @param destination The end point of the route.
 * @param heading An integer value between 0 and 359 that represents degrees from north where north is 0 degrees
 *        and the heading is specified clockwise from north. For example, setting the heading of 270 degrees
 *        creates a route that initially heads west.
 * @param isRerouting Flag indicating whether this is a rerouting operation.
 * @param routeType Type of the route required, e.g., ROUTE_TYPE_SHORTEST, ROUTE_TYPE_FASTEST, ROUTE_TYPE_UNDETERMINED.
 * @param completionBlock A block to be executed upon completion, providing the routes array and any errors.
 */
+ (void)fetchRouteFrom:(CLLocationCoordinate2D)orgin
                    to:(CLLocationCoordinate2D)destination
               heading:(float)heading
           isRerouting:(BOOL)isRerouting
             routeType:(RouteType)routeType
       completionBlock:(void (^)(NSArray* routes, NSError* error))completionBlock;



+ (void)divertRouteFrom:(CLLocation *)currentLocation
          toDestination:(CLLocation *)destination
           forRouteType:(RouteType)routeType
            withBearing:(float)bearing
             completion:(void (^)(NSArray *,NSDictionary *,NSError*))completionBlock;


@end
