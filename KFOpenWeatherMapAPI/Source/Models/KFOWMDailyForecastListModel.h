//
//  KFOWMDailyForecastListModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMForecastTemperatureModel;


@interface KFOWMDailyForecastListModel : JSONModel


@property (nonatomic, strong) NSDate *dt;

@property (nonatomic, strong) NSNumber *pressure;

@property (nonatomic, strong) NSNumber *humidity;

@property (nonatomic, strong) NSNumber *windSpeed;

@property (nonatomic, strong) NSNumber<Optional> *windGust;

@property (nonatomic, strong) NSNumber *windDeg;

@property (nonatomic, strong) KFOWMForecastTemperatureModel *temperature;


@end
