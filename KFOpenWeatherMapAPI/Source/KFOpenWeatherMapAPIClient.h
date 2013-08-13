//
//  KFOpenWeatherMapAPIClient.h
//  KFOpenWeatherMapAPI
//
//  Copyright (c) 2013 Rico Becker, KF Interactive
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//


#import "AFHTTPClient.h"
#import <CoreLocation/CoreLocation.h>


typedef void(^KFOWMResultBlock)(BOOL success, id responseData, NSError *error);


typedef NS_ENUM(NSUInteger, KFOWMTemperatureType)
{
    KFOWMTemperatureTypeKelvin,
    KFOWMTemperatureTypeCelcius,
    KFOWMTemperatureTypeFahrenheit
};


typedef NS_ENUM(NSUInteger, KFOWMMUnitType)
{
    KFOWMUnitTypeMetric,
    KFOWMUnitTypeImperial
};

/**
 *  A client connecting to the OpenWeatherMap API for fetching current weather, interval/daily forecasts, and searching cities.
 */
@interface KFOpenWeatherMapAPIClient : AFHTTPClient

/**
 *  Target temperature unit when converting returned basic kelvin values. Possible values are `KFOWMTemperatureTypeKelvin`, `KFOWMTemperatureTypeCelcius`, and `KFOWMTemperatureTypeFahrenheit`.
 */
@property (nonatomic) KFOWMTemperatureType temperatureType;


/**
 *  Unit of distance values. Possible values are `KFOWMUnitTypeMetric` and `KFOWMUnitTypeImperial`.
 */
@property (nonatomic) KFOWMMUnitType unitType;

/**
 *	The language send to get localised results
 */
@property (nonatomic, strong) NSString *language;


/**
 *	Designated initializer for setting up the client with API key and version.
 *
 *	@param	apiKey	The obtained API key from http://openweathermap.org/login
 *	@param	apiVersion	The version of the API to use.
 *
 *	@return	A ready client
 */
- (id)initWithAPIKey:(NSString *)apiKey andAPIVersion:(NSString *)apiVersion;


#pragma mark - Current weather
/** @name Requesting current weather data */


/**
 *	Request the current weather for a city by its name.
 *
 *	@param	city	The name of the city.
 *	@param	resultBlock	Result containing success, parsed `KFOWMWeatherResponseModel`, and/or ocurred error.
 */
- (void)weatherForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Request the current weather for a city by its id.
 *
 *	@param	cityId	The OpenWeatherMap-id of the city.
 *	@param	resultBlock	Result containing success, parsed `KFOWMWeatherResponseModel`, and/or ocurred error.
 */
- (void)weatherForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Request the current weather for a city by its geo coordinate.
 *
 *	@param	locationCoordinate	A location to use.
 *	@param	resultBlock	Result containing success, parsed `KFOWMWeatherResponseModel`, and/or ocurred error.
 */
- (void)weatherForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock;


#pragma mark - 3-hour interval forecast
/** @name Requesting 3-hour interval forecast data */


/**
 *	Gets the forecast of an city by its name in 3 hour intervals.
 *
 *	@param	city    The name of the city.
 *	@param	resultBlock	Result containing success, parsed `KFOWMForecastResponseModel`, and/or ocurred error.
 */
- (void)forecastForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Gets the forecast of an city by its id in 3 hour intervals.
 *
 *	@param	cityId	The OpenWeatherMap-id of the city.
 *	@param	resultBlock	Result containing success, parsed `KFOWMWeatherResponseModel`, and/or ocurred error.
 */
- (void)forecastForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Gets the forecast of an city by its location in 3 hour intervals.
 *
 *	@param	locationCoordinate  A location to use.
 *	@param	resultBlock	Result containing success, parsed `KFOWMWeatherResponseModel`, and/or ocurred error.
 */
- (void)forecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock;


#pragma mark - Daily forecast
/** @name Requesting daily forecast data */

/**
 *	Gets the forecast of an city by its name for a given number of days. range is from 1 to 14.
 *
 *	@param	city    The name of the city.
 *	@param	days    The number of days to request.
 *	@param	resultBlock	Result containing success, parsed `KFOWMDailyForecastResponseModel`, and/or ocurred error.
 */
- (void)dailyForecastForCityName:(NSString *)city numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Gets the forecast of an city by its id for a given number of days. range is from 1 to 14.
 *
 *	@param	cityId	The OpenWeatherMap-id of the city.
 *	@param	days    The number of days to request.
 *	@param	resultBlock	Result containing success, parsed `KFOWMDailyForecastResponseModel`, and/or ocurred error.
 */
- (void)dailyForecastForCityId:(NSString *)cityId numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;

/**
 *	Gets the forecast of an city by its location for a given number of days. range is from 1 to 14.
 *
 *	@param	locationCoordinate	A location to use.
 *	@param	days	The number of days to request.
 *	@param	resultBlock	Result containing success, parsed `KFOWMDailyForecastResponseModel`, and/or ocurred error.
 */
- (void)dailyForecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;


#pragma mark - Search
/** @name Search for a city. */


/**
 *	Searches for a phrase and returns a list of matching cities.
 *
 *	@param	phrase	The phrase to search for
 *	@param	results	Limits the number of results
 *	@param	resultBlock	Result containing success, parsed `KFOWMSearchResponseModel`, and/or ocurred error.
 */
- (void)searchForPhrase:(NSString *)phrase numberOfResults:(NSUInteger)results withResultBlock:(KFOWMResultBlock)resultBlock;


@end
