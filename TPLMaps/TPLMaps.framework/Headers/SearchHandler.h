//
//  SearchHandler.h
//  SearchHandlerApi
//
//  Created by TPL Maps on 8/31/16.
//  Copyright © 2017 TPL Maps. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>



@interface SearchHandler : NSObject  

/*! Executes an HTTP GET command and retrieves the information.
 * \param APIkey Obtained from http://www.TPLMaps.com/maps to use with the request
 * \param searchText The query you need to search
 * \param place The coordinates of current location
 * \param responseHandler handle returns response of the search as an array of Place object and NSError if search failed.
 */
+ (void)searchPlaceWithAPIKey:(NSString*)APIkey searchText:(NSString *)searchText place:(CLLocation *)place responseHandler:(void(^)(NSArray *places, NSError *error))responseHandler;


@end


