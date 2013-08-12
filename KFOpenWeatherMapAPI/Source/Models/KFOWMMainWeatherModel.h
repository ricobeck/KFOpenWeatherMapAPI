//
//  KFOWMMainWeatherModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  All information about weather conditions. 
 */
@interface KFOWMMainWeatherModel : JSONModel


/**
 *  The average temperature
 */
@property (nonatomic, strong) NSNumber *temperature;


/**
 *  The minimum temperature value.
 */
@property (nonatomic, strong) NSNumber *temperatureMin;


/**
 *  The maximum temperature value.
 */
@property (nonatomic, strong) NSNumber *temperatureMax;


/**
 *  The average air pressure.
 */
@property (nonatomic, strong) NSNumber *pressure;


/**
 *  The air pressure at sea level.
 */
@property (nonatomic, strong) NSNumber<Optional> *pressureSeaLevel;


/**
 *  The air pressure at ground level.
 */
@property (nonatomic, strong) NSNumber<Optional> *pressureGroundLevel;


/**
 *  The humidity value.
 */
@property (nonatomic, strong) NSNumber *humidity;


@end
