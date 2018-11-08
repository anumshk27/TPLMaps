//
//  TPLPolygon.h
//  TPLMapsSDK
//
//  TPL Maps SDK for iOS 13/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface TPLPolygon : NSObject

/** The width of the line in screen points.Default is 2 .*/
@property (nonatomic, assign) CGFloat outlineWidth;

/** The UIColor used to render the polyline. If empty or nil default color will be Blue. */
@property (nonatomic, strong) UIColor *outlineColor;

/** The color used to fill the shape’s path */
@property (nonatomic, strong) UIColor *fillColor;

/** Specifies the item’s position on the z axis. Min 100 Max 2000 */
@property(nonatomic) int zIndex;

/** The number of items in the coords array. */
@property (nonatomic) CLLocationCoordinate2D *coords;

/** The number of items in the coords array. */
@property (nonatomic) NSUInteger count;

/** A Boolean value that indicates whether the polygon is transparent. */
@property (nonatomic, assign) BOOL transparent;

/*! Creates an Polygon object from the specified set of map points.
 *  \param coords The array of map points defining the shape.
 *  \param count The number of items in the points array.
 */
+ (instancetype)polygonWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;


@end
