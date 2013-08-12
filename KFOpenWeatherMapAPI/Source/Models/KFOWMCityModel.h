//
//  KFOWMCityModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMCoordinateModel;


@interface KFOWMCityModel : JSONModel


@property (nonatomic, strong) NSNumber *cityId;

@property (nonatomic, strong) NSString *cityName;

@property (nonatomic) KFOWMCoordinateModel *coord;

@property (nonatomic, strong) NSString *country;

@property (nonatomic) NSUInteger population;


@end
