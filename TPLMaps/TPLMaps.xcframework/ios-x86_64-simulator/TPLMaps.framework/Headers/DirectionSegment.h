//
//  RouteSegment.h
//  tangram
//
//  Created by Muhammad Sajad on 26/07/2016.
//
//


#import <Foundation/Foundation.h>

typedef enum {
    
    MANEUVERTYPE_TURN_SHARP_LEFT = -3,
    MANEUVERTYPE_TURN_LEFT = -2,
    MANEUVERTYPE_TURN_SLIGHT_LEFT = -1,
    MANEUVERTYPE_CONTINUE_ON_STREET = 0,
    MANEUVERTYPE_TURN_SLIGHT_RIGHT = 1,
    MANEUVERTYPE_TURN_RIGHT = 2,
    MANEUVERTYPE_TURN_SHARP_RIGHT = 3,
    MANEUVERTYPE_FINISH = 4,
    MANEUVERTYPE_USE_ROUNDABOUT = 6,
    MANEUVERTYPE_MAKE_A_UTURN = 7,
    MANEUVERTYPE_FORK_LEFT = -8,
    MANEUVERTYPE_FORK_RIGHT = 8,
    MANEUVERTYPE_FORK_CENTER = 9,
    MANEUVERTYPE_TURN_LEFT_LEFT = -7
} ManeuverType;

@interface DirectionSegment : NSObject

@property (nonatomic, strong) NSString* compressedGeometry;
@property (nonatomic, strong) NSArray* geometry;
@property (nonatomic, strong) NSArray* geometryIndexes;
@property (nonatomic, strong) NSArray* roadNames;
@property (nonatomic, assign) ManeuverType maneuverType;
@property (nonatomic, strong) NSNumber* length;
@property (nonatomic, strong) NSString* text;
@property (nonatomic, strong) NSString* time;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
