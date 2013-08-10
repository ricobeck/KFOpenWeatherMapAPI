//
//  KFOWMResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMMainWeatherModel;
@class KFOWMWindModel;

@interface KFOWMResponseModel : JSONModel


@property (nonatomic, strong) NSDate *dt;

@property (nonatomic, strong) NSNumber *cityId;

@property (nonatomic, strong) NSString *cityName;

@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;

@property (nonatomic, strong) KFOWMWindModel *wind;



@end
