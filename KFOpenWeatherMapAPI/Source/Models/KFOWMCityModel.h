//
//  KFOWMCityModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@class KFOWMCoordinateModel;

/**
 *  A collection of information about a city.
 */
@interface KFOWMCityModel : JSONModel


/**
 *  The OpenWeatherMap city id.
 */
@property (nonatomic, strong) NSNumber *cityId;


/**
 *  The name of the city.
 */
@property (nonatomic, strong) NSString *cityName;


/**
 *  The geo location of the city.
 */
@property (nonatomic) KFOWMCoordinateModel *coord;


/**
 *  The country assigned to the city.
 */
@property (nonatomic, strong) NSString *country;


/**
 *  The number of inhabitants.
 */
@property (nonatomic) NSUInteger population;


@end
