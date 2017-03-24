//
//  TPLMarker.h
//  TPLMapsSDK
//
//  Copyright © 2017 TPL Maps. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "TPLMapView.h"

@interface TPLMarker : NSObject


/** Convenience constructor for a default marker. */
+(instancetype)markerWithPosition:(CLLocationCoordinate2D)position;

/** Marker position. */
@property (nonatomic, assign) CLLocationCoordinate2D position;

/** The string containing the Marker's Title. */
@property (nonatomic, strong) NSString *title;

/** The string containing the Marker's subtitle. */
@property (nonatomic, strong) NSString *subTitle;

/** Specifies the item’s position on the z axis. Min 100 Max 2000 */
@property(nonatomic) int zIndex;

/** Sets the rotation angle for the Marker in degrees */
@property(nonatomic) float rotation;

/** Marker icon to render. If left nil, uses a default SDK place marker. */
@property (nonatomic, strong) UIImage *icon;

/** A Boolean value indicating whether or not the marker is visible.. */
@property (nonatomic) BOOL isVisible;

/** Controls whether this marker should be flat against the Earth's surface (YES) or a billboard facing the camera (NO, default).  */
@property (nonatomic) BOOL flat;

/** A Boolean value indicating whether the annotation view display in a callout bubble. */
@property (nonatomic) BOOL canShowCallout;


/** Get Marker Postion. Read-only */
-(CLLocationCoordinate2D)getPosition;

/** Get Marker Title. Read-only */
-(NSString*)getTitle;

/** Get Marker SubTitle. Read-only */
-(NSString*)getSubTitle;

/** Get Marker zIndex. Read-only */
-(int)getZIndex;

/** Get Marker Rotation. Read-only */
-(float)getRotation;

/** Get Marker Image. Read-only */
-(UIImage*)getIcon;

/** Get Marker Visibility. Read-only */
-(BOOL)getIsVisible;

/** Get Marker Callout View. Read-only */
-(BOOL)getCanShowCallout;



@end
