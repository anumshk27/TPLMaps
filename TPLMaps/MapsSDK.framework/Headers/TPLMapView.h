//
//  TPLMapView.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 02/02/2017.
//
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "Direction.h"

@class TPLMapView;
@class Marker;
@class PolyLine;
@class MapPOI;
@class Polygon;
@class CameraPosition;
@class MapBounds;
@class Circle;
@class Direction;

/**
 * Enum provide MapView Mode Standard or Night.
 */
typedef NS_ENUM (NSUInteger, MapViewMode) {
    STANDARD = 0,
    NIGHT
};


NS_ASSUME_NONNULL_BEGIN

/**
 * TPLMapView Delegate Methods
 */
@protocol MapViewDelegate <NSObject>

@optional
/** Called when Map is completed loading. It tell that view is complete to perform any operation like applying styles etc.
 * Map may be rendering when this method is called
 */
- (void)mapViewDidCompleteLoading:(TPLMapView *)mapView;

/** Called when tap on particular coordinate. Not get called when tap gets a Marker or POI */
- (void)mapView:(TPLMapView *)mapView didSingleTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Called when double tap gesture recognized on a particular coordinate on map. */
- (void)mapView:(TPLMapView *)mapView didDoubleTapAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Called when long gesture recognized on a particular coordinate on map. */
- (void)mapView:(TPLMapView *)mapView didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/** Called a Marker is tapped. */
- (void)mapView:(TPLMapView *)mapView didSelectMarker:(Marker *)marker;

/** Called when a POI is tapped. */
- (void)mapView:(TPLMapView *)mapView didSelectPOI:(MapPOI *)poi;

/** Called when user location is updated. It only gets called when showsUserLocation is set true  */
- (void)mapView:(TPLMapView *)mapView userLocationUpdatedTo:(CLLocation *)location;

/** Called when user location update failed. Reason can be extracted from error  */
- (void)mapView:(TPLMapView *)mapView didFailToUpdateUserLocationWithError:(NSError *)error;

/** Called when camera position is start changing on map. It can be triggerd by setting camera position of map.
 * Or by calling any method changes either zoom, tilt, rotation, position of map.
 * Can also be triggered due to some gesutres.
 * cameraPosition param can be used to fetch current camera position on map.
 */
- (void)mapView:(TPLMapView *)mapView cameraPositionDidStartChange:(CameraPosition *)cameraPosition;

/** Same as cameraPositionDidStartChange: but get called when camera position is changing */
- (void)mapView:(TPLMapView *)mapView cameraPositionDidChange:(CameraPosition *)cameraPosition;

/** Same as cameraPositionDidStartChange: but get called when any change camera position is complete and map is still now*/
- (void)mapView:(TPLMapView *)mapView cameraPositionDidEndChange:(CameraPosition *)cameraPosition;

/**
 Called immediately before the displayed map region moves.
 
 @param mapView The map view instance.
 @param animated If YES the move will be animated over time, if NO the move will happen immediately.
 */
- (void)mapView:(nonnull TPLMapView *)mapView regionWillChangeAnimated:(BOOL)animated;

/**
 Called repeatedly when the displayed map region is moving due to an animation or a gesture.
 
 @param mapView The map view instance.
 */
- (void)mapViewRegionIsChanging:(nonnull TPLMapView *)mapView;

/**
 Called after the displayed map region moves.
 
 @param mapView The map view instance.
 @param animated If YES the move was animated over time, if NO the move happened immediately.
 */
- (void)mapView:(nonnull TPLMapView *)mapView regionDidChangeAnimated:(BOOL)animated;


@end


/**
 * This is the class use to show base maps
 * It provides all the controls to customize maps
 * Also configration of map interaction
 */

/**
 `TPLMapView` is a flexible and customizable map view managing the lifecycle of an OpenGL ES map. This view provides
 gesture handlers for tap, double-tap, long press, pan, pinch, rotate, and shove gestures.
 
 The public interface provides dynamic map marker placement, change of camera view settings, and map description changes
 through scene updates.
 
 To use basemap styles you can <a href="https://api.tplmaps.com/apiportal/#/portal/home"> sign up for an API key</a> and load it
 through your application:
 
 @note All the screen positions used in this inteface are in _logical pixel_ or _drawing coordinate system_ (based on a
 `UIKit` coordinate system), which is independent of the phone pixel density. Refer to the
 <a href="https://developer.apple.com/library/content/documentation/2DDrawing/Conceptual/DrawingPrintingiOS/GraphicsDrawingOverview/GraphicsDrawingOverview.html">Apple documentation</a>
 regarding _Coordinate Systems and Drawing in iOS_ for more information.
 */

@interface TPLMapView : UIView

#pragma mark Initialize the View
/**
 Initializes and returns a new map view for specified frame
 
 @param frame The view frame.
 @return An initialized map view.
 */
+ (instancetype)mapViewWithFrame:(CGRect)frame;

#pragma mark Delegates
/**
 The map view delegate
 May be `nil`. See `MapView` for more details.
 */
@property (nonatomic, weak, nullable) IBOutlet id <MapViewDelegate> delegate;

#pragma mark Changing the Map Viewport
/**
 The current position and orientation of the map camera.
 
 Setting this property will move the map immediately. To animate the movement use
 `-[MapView setCameraPositionAnimated:(nonnull CameraPosition *)]` or
 `-[TPLMapView setCameraPositionAnimated:(nonnull CameraPosition *) withDuration:(float)]`
 `
 */
@property (nonatomic, copy) CameraPosition *cameraPosition;

/**
 * Apply camera position with animation
 */
- (void)setCameraPositionAnimated:(CameraPosition *)cameraPosition;

/**
 * Apply camera position with animation over specified duration
 */
- (void)setCameraPositionAnimated:(CameraPosition *)cameraPosition withDuration:(float)duration;


#pragma mark Gesture Recognizers
/**
 * Sets the preference for whether all gestures should be enabled (default) or
 * disabled. This doesn't restrict users from tapping any on screen buttons to
 * move the camera (e.g., compass or zoom controls), nor does it restrict
 * programmatic movements and animation.
 */
@property (nonatomic) BOOL allGesturesEnabled NS_SWIFT_NAME(allGesturesEnabled);

/**
 * Wether zoom gesture is enabled or disabled on map .
 */
@property (nonatomic) BOOL zoomEnabled NS_SWIFT_NAME(zoomEnabled);

/**
 * Wether pan gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL scrollEnabled NS_SWIFT_NAME(scrollEnabled);

/**
 * Wether tilt gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL tiltEnabled NS_SWIFT_NAME(tiltEnabled);

/**
 * Wether rotate gesture is enabled or disabled on map.
 */
@property (nonatomic) BOOL rotateEnabled NS_SWIFT_NAME(rotateEnabled);

/**
 * Set to YES to add the user location annotation to the map and start updating its location
 * Set key in info.plist
 */
@property (nonatomic) BOOL showsUserLocation NS_SWIFT_NAME(showsUserLocation);

/**
 * If My Location is enabled, reveals where the user location dot is being
 * drawn. If it is disabled, or it is enabled but no location data is available,
 * this will be nil.  This property is observable using KVO.
 */
@property(nonatomic, strong, readonly) CLLocation *myCurrentLocation NS_SWIFT_NAME(myCurrentLocation);

#pragma mark Coordinate Conversions

/**
 Convert a longitude and latitude to a view position.
 
 @param coordinate The geographic coordinate to convert
 @return The view position of the input coordinate
 */
- (CGPoint)pointForCoordinate:(CLLocationCoordinate2D)coordinate NS_SWIFT_NAME(pointForCoordinate(coordinate:));

/**
 Convert a position in view coordinates into the longitude and latitude of the corresponding geographic location.
 
 @param point the position in view coordinates to convert
 @return the latitude and longitude
 */
- (CLLocationCoordinate2D)coordinateForPoint:(CGPoint)point NS_SWIFT_NAME(coordinateForPoint(point:));

#pragma mark Changing the Map Viewport
/**
 Changes the postion of map. Map will be centered to new position.
 
 @param location the position in view coordinates to convert
 */
- (void)animateToLocation:(CLLocationCoordinate2D)location NS_SWIFT_NAME(animateToLocation(location:));;

/**
 To animate the location movement with user define duration
 
 @param location the position in view coordinates to convert
 @param duration value of animation duration in seconds
 
 */
- (void)animateToLocation:(CLLocationCoordinate2D)location withDuration:(float)duration NS_SWIFT_NAME(animateToLocation(location:duration:));

/**
 Changes zoom of the map. If value of zoom is out of zoom bounds (minzoom, maxzoom) zoom will be set to either minzoom or maxzoom
 @param zoom fvalue of zoom level in float
 */
- (void)animateToZoom:(float)zoom NS_SWIFT_NAME(animateToZoom(zoom:));

/**
 To animate the zoom movement with user define duration
 
 @param zoom value of zoom level in float
 @param duration value of animation duration in float
 */
- (void)animateToZoom:(float)zoom withDuration:(float)duration NS_SWIFT_NAME(animateToLocation(zoom:duration:));

/**
 Changes the rotation of map from true north. Zero indicates true north.
 Rotation should be in radians
 
 @param rotation value of rotation in float
 */
- (void)animateToRotation:(float)rotation NS_SWIFT_NAME(animateToRotation(rotation:));

/**
 To animate the rotation movement with user define duration
 
 @param rotation value of rotation in float
 @param duration value of animation duration in float
 */
- (void)animateToRotation:(float)rotation withDuration:(float)duration NS_SWIFT_NAME(animateToRotation(rotation:duration:));

/**
 Changes the tilt of map. 0 means looking straight down at map.
 If value is greater than PI/4 then it uses maxLimit (PI/4).
 
 @param tilt value of tilt in float
 */
- (void)animateToTilt:(double)tilt NS_SWIFT_NAME(animateToTilt(tilt:));

/**
 To animate the tilt movement with user define duration
 
 @param tilt value of tilt in float
 @param duration value of animation duration in float
 */
- (void)animateToTilt:(double)tilt withDuration:(float)duration NS_SWIFT_NAME(animateToTilt(rotation:duration:));

/**
 Adjust camera postion to fit MapBounds with in the mapview.
 
 @param bounds Represents a rectangular bounds on map
 @param padding Padding is specify the distance of bounds box from view's edges
 */
- (void)setBounds:(MapBounds *)bounds withPadding:(UIEdgeInsets)padding NS_SWIFT_NAME(setBounds(bounds:padding:));

/**
 Same as setBounds:withPadding: but with animation over specified duration
 
 @param bounds Represents a rectangular bounds on map
 @param padding Padding is specify the distance of bounds box from view's edges
 @param duration value of animation duration in float
 */
- (void)setBoundsAnimated:(MapBounds *)bounds withPadding:(UIEdgeInsets)padding duration:(float)duration NS_SWIFT_NAME(setBoundsAnimated(bounds:padding:duration:));

/**
 Adjust camera postion to fit TPLMapBounds with in the rect on mapview.
 Padding is specify the distance of bounds box from rect edges
 
 @param bounds Represents a rectangular bounds on map
 @param rect in which maps need padding
 @param padding Padding is specify the distance of bounds box from view's edges
 */
- (void)setBoundsFitInRect:(MapBounds *)bounds rect:(CGRect)rect withPadding:(UIEdgeInsets)padding NS_SWIFT_NAME(setBoundsFitInRect(bounds:rect:padding:));

/**
 Same as setBounds:rect:withPadding: but with animation over specified duration
 
 @param bounds Represents a rectangular bounds on map
 @param rect in which maps need padding
 @param padding Padding is specify the distance of bounds box from view's edges
 @param duration value of animation duration in float
 */
- (void)setBoundsFitInRectAnimated:(MapBounds *)bounds rect:(CGRect)rect withPadding:(UIEdgeInsets)padding duration:(float)duration NS_SWIFT_NAME(setBoundsFitInRectAnimated(bounds:rect:padding:duration:));

#pragma mark Changing the Map Options

/**
 * Enum provide MapView Mode Standard or Night.
 */
@property (nonatomic) MapViewMode mapMode NS_SWIFT_NAME(mapMode);

/**
 * A Boolean indicating whether the map displays point-of-interest information.
 */
@property (nonatomic) BOOL showsPointsOfInterest NS_SWIFT_NAME(showsPointsOfInterest);

/**
 * A Boolean indicating whether the map displays extruded building information.
 */
@property (nonatomic) BOOL showsBuildings NS_SWIFT_NAME(showsPointsOfInterest);

/**
 A Boolean indicating whether the map displays a location button control.
 */
@property(nonatomic) BOOL myLocationButtonEnabled NS_SWIFT_NAME(myLocationButtonEnabled);

/**
 A Boolean indicating whether the map displays a compass control.
 */
@property(nonatomic) BOOL showsCompass NS_SWIFT_NAME(showsCompass);

/**
 A Boolean indicating whether the map displays zoom controls.
 */
@property(nonatomic) BOOL zoomControlsEnabled NS_SWIFT_NAME(zoomControlsEnabled);

/**
 A Boolean indicating whether the map displays traffic.
 */
@property(nonatomic) BOOL trafficEnabled NS_SWIFT_NAME(trafficEnabled);

/**
 The maximum zoom level that the map can be zoomed into.
 */
@property (nonatomic) CGFloat maximumZoom NS_SWIFT_NAME(maximumZoom);

/**
 The minimum zoom level that the map cab be zoomed out to.
 */
@property (nonatomic) CGFloat minimumZoom NS_SWIFT_NAME(maximumZoom);

#pragma mark Markers
/**
 Sets the location that define the geo-point.
 */
- (void)addMarker:(Marker *)marker NS_SWIFT_NAME(addMarker(Marker:));

/**
 Remove Marker from map.
 */
- (void)removeMarker:(Marker*)marker NS_SWIFT_NAME(removeMarker(Marker:));
/**
 Remove all the Markers from the map.
 */
- (void)removeAllMarkers;
/**
 Sets the locations that define the Polyline.
 */
- (void)drawPolyLine:(PolyLine *)polyline NS_SWIFT_NAME(drawPolyLine(PolyLine:));
/**
 Remove Polyline from map.
 */
- (void)removePolyLine:(PolyLine*)polyline NS_SWIFT_NAME(removePolyLine(PolyLine:));
/**
 Remove all Polylines from map.
 */
- (void)removeAllPolylines;
/**
 Sets the locations that define the Polygon.
 */
- (void)drawPolygon:(Polygon*)polygon NS_SWIFT_NAME(drawPolygon(Polygon:));
/**
 Remove Polygon from map.
 */
- (void)removePolygon:(Polygon*)polygon NS_SWIFT_NAME(removePolygon(Polygon:));
/**
 Remove all Polygons from map.
 */
- (void)removeAllPolygons;

/**
 Sets the location that define the Circle.
 */
- (void)drawCircle:(Circle *)circle NS_SWIFT_NAME(drawCircle(Circle:));

/**
 Remove Circle from map.
 */
- (void)removeCircle:(Circle *)circle NS_SWIFT_NAME(removeCircle(Circle:));

/**
 Remove all Circles from map.
 */
- (void)removeAllCircles;

/**
 Draw route on Map using Direction object.
 It will draw route on Map.
 User can draw route using Direction object.
 
 @param route is the Direction object obtained from Direction class.
 */
- (void)drawRoute:(Direction *)route NS_SWIFT_NAME(drawRoute(Direction:));

/**
 Draw single route on Map from start to end positions.
 This method will draw the route between two points.
 This method will draw route on Map, also provide Direction object which includes all routing instructions.
 
 @param orgin The start point of the route.
 @param destination The end point of the route.
 @param heading An integer value between 0 and 359 that represents degrees from north where north is 0 degrees and the heading is specified clockwise from north. For example, setting the heading of 270 degrees creates a route that initially heads west.
 @param routeType Type of the route required e.g ROUTE_TYPE_SHORTEST, ROUTE_TYPE_FASTEST, ROUTE_TYPE_UNDETERMINED.
 */
- (void)drawRouteFrom:(CLLocationCoordinate2D)orgin to:(CLLocationCoordinate2D)destination heading:(float)heading routeType:(RouteType)routeType completionBlock:(void (^)(Direction* direction,NSError* error))completionBlock;

//- (void)JSONStlyleFile:(NSString*)file;

- (void)removeRoute:(Direction *)route NS_SWIFT_NAME(removeRoute(Direction:));

NS_ASSUME_NONNULL_END

@end
