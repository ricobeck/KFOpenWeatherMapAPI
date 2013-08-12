//
//  KFOWMResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"
#import <CoreLocation/CoreLocation.h>

@class KFOWMMainWeatherModel;
@class KFOWMWindModel;
@class KFOWMSystemModel;
@class KFOWMCloudModel;
@class KFOWMCoordinateModel;


@protocol KFOWMWeatherModel;

/**
 *  A model representing the response of the current weather resource.
 */
@interface KFOWMWeatherResponseModel : JSONModel

/**
 *  The local date and time
 */
@property (nonatomic, strong) NSDate *dt;


/**
 *  The OpenWeatherMap city id.
 */
@property (nonatomic, strong) NSNumber *cityId;


/**
 *  The name of the city.
 */
@property (nonatomic, strong) NSString *cityName;


/**
 *  The latitude and longitude of the location.
 */
@property (nonatomic) KFOWMCoordinateModel *coord;


/**
 *  No information provided.
 */
@property (nonatomic, strong) NSString<Optional> *base;


/**
 *  The response code of the request.
 */
@property (nonatomic) NSNumber<Optional> *responseCode;


/**
 *  The main weather conditions.
 */
@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;


/**
 *  The wind conditions
 */
@property (nonatomic, strong) KFOWMWindModel *wind;


/**
 *  A list of `KFOWMWeatherModel`s.
 */
@property (nonatomic, strong) NSArray<KFOWMWeatherModel> *weather;


/**
 *  Additional information provided for the location.
 */
@property (nonatomic, strong) KFOWMSystemModel *systemInfo;


/**
 *  The cloud situation.
 */
@property (nonatomic, strong) KFOWMCloudModel *clouds;


@end
