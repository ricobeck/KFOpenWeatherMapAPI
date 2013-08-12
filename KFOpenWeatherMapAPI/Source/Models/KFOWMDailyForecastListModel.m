//
//  KFOWMDailyForecastListModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMDailyForecastListModel.h"

@implementation KFOWMDailyForecastListModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"speed": @"windSpeed", @"gust" : @"windGust", @"deg" : @"windDeg", @"temp" : @"temperature"}];
}


@end
