//
//  KFOWMForecastResponseModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMForecastResponseModel.h"

@implementation KFOWMForecastResponseModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"cod" : @"responseCode"}];
}


@end
