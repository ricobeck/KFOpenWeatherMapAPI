//
//  KFOWMMainWeatherModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@interface KFOWMMainWeatherModel : JSONModel


@property (nonatomic, strong) NSNumber *temperature;

@property (nonatomic, strong) NSNumber *humidity;

@property (nonatomic, strong) NSNumber *pressure;

@property (nonatomic, strong) NSNumber *temperatureMin;

@property (nonatomic, strong) NSNumber *temperatureMax;


@end
