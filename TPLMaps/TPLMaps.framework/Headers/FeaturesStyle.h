//
//  FeaturesStyle.h
//  tangram
//
//  Copyright © 2017 TPL Maps. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface FeaturesStyle : NSObject


@property (nonatomic, strong) NSString *mapMode;
@property (nonatomic, strong) NSString *featureType;
@property (nonatomic, strong) NSString *color;
@property (nonatomic, strong) NSString *width;
@property (nonatomic, strong) NSString *outlineColor;
@property (nonatomic, strong) NSString *outlineWidth;
@property (nonatomic, strong) NSString *visibility;


- (id)initWithMapStyleFromJSON:(NSDictionary*)jsonDictionary;


@end
