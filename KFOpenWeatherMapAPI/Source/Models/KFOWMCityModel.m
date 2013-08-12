//
//  KFOWMCityModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMCityModel.h"

@implementation KFOWMCityModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"id" : @"cityId", @"name" : @"cityName"}];
}


@end
