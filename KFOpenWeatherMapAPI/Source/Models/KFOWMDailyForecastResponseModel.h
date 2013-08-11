//
//  KFOWMDailyForecastResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMCityModel;

@protocol KFOWMDailyForecastListModel;


@interface KFOWMDailyForecastResponseModel : JSONModel


@property (nonatomic) NSUInteger responseCode;

@property (nonatomic) NSString *message;

@property (nonatomic) NSInteger cnt;

@property (nonatomic, strong) KFOWMCityModel *city;

@property (nonatomic, strong) NSArray<KFOWMDailyForecastListModel> *list;


@end
