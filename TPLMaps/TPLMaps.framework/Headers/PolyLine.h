//
//  TPLPloyLine.h
//  TPLMapsSDK
//
//  TPL Maps SDK for iOS 10/02/2017.
//
//

#import "CoordinateGeometry.h"
#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 PolyLine interface that makes you able to add PolyLines to the map view.
 */
@interface PolyLine : NSObject


/** The Width of the line in screen points.Default is 2 */
@property (nonatomic, assign) CGFloat lineWidth;

/** The UIColor used to render the polyline. if empty or nil default color will be Blue */
@property (nonatomic, strong) UIColor *outlineColor;

/** The outline width of the line in screen points.Default is 2 */
@property (nonatomic, assign) CGFloat outlineWidth;

/** The UIColor used to fill the shape’s path */
@property (nonatomic, strong) UIColor *fillColor;

/** Specifies the item’s position on the z axis. Min 500 Max 2000 */
@property(nonatomic) int zIndex;

/** A pointer to the array of coordinates that define the path. */
@property (nonatomic) MutableCoordinateGeometry * geometryCoordinates;

/** A Boolean value that indicates whether the polyline is transparent. */
@property (nonatomic, assign) BOOL transparent;

/*! A pointer to the array of coordinates that define the path.
 *  \param geometryCoordinates The array of coordinates defining the shape.
 */
+ (instancetype)polylineWithCoordinates:(MutableCoordinateGeometry *)geometryCoordinates NS_SWIFT_NAME(polylineWithCoordinates(geometryCoordinates:));

/*!
 *  Unavailable. Use -polylineWithCoordinates instead.
 */
- (instancetype)init __attribute__((unavailable("Use -polylineWithCoordinates instead.")));

/*!
 *  Unavailable. Use -polylineWithCoordinates instead.
 */
- (instancetype)initWithFrame:(CGRect)frame __attribute__((unavailable("Use -polylineWithCoordinates instead.")));

/*!
 *  Unavailable. Use -polylineWithCoordinates instead.
 */
+ (instancetype)new __attribute__((unavailable("Use -polylineWithCoordinates instead.")));

@end
