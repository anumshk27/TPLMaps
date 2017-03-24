//
//  TPLPolygon.h
//  TPLMapsSDK
//
//  Copyright © 2017 TPL Maps. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface TPLPolygon : NSObject

/** The width of the line in screen points.Default is 2 .*/
@property (nonatomic, assign) CGFloat outlineWidth;

/** The UIColor used to render the polyline. if not set than default color will be Blue */
@property (nonatomic, strong) UIColor *outlineColor;

/** The color used to fill the shape’s path */
@property (nonatomic, strong) UIColor *fillColor;

/** Specifies the item’s position on the z axis. */
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
