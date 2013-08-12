//
//  KFOWMDailyForecastResponseModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMDailyForecastResponseModel.h"

@implementation KFOWMDailyForecastResponseModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"cod" : @"responseCode", @"cnt" : @"count"}];
}


@end
