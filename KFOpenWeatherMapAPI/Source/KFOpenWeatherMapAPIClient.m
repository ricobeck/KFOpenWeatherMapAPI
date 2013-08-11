//
//  KFOpenWeatherMapAPIClient.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFOpenWeatherMapAPIClient.h"
#import "KFOWMWeatherResponseModel.h"
#import "KFOWMForecastResponseModel.h"
#import "KFOWMDailyForecastResponseModel.h"

#import <AFNetworking/AFNetworking.h>


@interface KFOpenWeatherMapAPIClient ()


@property (nonatomic, strong) NSString *apiKey;

@property (nonatomic, strong) NSString *apiVersion;


@end


@implementation KFOpenWeatherMapAPIClient


- (id)initWithAPIKey:(NSString *)apiKey andAPIVersion:(NSString *)apiVersion
{
    self = [super initWithBaseURL:[NSURL URLWithString:[NSString stringWithFormat:@"http://api.openweathermap.org/data/%@", apiVersion]]];
    if (self)
    {
        [self registerHTTPOperationClass:[AFJSONRequestOperation class]];
        
        self.apiKey = apiKey;
        self.apiVersion = apiVersion;
        self.language = [self valueForPreferredLanguage];
        
        self.temperatureType = KFOWMTemperatureTypeCelcius;
        [self setDefaultHeader:@"x-api-key" value:self.apiKey];
        [self setDefaultHeader:@"Accept" value:@"application/json; charset=utf-8"];
    }
    return self;
}


#pragma mark - API calls for current weather


- (void)weatherForParams:(NSDictionary *)params withResultBlock:(KFOWMResultBlock)resultBlock
{
    [self getPath:@"weather" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
    {
        NSDictionary *responseDictionary = responseObject;
        NSError *error = nil;
        KFOWMWeatherResponseModel *responseModel = [[KFOWMWeatherResponseModel alloc] initWithDictionary:responseDictionary error:&error];
         
        if (error == nil)
        {
            resultBlock(YES, responseModel, nil);
        }
        else
        {
            resultBlock(YES, responseObject, error);
        }
         
    }
        failure:^(AFHTTPRequestOperation *operation, NSError *error)
    {
        resultBlock(NO, nil, error);
    }];
}


- (void)weatherForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"q": city}];
    [self weatherForParams:params withResultBlock:resultBlock];
}


- (void)weatherForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"id": cityId}];
    [self weatherForParams:params withResultBlock:resultBlock];
}


- (void)weatherForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"lat": [NSString stringWithFormat:@"%f", locationCoordinate.latitude],@"lon": [NSString stringWithFormat:@"%f", locationCoordinate.longitude]}];
    [self weatherForParams:params withResultBlock:resultBlock];
}


#pragma mark - 3 hour forecast


- (void)forecastForParams:(NSDictionary *)params withResultBlock:(KFOWMResultBlock)resultBlock
{
    [self getPath:@"forecast" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
    {
         NSDictionary *responseDictionary = responseObject;
         NSError *error = nil;
         KFOWMForecastResponseModel *responseModel = [[KFOWMForecastResponseModel alloc] initWithDictionary:responseDictionary error:&error];
         
         if (error == nil)
         {
             resultBlock(YES, responseModel, nil);
         }
         else
         {
             resultBlock(YES, responseObject, error);
         }
         
     }
     failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         resultBlock(NO, nil, error);
     }];
}

- (void)forecastForCityName:(NSString *)city withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"q": city}];
    [self forecastForParams:params withResultBlock:resultBlock];
}


- (void)forecastForCityId:(NSString *)cityId withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"id": cityId}];
    [self forecastForParams:params withResultBlock:resultBlock];
}


- (void)forecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"lat": [NSString stringWithFormat:@"%f", locationCoordinate.latitude],@"lon": [NSString stringWithFormat:@"%f", locationCoordinate.longitude]}];
    [self forecastForParams:params withResultBlock:resultBlock];
}


#pragma mark - Daily forecast


- (void)dailyForecastForCityName:(NSString *)city numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"q": city, @"cnt": @(days)}];
    [self getPath:@"forecast/daily" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         NSDictionary *responseDictionary = responseObject;
         NSError *error = nil;
         KFOWMDailyForecastResponseModel *responseModel = [[KFOWMDailyForecastResponseModel alloc] initWithDictionary:responseDictionary error:&error];
         
         if (error == nil)
         {
             resultBlock(YES, responseModel, nil);
         }
         else
         {
             resultBlock(YES, responseObject, error);
         }
     }
          failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         resultBlock(NO, nil, error);
     }];
}


- (void)dailyForecastForCityId:(NSString *)cityId numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"id": cityId, @"cnt": @(days)}];
    [self getPath:@"forecast/daily" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         resultBlock(YES, responseObject, nil);
     }
          failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         resultBlock(NO, nil, error);
     }];
}


- (void)dailyForecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"lat": [NSString stringWithFormat:@"%f", locationCoordinate.latitude],@"lon": [NSString stringWithFormat:@"%f", locationCoordinate.longitude], @"cnt": @(days)}];
    [self getPath:@"forecast/daily" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         resultBlock(YES, responseObject, nil);
     }
          failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         resultBlock(NO, nil, error);
     }];
}


#pragma mark - Request Parameters


- (NSDictionary *)parametersWithDictionary:(NSDictionary *)parameters
{
    NSMutableDictionary *finalizedParameters = [NSMutableDictionary dictionaryWithDictionary:@{@"lang": self.language, @"unit" : [self valueForUnitType:self.unitType]}];
    [finalizedParameters addEntriesFromDictionary:parameters];
    return [finalizedParameters copy];
}


- (NSString *)valueForUnitType:(KFOWMMUnitType)unitType
{
    switch (unitType)
    {
        case KFOWMUnitTypeMetric:
            return @"metric";
            break;
        case KFOWMUnitTypeImperial:
            return @"imperial";
            break;
    }
}


- (NSString *)valueForPreferredLanguage
{
    NSDictionary *languageMap = languageMap = @{@"es":@"sp", @"en-GB":@"en", @"pt-PT":@"pt", @"sv":@"se", @"uk":@"ua", @"zh-Hans":@"zh_cn", @"zh-Hant":@"zh_tw"};

    NSString *language = [[NSLocale preferredLanguages] objectAtIndex:0];
    if (languageMap[language] != nil)
    {
        language = languageMap[language];
    }
    return language;
}


#pragma mark - Conversions


- (NSNumber *)kelvinToCelcius:(NSNumber *)kelvin
{
    return @(kelvin.floatValue - 273.15);
}


- (NSNumber *)kelvinToFahrenheit:(NSNumber *)kelvin
{
    return @((kelvin.floatValue * 9/5) - 459.67);
}


@end
