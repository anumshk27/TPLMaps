//
//  TPLPath.h
//  TPLMapsSDK
//
//  Created by Muhammad Sajad on 15/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN
/**
 * TPLCoordinateGeometry is colloction of CLLocationCooordinate2D. 
 * Its like an immutable array of coordinates which can represent a Path, Polyline, Polygon etc 
 * Use TPLMutableCoordinateGeometry for mutable object
 */
@interface TPLCoordinateGeometry : NSObject <NSCopying, NSMutableCopying>

/** Initialize new geometry with coordinates from other TPLCoordinateGeometry */
- (instancetype)initWithGeometry:(TPLCoordinateGeometry *)coordinateGeometry;

/** Gives the number of coordinate in the geometry */
@property (nonatomic) NSUInteger count;

/** Give the coordinate at specified index
 * * Raises an exeption if index is beyond the end of geometry.
 */
- (CLLocationCoordinate2D)coordinateAtIndex:(NSUInteger)index;

@end


@interface TPLMutableCoordinateGeometry : TPLCoordinateGeometry
/** Adds coordinate to the end of geometry */
- (void)addCoordinate:(CLLocationCoordinate2D)coordinate;

/** Inserts coordinate at specified index.
 * Raises an exeption if index is greater than size of geometry. 
 */
- (void)insertCoordinateAtIndex:(CLLocationCoordinate2D)coordinate atIndex:(NSUInteger)index;

/** Delete coordinate at specified index.
 * Raises an exeption if index is beyond the end of geometry.
 */
- (void)removeCoordiniateAtIndex:(NSUInteger)index;

/** Remove coordinate from end of geometry.*/
- (void)removeLastCoordinate;

/** Remove all the coordinates from geometry. */
- (void)removeAllCoordinates;


NS_ASSUME_NONNULL_END
@end
