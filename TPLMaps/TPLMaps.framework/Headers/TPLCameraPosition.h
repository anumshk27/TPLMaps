//
//  TPLCameraPosition.h
//  TPLMapsSDK
//
//  Created by Muhammad Sajad on 10/02/2017.
//
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A class for setting properties related to camera postion.
 * This is immutable and values cannot be changed
 */
@interface TPLCameraPosition : NSObject
/**
 * Location on map where camera should point
 */
@property(nonatomic, readonly) CLLocationCoordinate2D location;

/**
 * Zoom level ranging from 1 to 22 where 1 is world level
 */
@property(nonatomic, readonly) float zoom;

/**
 * Rotation in degrees in clockwise direction from true north, 0 means camera pointing towards true north.
 */
@property(nonatomic, readonly) float rotation;

/**
 * View angle of the camera, 0 means camera pointed straight down on map, 90 means its parallel to ground
 */
@property(nonatomic, readonly) double tilt;

/**
 * Its designated initializer which can be used to obtain camera object by setting all four params.
 * @param location Location on map where camera should point.
 * @param zoom Zoom level ranging from 1 to 22 where 1 is world level
 * @param rotation Rotation in degrees in clockwise direction from true north, 0 means camera pointing towards true north.
 * @param tilt View angle of the camera, 0 means camera pointed straight down on map, 90 means its parallel to ground
 */
- (id)initWithLocation:(CLLocationCoordinate2D)location
                  zoom:(float)zoom
              rotation:(float)rotation
                  tilt:(double)tilt;

/**
 * Returns a new camera position with specified value of location and zoom.
 * Rotation and Tilt are set to default values (Map is points to north with
 *
 */
+ (instancetype)cameraPositionWithLocation:(CLLocationCoordinate2D)location
                                      zoom:(float)zoom;

/**
 * Convenience constructor for GMSCameraPosition, with all camera properties as per
 * initWithTarget:zoom:bearing:viewingAngle:.
 */
+ (instancetype)cameraPositionWithLocation:(CLLocationCoordinate2D)location
                                      zoom:(float)zoom
                                  rotation:(float)rotation
                                      tilt:(double)tilt;


@end

/** Mutable version of TPLCameraPosition. */
@interface TPLMutableCameraPosition : TPLCameraPosition
@property(nonatomic, assign) CLLocationCoordinate2D location;
@property(nonatomic, assign) float zoom;
@property(nonatomic, assign) float rotation;
@property(nonatomic, assign) double tilt;

@end

NS_ASSUME_NONNULL_END
