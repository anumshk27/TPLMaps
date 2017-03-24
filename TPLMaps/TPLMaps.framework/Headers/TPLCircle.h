//
//  TPLPloyLine.h
//  TPLMapsSDK
//
//  Copyright © 2017 TPL Maps. All rights reserved.
//
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TPLCircle : NSObject

/** The width of the line in screen points.Default is 2 */
@property (nonatomic, assign) CGFloat outlineWidth;

/** The UIColor used to render the polyline. if empty or nil default color will be Blue */
@property (nonatomic, strong) UIColor *outlineColor;

/** The color used to fill the shape’s path */
@property (nonatomic, strong) UIColor *fillColor;

/** Specifies the item’s position on the z axis. Min 100 Max 2000 */
@property(nonatomic) int zIndex;

/** The center point of the circle, specified as a latitude and longitude value. */
@property (nonatomic) CLLocationCoordinate2D coord;

/** The radius of the circle, measured in meters from the center point. */
@property (nonatomic) CLLocationDistance radius;

/** A Boolean value that indicates whether the Circle is transparent. */
@property (nonatomic, assign) BOOL transparent;


/*! A pointer to the array of coordinates that define the path.
 *  \param coord The center point of the circle, specified as a latitude and longitude value.
 *  \param radius The radius of the circle, measured in meters from the center point.
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord radius:(CLLocationDistance)radius;



@end
