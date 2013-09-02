//
//  KFOpenWeatherMapAPIClient.m
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

#import "KFOpenWeatherMapAPIClient.h"
#import "KFOWMWeatherResponseModel.h"
#import "KFOWMForecastResponseModel.h"
#import "KFOWMDailyForecastResponseModel.h"
#import "KFOWMSearchResponseModel.h"

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


#pragma mark - Current weather


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
            resultBlock(NO, responseObject, error);
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


#pragma mark - 3-hour interval forecast


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
             resultBlock(NO, responseObject, error);
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


- (void)dailyForecastForParams:(NSDictionary *)params withResultBlock:(KFOWMResultBlock)resultBlock
{
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
            resultBlock(NO, responseObject, error);
        }
         
    }
    failure:^(AFHTTPRequestOperation *operation, NSError *error)
    {
        resultBlock(NO, nil, error);
    }];
}


- (void)dailyForecastForCityName:(NSString *)city numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"q": city, @"cnt": @(days)}];
    [self dailyForecastForParams:params withResultBlock:resultBlock];
}


- (void)dailyForecastForCityId:(NSString *)cityId numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"id": cityId, @"cnt": @(days)}];
    [self dailyForecastForParams:params withResultBlock:resultBlock];
}


- (void)dailyForecastForCoordinate:(CLLocationCoordinate2D)locationCoordinate numberOfDays:(NSUInteger)days withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSDictionary *params = [self parametersWithDictionary:@{@"lat": [NSString stringWithFormat:@"%f", locationCoordinate.latitude],@"lon": [NSString stringWithFormat:@"%f", locationCoordinate.longitude], @"cnt": @(days)}];
    [self dailyForecastForParams:params withResultBlock:resultBlock];
}


#pragma mark - Search


- (void)searchForPhrase:(NSString *)phrase numberOfResults:(NSUInteger)results withResultBlock:(KFOWMResultBlock)resultBlock
{
    [self searchForPhrase:phrase numberOfResults:results type:KFOWMSearchTypeLike withResultBlock:resultBlock];
}


- (void)searchForPhrase:(NSString *)phrase numberOfResults:(NSUInteger)results type:(KFOWMSearchType)searchType withResultBlock:(KFOWMResultBlock)resultBlock
{
    NSString *searchTypeValue;
    switch (searchType)
    {
        case KFOWMSearchTypeAccurat:
            searchTypeValue = @"accurate";
            break;
        case KFOWMSearchTypeLike:
        default:
            searchTypeValue = @"like";
            break;
    }
    
    
    NSDictionary *params = [self parametersWithDictionary:@{@"q": phrase, @"cnt": @(results), @"type": searchTypeValue}];
    [self getPath:@"find" parameters:params success:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         NSDictionary *responseDictionary = responseObject;
         NSError *error = nil;
         KFOWMSearchResponseModel *responseModel = [[KFOWMSearchResponseModel alloc] initWithDictionary:responseDictionary error:&error];
         
         if (error == nil)
         {
             resultBlock(YES, responseModel, nil);
         }
         else
         {
             resultBlock(NO, responseObject, error);
         }
         
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
    return @(kelvin.floatValue - 273.15f);
}


- (NSNumber *)kelvinToFahrenheit:(NSNumber *)kelvin
{
    return @((kelvin.floatValue * 9.0f/5.0f) - 459.67f);
}


@end
