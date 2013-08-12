//
//  KFOWMWindModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  A collection of wind information.
 */
@interface KFOWMWindModel : JSONModel


/**
 *  The wind speed.
 */
@property (nonatomic, strong) NSNumber *speed;

/**
 *  The wind gust.
 */
@property (nonatomic, strong) NSNumber<Optional> *gust;


/**
 *  The direction of the wind in degrees. Can get mapped to wind directions.
 */
@property (nonatomic, strong) NSNumber *deg;


@end
