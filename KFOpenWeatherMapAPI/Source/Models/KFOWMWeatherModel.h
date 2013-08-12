//
//  KFWeatherModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  Provides conformation to the `KFOWMWeatherModel`.
 */
@protocol KFOWMWeatherModel @end


/**
 *  Bundled information about weather.
 */
@interface KFOWMWeatherModel : JSONModel


/**
 *  The weather condition code. A list of codes can be found at http://bugs.openweathermap.org/projects/api/wiki/Weather_Condition_Codes
 */
@property (nonatomic, strong) NSNumber *weatherId;

/**
 *  A short title for the current conditions .
 */
@property (nonatomic, strong) NSString *main;


/**
 *  A more detailed description for the current condidions.
 */
@property (nonatomic, strong) NSString *weatherDescription;


/**
 *  The code for the icon.  A list of weather icon codes can be found at http://bugs.openweathermap.org/projects/api/wiki/Weather_Condition_Codes 
 */
@property (nonatomic, strong) NSString *icon;


@end
