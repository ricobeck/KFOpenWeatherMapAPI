//
//  KFViewController.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFViewController.h"
#import "KFOpenWeatherMapAPIClient.h"

#import "KFOWMWeatherResponseModel.h"
#import "KFOWMMainWeatherModel.h"
#import "KFOWMForecastResponseModel.h"
#import "KFOWMCityModel.h"
#import "KFOWMDailyForecastResponseModel.h"
#import "KFOWMSearchResponseModel.h"
#import "KFOWMSystemModel.h"


@interface KFViewController ()


@property (nonatomic, strong) KFOpenWeatherMapAPIClient *apiClient;


@end


@implementation KFViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.apiClient = [[KFOpenWeatherMapAPIClient alloc] initWithAPIKey:@"1111111111" andAPIVersion:@"2.5"];
    
    [self.apiClient weatherForCityName:@"Leipzig" withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            KFOWMWeatherResponseModel *responseModel = (KFOWMWeatherResponseModel *)responseData;
            NSLog(@"received weather: %@, temperature: %@ K, %@%%rH, %@ mbar", responseModel.cityName, responseModel.mainWeather.temperature, responseModel.mainWeather.humidity, responseModel.mainWeather.pressure);
        }
        else
        {
            NSLog(@"could not get weather: %@", error);
        }
    }];
     
    [self.apiClient forecastForCityName:@"Leipzig" withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            KFOWMForecastResponseModel *responseModel = (KFOWMForecastResponseModel *)responseData;
            
            NSString *humidity = [[responseModel.list valueForKeyPath:@"mainWeather.humidity"] componentsJoinedByString:@"%rH, "];
            NSLog(@"received forecast: %@, humidity: %@", responseModel.city.cityName, humidity);
        }
        else
        {
            NSLog(@"could not get forecast: %@", error);
        }
    }];

    
    [self.apiClient dailyForecastForCityName:@"Leipzig" numberOfDays:4 withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            KFOWMDailyForecastResponseModel *responseModel = (KFOWMDailyForecastResponseModel *)responseData;
            NSLog(@"received daily forecast: %@, %@", responseModel.city.cityName, [[responseModel.list valueForKeyPath:@"temperature.day"] componentsJoinedByString:@" K, "]);
        }
        else
        {
            NSLog(@"could not get daily forecast: %@", error);
        }
    }];
    
    [self.apiClient searchForPhrase:@"London" numberOfResults:10 withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            KFOWMSearchResponseModel *responseModel = (KFOWMSearchResponseModel *)responseData;
            NSMutableArray *foundCities = [NSMutableArray new];
            for (KFOWMWeatherResponseModel *listModel in responseModel.list)
            {
                NSString *city = [NSString stringWithFormat:@"%@, %@", listModel.cityName, listModel.systemInfo.country];
                [foundCities addObject:city];
            }
            NSLog(@"search results: %@", [foundCities componentsJoinedByString:@", "]);
        }
        else
        {
            NSLog(@"could not get search results: %@", error);
        }
    }];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


@end
