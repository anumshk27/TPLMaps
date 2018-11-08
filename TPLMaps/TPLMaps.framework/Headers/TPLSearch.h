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


@interface TPLSearch : NSObject

/*! Executes an HTTP GET command and retrieves the information.
 * \param query The query you need to search.
 * \param place The coordinates of place where search going to be initiated.
 * \param responseHandler handle returns response of the search as an array of Place object and NSError if search failed.
 */
+(void)searchQuery:(NSString *)query place:(CLLocation *)place responseHandler:(void (^)(NSArray *, NSError *))responseHandler;

+ (void)cancalSearchPlaces;

+(TPLSearch *)handler;

@end


