//
//  RouteSegment.h
//  tangram
//
//  Created by Muhammad Sajad on 26/07/2016.
//
//


#import <Foundation/Foundation.h>

@interface DirectionSegment : NSObject

@property (nonatomic, strong) NSString* compressedGeometry;
@property (nonatomic, strong) NSArray* geometry;
@property (nonatomic, strong) NSArray* geometryIndexes;
@property (nonatomic, strong) NSArray* roadNames;

@property (nonatomic, strong) NSNumber* length;
@property (nonatomic, strong) NSString* text;
@property (nonatomic, strong) NSString* time;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
