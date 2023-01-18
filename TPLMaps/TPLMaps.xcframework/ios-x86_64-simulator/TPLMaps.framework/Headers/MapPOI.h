//
//  MapPOI.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 02/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/**
 Contains the basic information about the location.
 To obtain the values, you can tap on the icon or label of that location.

 */
@interface MapPOI : NSObject
/** placeID for POI */
@property (nonatomic, strong) NSString *placeID;

/** name of POI */
@property (nonatomic, strong) NSString *name;

/** Location of POI on map */
@property (nonatomic) CLLocationCoordinate2D position;

/** convinience method which returns a POI constructed by attributes passed */ 

+ (MapPOI *)poiWithPlaceID:(NSString *)placeID
                         name:(NSString *)name
                  position:(CLLocationCoordinate2D)position NS_SWIFT_NAME(poiWithPlaceID(placeID:name:position:));

@end
