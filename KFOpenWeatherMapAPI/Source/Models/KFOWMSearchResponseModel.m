//
//  KFOWMSearchResponseModel.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/12/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOWMSearchResponseModel.h"

@implementation KFOWMSearchResponseModel


+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"cod" : @"responseCode"}];
}


@end
