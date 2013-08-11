//
//  KFViewController.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "KFViewController.h"
#import "KFOpenWeatherMapAPIClient.h"

@interface KFViewController ()


@property (nonatomic, strong) KFOpenWeatherMapAPIClient *apiClient;


@end


@implementation KFViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.apiClient = [[KFOpenWeatherMapAPIClient alloc] initWithAPIKey:@"1111111111" andAPIVersion:@"2.5"];
    
    [self.apiClient weatherForCityName:@"Los Angeles" withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            NSLog(@"received weather: %@", responseData);
        }
        else
        {
            NSLog(@"could not get weather: %@", error);
        }
    }];
    
    /*
    [self.apiClient forecastForCityName:@"Los Angeles" withResultBlock:^(BOOL success, id responseData, NSError *error)
     {
         if (success)
         {
             NSLog(@"received forecast: %@", responseData);
         }
         else
         {
             NSLog(@"could not get forecast: %@", error);
         }
     }];
    
    [self.apiClient dailyForecastForCityName:@"Los Angeles" numberOfDays:4 withResultBlock:^(BOOL success, id responseData, NSError *error)
    {
        if (success)
        {
            NSLog(@"received daily forecast: %@", responseData);
        }
        else
        {
            NSLog(@"could not get daily forecast: %@", error);
        }
    }];
     */
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


@end
