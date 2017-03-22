//
//  TPLMapView.h
//  TPLMapsSDK
//
//  Created by Muhammad Sajad on 02/02/2017.
//
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>


@class TPLMapView;
@class TPLMarker;
@class TPLPolyLine;
@class TPLMapPOI;
@class TPLPolygon;
@class TPLCameraPosition;
@class TPLMapBounds;
@class TPLCircle;

typedef enum {
    STANDARD = 0,
    NIGHT
} MapViewMode;


NS_ASSUME_NONNULL_BEGIN

/**
 * TPLMapView Delegate Methods
 */
@protocol TPLMapViewDelegate <NSObject>

@optional
/** Triggered when Map start loading after initialization */
- (void)mapViewWillStartLoading:(TPLMapView *)mapView;

/** Triggered when Map is completed loading. It tell that view is complete to perform any operation like applying styles etc.
 * Map may be rendering when this method is called 
 */
- (void)mapViewDidCompleteLoading:(TPLMapView *)mapView;

/** Triggered when Map loading is failed due to some reason. 
 * Reason can be extracted from error argument
 */
- (void)mapViewDidFailLoading:(TPLMapView *)mapView withError:(NSError *)error;

/** Triggered when Map View start rendering.
 * This is different from mapViewWillStartLoading: and gets called when visible tiles start bulding.
 */
- (void)mapViewDidStartRendering:(TPLMapView *)mapView;

/** Triggered when Map View finish rendering.
 * This is different from mapViewDidCompleteLoading: and gets called when visible tiles are completly rendering.
 */
- (void)mapViewDidFinishRendering:(TPLMapView *)mapView;

/** Triggered when tap on particular coordinate. Not get called when tap gets a Marker or POI */
- (void)mapView:(TPLMapView *)mapView didSingleTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Triggered when double tap gesture recognized on a particular coordinate on map. */
- (void)mapView:(TPLMapView *)mapView didDoubleTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Triggered when long gesture recognized on a particular coordinate on map. */
- (void)mapView:(TPLMapView *)mapView didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Triggered a Marker is tapped. */
- (void)mapView:(TPLMapView *)mapView didSelectMarker:(TPLMarker *)marker;

/** Triggered a POI is tapped. */
- (void)mapView:(TPLMapView *)mapView didSelectPOI:(TPLMapPOI *)poi;

/** Triggered when user location is updated. It only gets called when showsUserLocation is set true  */
- (void)mapView:(TPLMapView *)mapView userLocationUpdatedTo:(CLLocation *)location;

/** Triggered when user location update failed. Reason can be extracted from error  */
- (void)mapView:(TPLMapView *)mapView didFailToUpdateUserLocationWithError:(NSError *)error;

/** Triggered when camera position is start changing on map. It can be triggerd by setting camera position of map. 
 * Or by calling any method changes either zoom, tilt, rotation, position of map.
 * Can also be triggered due to some gesutres.
 * cameraPosition param can be used to fetch current camera position on map. 
 */
- (void)mapView:(TPLMapView *)mapView cameraPositionDidStartChange:(TPLCameraPosition *)cameraPosition;

/** Same as cameraPositionDidStartChange: but get called when camera position is changing */
- (void)mapView:(TPLMapView *)mapView cameraPositionDidChange:(TPLCameraPosition *)cameraPosition;

/** Same as cameraPositionDidStartChange: but get called when any change camera position is complete and map is still now*/
- (void)mapView:(TPLMapView *)mapView cameraPositionDidEndChange:(TPLCameraPosition *)cameraPosition;


@end


/**
 * This is the class use to show base maps
 * It provides all the controls to customize maps
 * Also configration of map interaction
 */

@interface TPLMapView : UIView
/**
 * TPLMapView Delegate
 */
@property (nonatomic, weak, nullable) id <TPLMapViewDelegate> delegate;

/**
 * Builds the map view for specified frame
 */
+ (instancetype)mapViewWithFrame:(CGRect)frame;

/**
 * Camera postion on the map.
 * Setting this property will result in instantaneous changes.
 */
@property (nonatomic, copy) TPLCameraPosition *cameraPosition;

/**
 * Apply camera position with animation
 */
- (void)setCameraPositionAnimated:(TPLCameraPosition *)cameraPosition;

/**
 * Apply camera position with animation over specified duration
 */
- (void)setCameraPositionAnimated:(TPLCameraPosition *)cameraPosition withDuration:(float)duration;

/**
 * Sets the preference for whether all gestures should be enabled (default) or
 * disabled. This doesn't restrict users from tapping any on screen buttons to
 * move the camera (e.g., compass or zoom controls), nor does it restrict
 * programmatic movements and animation.
 */
@property (nonatomic) BOOL allGesturesEnabled;

/**
 * Wether zoom gesture is enabled or disabled on map .
 */
@property (nonatomic) BOOL zoomEnabled;
/**
 * Wether pan gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL scrollEnabled;
/**
 * Wether tilt gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL tiltEnabled;

/**
 * Wether rotate gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL rotateEnabled;

/**
 * Set to YES to add the user location annotation to the map and start updating its location
 * Set key in info.plist
 */
@property (nonatomic) BOOL showsUserLocation;

/**
 * If My Location is enabled, reveals where the user location dot is being
 * drawn. If it is disabled, or it is enabled but no location data is available,
 * this will be nil.  This property is observable using KVO.
 */
@property(nonatomic, strong, readonly) CLLocation *myCurrentLocation;


/** Maps an Earth coordinate to a point coordinate in the map's view. */
- (CGPoint)pointForCoordinate:(CLLocationCoordinate2D)coordinate;

/** Maps a point coordinate in the map's view to an Earth coordinate. */
- (CLLocationCoordinate2D)coordinateForPoint:(CGPoint)point;

/**
 * Changes the postion of map. Map will be centered to new position.
 */
- (void)animateToLocation:(CLLocationCoordinate2D)location;
- (void)animateToLocation:(CLLocationCoordinate2D)location withDuration:(float)duration;

/**
 * Changes zoom of the map. If value of zoom is out of zoom bounds (minzoom, maxzoom) zoom will be set to either minzoom or maxzoom
 */
- (void)animateToZoom:(float)zoom;
- (void)animateToZoom:(float)zoom withDuration:(float)duration;

/**
 * Changes the rotation of map from true north. Zero indicates true north.
 * Rotation should be in radians
 */
- (void)animateToRotation:(float)rotation;
- (void)animateToRotation:(float)rotation withDuration:(float)duration;

/**
 * Changes the tilt of map. 0 means looking straight down at map. 
 * if value is greater than PI/4 then it uses maxLimit (PI/4). 
 */
- (void)animateToTilt:(double)tilt;
- (void)animateToTilt:(double)tilt withDuration:(float)duration;

/**
 * Adjust camera postion to fit TPLMapBounds with in the mapview. 
 * Padding is specify the distance of bounds box from view's edges
 */
- (void)setBounds:(TPLMapBounds *)bounds withPadding:(CGFloat)padding;

/** Same as setBounds:withPadding: but with animation over specified duration */
- (void)setBoundsAnimated:(TPLMapBounds *)bounds withPadding:(CGFloat)padding duration:(float)duration;

/**
 * Adjust camera postion to fit TPLMapBounds with in the rect on mapview.
 * Padding is specify the distance of bounds box from rect edges
 */
- (void)setBoundsFitInRect:(TPLMapBounds *)bounds rect:(CGRect)rect withPadding:(CGFloat)padding;

/** Same as setBounds:rect:withPadding: but with animation over specified duration */
- (void)setBoundsFitInRectAnimated:(TPLMapBounds *)bounds rect:(CGRect)rect withPadding:(CGFloat)padding duration:(float)duration;

/**
 * Enum provide MapView Mode Standard or Night.
 */
@property (nonatomic) MapViewMode mapMode;

/**
 * A Boolean indicating whether the map displays point-of-interest information.
 */
@property (nonatomic) BOOL showsPointsOfInterest;
/**
 * A Boolean indicating whether the map displays extruded building information.
 */
@property (nonatomic) BOOL showsBuildings;
/**
 A Boolean indicating whether the map displays a location button control.
 */
@property(nonatomic) BOOL myLocationButtonEnabled;
/**
 A Boolean indicating whether the map displays a compass control.
 */
@property(nonatomic) BOOL showsCompass;
/**
 A Boolean indicating whether the map displays zoom controls.
 */
@property(nonatomic) BOOL zoomControlsEnabled;

@property (nonatomic) int maximumZoom;
@property (nonatomic) int minimumZoom;



- (void)addMarker:(TPLMarker *)marker;
- (void)removeMarker:(TPLMarker*)marker;
- (void)removeAllMarkers;

- (void)drawPolyLine:(TPLPolyLine *)polyline;
- (void)removePolyLine:(TPLPolyLine*)polyline;
- (void)removeAllPolylines;

- (void)drawPolygon:(TPLPolygon*)polygon;
- (void)removePolygon:(TPLPolygon*)polygon;
- (void)removeAllPolygons;

- (void)drawCircle:(TPLCircle *)circle;
- (void)removeCircle:(TPLCircle *)circle;
- (void)removeAllCircles;


- (void)JSONStlyleFile:(NSString*)file;



NS_ASSUME_NONNULL_END

@end
