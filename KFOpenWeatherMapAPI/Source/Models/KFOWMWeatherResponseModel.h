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


@interface KFOWMWeatherResponseModel : JSONModel


@property (nonatomic, strong) NSDate *dt;

@property (nonatomic, strong) NSNumber *cityId;

@property (nonatomic, strong) NSString *cityName;

@property (nonatomic) KFOWMCoordinateModel *coord;

@property (nonatomic, strong) NSString<Optional> *base;

@property (nonatomic) NSNumber<Optional> *responseCode;

@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;

@property (nonatomic, strong) KFOWMWindModel *wind;

@property (nonatomic, strong) NSArray<KFOWMWeatherModel> *weather;

@property (nonatomic, strong) KFOWMSystemModel *systemInfo;

@property (nonatomic, strong) KFOWMCloudModel *clouds;


@end
