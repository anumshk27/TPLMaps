//
//  TPLPath.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 15/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN
/**
 * CoordinateGeometry is colloction of CLLocationCooordinate2D.
 * Its like an immutable array of coordinates which can represent a Path, Polyline, Polygon etc 
 * Use MutableCoordinateGeometry for mutable object
 */
@interface CoordinateGeometry : NSObject

/** Initialize new geometry with coordinates from other TPLCoordinateGeometry */
- (instancetype)initWithGeometry:(CoordinateGeometry *)coordinateGeometry;

/** Gives the number of coordinate in the geometry */
@property (nonatomic) NSUInteger count;

/** Give the coordinate at specified index
 * * Raises an exeption if index is beyond the end of geometry.
 */
- (CLLocationCoordinate2D)coordinateAtIndex:(NSUInteger)index;

@end


@interface MutableCoordinateGeometry : CoordinateGeometry
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
