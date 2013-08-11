//
//  KFForecastListModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@protocol KFOWMForecastListModel @end

@class KFOWMMainWeatherModel;
@class KFOWMCloudModel;
@class KFOWMWindModel;
@class KFOWMSystemModel;

@protocol  KFOWMWeatherModel;


@interface KFOWMForecastListModel : JSONModel


@property (nonatomic, strong) NSDate *dt;

@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;

@property (nonatomic, strong) NSArray<KFOWMWeatherModel> *weather;

@property (nonatomic, strong) KFOWMCloudModel *clouds;

@property (nonatomic, strong) KFOWMWindModel *wind;

@property (nonatomic, strong) KFOWMSystemModel *systemInfo;


@end
