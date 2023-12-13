//
//  SearchHandler.h
//  SearchHandlerApi
//
//  Created by TPL Maps on 8/31/16.
//  Copyright © 2016 TPL Maps. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class Place;

/**
 By using Search, you can search for any loction on map.
 */
@interface Search : NSObject

/**
 Executes an HTTP GET command and retrieves the information.
 
 @param query The query you need to search.
 @param place The coordinates of place where search going to be initiated.
 @param responseHandler handle returns response of the search as an array of Place object and NSError if search fails.
 */
+(void)searchQuery:(NSString *)query place:(CLLocation *)place responseHandler:(void (^)(NSArray *, NSError *))responseHandler;

/**
 Cancel manually previous requests before making a new request for search.
 */
+ (void)cancalSearchPlaces;

/**
 Initialize a shared instance of Search.
 */
+(Search *)handler;


/**
 Executes HTTP GET command and retrieves the information.
 Method searchNearby provides the near by Places from the center place/point to a certain radius.
 
 @param name : optional parameter, keyword you want to search nearby.
 @param place : mandatiory parameter, The coordinates of place where search going to be initiated.
 @param radius : mandatiory parameter, Radius in which search will be performed
 @param limit : optional parameter, Number of records at once.
 @param offset : optional parameter, Offset for pagination
 @param responseHandler handle returns response of the search as an array of Place objects and NSError if search fails.
 */
+(void)searchNearby:(NSString *)name Place:(CLLocation *)place Radius:(NSInteger)radius Limit:(NSInteger)limit  Offset:(NSInteger)offset responseHandler:(void (^)(NSArray *, NSError *))responseHandler;

/**
 Executes an HTTP POST command and retrieves the information.
 Method returns a place item (e.g: division, district, tehsil) around the given location.
 
 @param place The coordinates of place where search going to be initiated.
 @param responseHandler handle returns response of the search as an array of NearbyPlace object and NSError if search fails.
 */
+(void)requestNearbyPlace:(CLLocation *)place responseHandler:(void (^)(NSArray *, NSError *))responseHandler;


/**
 Executes an HTTP POST command and retrieves the information.
 Method returns a place item (e.g: division, district, tehsil) around the given location.
 
 @param place The coordinates of place where search going to be initiated.
 @param responseHandler handle returns response of the search as an array of NearbyPlace object and NSError if search fails.
 */
+(void)getAreaDetail:(NSString *)name place:(CLLocation *)place responseHandler:(void (^)(NSArray *, NSError *))responseHandler;


/**
 Executes an HTTP POST command and retrieves the information.
 Method returns a place item (e.g: division, district, tehsil) around the given location.
 
 @param place The coordinates of place where search going to be initiated.
 @param responseHandler handle returns response of the search as an array of Place objects object and NSError if search fails.
 */
+(void)optimizedSearch:(NSString *)query place:(CLLocation *)place responseHandler:(void (^)(NSArray *, NSError *))responseHandler;


/**
 Executes an HTTP POST command and retrieves the information.
 Method returns a place item (e.g: name, parent,cpd_address) around the given point.
 
 @param point The coordinates of place where search going to be initiated.
 @param responseHandler handle returns response of the search as an array of Place object and NSError if search fails.
 */
+(void)searchByPoint:(CLLocation *)point responseHandler:(void (^)(NSArray *, NSError *))responseHandler;

@end


