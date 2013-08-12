//
//  KFOWMForecastTemperatureModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"


@interface KFOWMForecastTemperatureModel : JSONModel


@property (nonatomic, strong) NSNumber *day;

@property (nonatomic, strong) NSNumber *min;

@property (nonatomic, strong) NSNumber *max;

@property (nonatomic, strong) NSNumber *night;

@property (nonatomic, strong) NSNumber *eve;

@property (nonatomic, strong) NSNumber *morning;


@end
