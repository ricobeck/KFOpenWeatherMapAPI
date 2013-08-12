//
//  KFOWMMainWeatherModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMMainWeatherModel.h"

@implementation KFOWMMainWeatherModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"temp" : @"temperature", @"temp_min" : @"temperatureMin", @"temp_max": @"temperatureMax", @"sea_level" : @"pressureSeaLevel", @"grnd_level" : @"pressureGroundLevel"}];
}


@end
