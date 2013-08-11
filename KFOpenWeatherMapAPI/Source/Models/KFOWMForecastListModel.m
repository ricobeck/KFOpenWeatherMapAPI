//
//  KFForecastListModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMForecastListModel.h"

@implementation KFOWMForecastListModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"main": @"mainWeather", @"sys" : @"systemInfo"}];
}


@end
