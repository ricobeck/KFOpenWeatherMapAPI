//
//  KFOWMForecastTemperatureModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  A model containing forecast temperatures for different times of the day.
 */
@interface KFOWMForecastTemperatureModel : JSONModel


/**
 *  The temperature during the day.
 */
@property (nonatomic, strong) NSNumber *day;


/**
 *  The minimum temperature value.
 */
@property (nonatomic, strong) NSNumber *min;


/**
 *  The maximum temperature value.
 */
@property (nonatomic, strong) NSNumber *max;

/**
 *  The temperature at night.
 */
@property (nonatomic, strong) NSNumber *night;

/**
 *  The temperature at eve.
 */
@property (nonatomic, strong) NSNumber *eve;

/**
 *  The temperature in the morning.
 */
@property (nonatomic, strong) NSNumber *morning;


@end
