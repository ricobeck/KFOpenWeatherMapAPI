//
//  KFOWMResponseModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMWeatherResponseModel.h"

@implementation KFOWMWeatherResponseModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"id" : @"cityId", @"name" : @"cityName", @"main": @"mainWeather", @"sys" : @"systemInfo", @"cod" : @"responseCode"}];
}


@end
