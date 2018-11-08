//
//  TPLPloyLine.h
//  TPLMapsSDK
//
//  TPL Maps SDK for iOS 10/02/2017.
//
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TPLPolyLine : NSObject


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
@property (nonatomic) CLLocationCoordinate2D *coords;

/** The number of items in the coords array. */
@property (nonatomic) NSUInteger count;

/** A Boolean value that indicates whether the polyline is transparent. */
@property (nonatomic, assign) BOOL transparent;



/*! A pointer to the array of coordinates that define the path.
 *  \param coords The array of coordinates defining the shape.
 *  \param count The number of items in the coords array.
 */
+ (instancetype)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;



@end
