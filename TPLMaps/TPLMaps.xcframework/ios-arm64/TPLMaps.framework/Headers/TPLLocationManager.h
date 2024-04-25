//
//  TPLLocationManager.h
//  TPLMapsSDK
//
//  Created by Muhammad Anum on 03/02/2017.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class TPLLocationManager;

@protocol TPLLocationManagerDelegate <NSObject>
- (void)tplLocationManager:(TPLLocationManager *)locationManger didUpdateLocation:(CLLocation *)location;
- (void)tplLocationManager:(TPLLocationManager *)locationManger didUpdateHeading:(CLHeading *)heading;


- (void)tplLocationManager:(TPLLocationManager *)locationManager didAuthorize:(BOOL)authorized;
- (void)tplLocationManager:(TPLLocationManager *)locationManager didFailWithError:(NSError *)error;


@end

@interface TPLLocationManager : NSObject

@property (nonatomic, weak) id<TPLLocationManagerDelegate> delegate;

- (CLLocation*)lastLocation;
- (BOOL)startLocationUpdates;
- (void)startUpdatingHeading;
- (void)stopUpdatingHeading;
- (void)stopUpdatingLocation;
- (void)stopAndReset;

-(void)setBackgroundLocationUpdates:(BOOL)allow;


@end
