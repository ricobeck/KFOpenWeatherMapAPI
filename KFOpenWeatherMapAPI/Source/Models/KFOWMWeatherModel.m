//
//  KFWeatherModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMWeatherModel.h"

@implementation KFOWMWeatherModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"id" : @"weatherId", @"description" : @"weatherDescription", @"main": @"mainWeather"}];
}



@end
