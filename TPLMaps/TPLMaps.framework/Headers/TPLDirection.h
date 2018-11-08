//
//  TPLDirection.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 28/06/2017.
//
//

#import <Foundation/Foundation.h>
#import "TPLDirectionObject.h"

@interface TPLDirection : NSObject



/*! The Directions API is a service that calculates directions between locations using an HTTP request.
 *  \param orgin The start point of the route.
 *  \param destination The end point of the route.
 *  \param heading An integer value between 0 and 359 that represents degrees from north where north is 0 degrees and the heading is specified clockwise from north. For example, setting the heading of 270 degrees creates a route that initially heads west.
 *  \param isRerouting True if wants to reroute from different place. NOTE: In c
 *  \param routeType Type of the route required e.g ROUTE_TYPE_SHORTEST, ROUTE_TYPE_FASTEST, ROUTE_TYPE_UNDETERMINED.
 */

- (void)fetchRouteFrom:(CLLocationCoordinate2D)orgin
                    to:(CLLocationCoordinate2D)destination
               heading:(float)heading
           isRerouting:(BOOL)isRerouting
             routeType:(RouteType)routeType
       completionBlock:(void(^)(NSArray *routes, NSDictionary *issue, NSError *error))completionBlock;

@end
