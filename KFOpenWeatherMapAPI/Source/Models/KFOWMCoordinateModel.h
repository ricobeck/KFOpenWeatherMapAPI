//
//  KFOWMCoordinateModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"
#import <CoreLocation/CoreLocation.h>


@interface KFOWMCoordinateModel : JSONModel


@property (nonatomic) CLLocationDegrees latitude;

@property (nonatomic) CLLocationDegrees longitude;


- (CLLocationCoordinate2D)locationCoordinate;


@end
