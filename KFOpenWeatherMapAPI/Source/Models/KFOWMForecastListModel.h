//
//  KFForecastListModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  Provides conformation to the `KFOWMForecastListModel`.
 */
@protocol KFOWMForecastListModel @end

@class KFOWMMainWeatherModel;
@class KFOWMCloudModel;
@class KFOWMWindModel;
@class KFOWMSystemModel;

@protocol  KFOWMWeatherModel;


/**
 *  A wrapper containing a collection of `KFOWMWeatherModel` and some additional information.
 */
@interface KFOWMForecastListModel : JSONModel


/**
 *  The local date and time.
 */
@property (nonatomic, strong) NSDate *dt;


/**
 *  The current conditions.
 */
@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;


/**
 *  A list of weather conditions in 3 hour intervals.
 */
@property (nonatomic, strong) NSArray<KFOWMWeatherModel> *weather;


/**
 *  The cloud status
 */
@property (nonatomic, strong) KFOWMCloudModel *clouds;


/**
 *  The wind situation
 */
@property (nonatomic, strong) KFOWMWindModel *wind;


/**
 *  Additional information about the location.
 */
@property (nonatomic, strong) KFOWMSystemModel *systemInfo;


@end
