//
//  TPLMapLabel.h
//  TPLMapsSDK
//
//  Copyright © 2017 TPL Maps. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface TPLMapPOI : NSObject
/** placeID for POI */
@property (nonatomic, strong) NSString *placeID;

/** name of POI */
@property (nonatomic, strong) NSString *name;

/** Location of POI on map */
@property (nonatomic) CLLocationCoordinate2D position;

/** convinience method which returns a POI constructed by attributes passed */ 

+ (TPLMapPOI *)poiWithPlaceID:(NSString *)placeID
                         name:(NSString *)name
                     position:(CLLocationCoordinate2D)position; 

@end
