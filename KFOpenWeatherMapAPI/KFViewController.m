//
//  KFViewController.m
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

#import "KFViewController.h"
#import "KFOpenWeatherMapAPIClient.h"

#import "KFOWMWeatherResponseModel.h"
#import "KFOWMMainWeatherModel.h"
#import "KFOWMWeatherModel.h"
#import "KFOWMForecastResponseModel.h"
#import "KFOWMCityModel.h"
#import "KFOWMDailyForecastResponseModel.h"
#import "KFOWMDailyForecastListModel.h"
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
            
            KFOWMDailyForecastListModel *listModel = responseModel.list[0];
            KFOWMWeatherModel *weatherModel = listModel.weather[0];
            NSLog(@"daily forecast first day weather icon: %@", weatherModel.icon);
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
