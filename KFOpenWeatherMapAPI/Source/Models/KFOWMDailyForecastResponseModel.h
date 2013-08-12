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

/**
 *  A model representing the response of the daily forecast resource.
 */
@interface KFOWMDailyForecastResponseModel : JSONModel


/**
 *  The response code of the request.
 */
@property (nonatomic) NSUInteger responseCode;

/**
 *  A returned message from the api. Currently it looks like the net request time.
 */
@property (nonatomic) NSString *message;

/**
 *  The number of returned days.
 */
@property (nonatomic) NSInteger count;

/**
 *  A `KFOWMCityModel` containing additional information about the requested city.
 */
@property (nonatomic, strong) KFOWMCityModel *city;


/**
 *  A list of `KFOWMDailyForecastListModel`.
 */
@property (nonatomic, strong) NSArray<KFOWMDailyForecastListModel> *list;


@end
