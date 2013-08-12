//
//  KFOWMDailyForecastListModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMForecastTemperatureModel;

/**
 *  Contains all forecast data.
 */
@interface KFOWMDailyForecastListModel : JSONModel


/**
 *  The local date and time.
 */
@property (nonatomic, strong) NSDate *dt;


/**
 *  The air pressure.
 */
@property (nonatomic, strong) NSNumber *pressure;


/**
 *  The humidity value.
 */
@property (nonatomic, strong) NSNumber *humidity;


/**
 *  The wind speed.
 */
@property (nonatomic, strong) NSNumber *windSpeed;

/**
 *  The wind gust.
 */
@property (nonatomic, strong) NSNumber<Optional> *windGust;


/**
 *  The wind direction in degrees.
 */
@property (nonatomic, strong) NSNumber *windDeg;


/**
 *  A collection of temperatures during the day.
 */
@property (nonatomic, strong) KFOWMForecastTemperatureModel *temperature;


@end
