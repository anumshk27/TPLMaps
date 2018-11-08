//
//  RouteObject.h
//  tangram
//
//  Created by Muhammad Sajad on 26/07/2016.
//
//
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    /** The fastest route to your destination based on speed and traffic condition. */
    ROUTE_TYPE_FASTEST = 0,
    /** The shortest route to your destination based on distance. */
    ROUTE_TYPE_SHORTEST,
    /** The fastest route to your destination based on speed. */
    ROUTE_TYPE_UNDETERMINED
} RouteType;


#import <Foundation/Foundation.h>

@interface TPLDirectionObject : NSObject

@property (nonatomic, strong) NSString* via;
@property (nonatomic, strong) NSNumber* length;
@property (nonatomic, strong) NSNumber* time;
@property (nonatomic, strong) NSArray* segments;
@property (nonatomic, strong) NSArray* roadNames;

-(instancetype)initWithDictionary:(NSDictionary *)route;



@end

