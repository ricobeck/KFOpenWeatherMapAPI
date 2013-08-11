//
//  KFOWMForecastTemperatureModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMForecastTemperatureModel.h"

@implementation KFOWMForecastTemperatureModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"morn": @"morning"}];
}


@end
