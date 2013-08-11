//
//  KFOWMCoordinateModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMCoordinateModel.h"

@implementation KFOWMCoordinateModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"lat" : @"latitude", @"lon" : @"longitude"}];
}


- (CLLocationCoordinate2D)locationCoordinate
{
    CLLocationCoordinate2D locationCoordinate;
    locationCoordinate.latitude = self.latitude;
    locationCoordinate.longitude = self.longitude;
    
    return locationCoordinate;
}


@end
