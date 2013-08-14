//
//  KFOWMRainModel.m
//  KFOpenWeatherMapAPI
//
//  Created by rick on 14/08/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMRainModel.h"

@implementation KFOWMRainModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"3h" : @"next3h"}];
}


@end
