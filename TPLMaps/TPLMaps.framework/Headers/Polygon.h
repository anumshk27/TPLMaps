//
//  TPLPolygon.h
//  TPLMapsSDK
//
//  TPL Maps SDK for iOS 13/02/2017.
//
//

#import "CoordinateGeometry.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

/**
 Polygon interface that makes you able to add Polygons to the map view.
 */

@interface Polygon : NSObject

/** The width of the line in screen points.Default is 2 .*/
@property (nonatomic, assign) CGFloat outlineWidth;

/** The UIColor used to render the polyline. If empty or nil default color will be Blue. */
@property (nonatomic, strong) UIColor *outlineColor;

/** The color used to fill the shape’s path */
@property (nonatomic, strong) UIColor *fillColor;

/** Specifies the item’s position on the z axis. Min 100 Max 2000 */
@property(nonatomic) int zIndex;

/** A pointer to the array of coordinates that define the path. */
@property (nonatomic) MutableCoordinateGeometry * geometryCoordinates;

/** A Boolean value that indicates whether the polygon is transparent. */
@property (nonatomic, assign) BOOL transparent;

/*! Creates an Polygon object from the specified set of map points.
 *  \param geometryCoordinates The array of map points defining the shape.
 */
+ (instancetype)polygonWithCoordinates:(MutableCoordinateGeometry *)geometryCoordinates NS_SWIFT_NAME(polygonWithCoordinates(geometryCoordinates:));


@end
