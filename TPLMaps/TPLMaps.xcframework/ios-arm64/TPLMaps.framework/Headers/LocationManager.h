//
//  TPLLocationManager.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 03/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LocationManager;

@protocol LocationManagerDelegate <NSObject>
- (void)tplLocationManagerDidUpdtaeLocation:(LocationManager *)locationManger location:(CLLocation *)location;
- (void)tplLocationManager:(LocationManager *)locationManager didAuthorize:(BOOL)authorized;
- (void)tplLocationManager:(LocationManager *)locationManager didFailWithError:(NSError *)error; 

@end

@interface LocationManager : NSObject

@property (nonatomic, weak) id<LocationManagerDelegate> delegate;

- (CLLocation*)lastLocation;
- (BOOL)startUserLocationUpdates;
- (void)stopUpdatingLocation;
- (void)stopAndReset;

@end
