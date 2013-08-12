//
//  KFOpenWeatherMapAPIClient.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
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


@interface KFOpenWeatherMapAPIClient : AFHTTPClient


@property (nonatomic) KFOWMTemperatureType temperatureType;

@property (nonatomic) KFOWMMUnitType unitType;

@property (nonatomic, strong) NSString *language;


- (id)initWithAPIKey:(NSString *)apiKey andAPIVersion:(NSString *)apiVersion;


- (void)weatherForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)weatherForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)weatherForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock;


- (void)forecastForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)forecastForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)forecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock;


- (void)dailyForecastForCityName:(NSString *)city numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)dailyForecastForCityId:(NSString *)cityId numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;

- (void)dailyForecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock;


- (void)searchForPhrase:(NSString *)phrase numberOfResults:(NSUInteger)results withResultBlock:(KFOWMResultBlock)resultBlock;




@end
