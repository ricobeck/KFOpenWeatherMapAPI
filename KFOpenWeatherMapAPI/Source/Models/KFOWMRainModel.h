//
//  KFOWMRainModel.h
//  KFOpenWeatherMapAPI
//
//  Created by rick on 14/08/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@interface KFOWMRainModel : JSONModel

/**
 *  Amount of rain in the next three hours.
 */
@property (nonatomic, strong) NSNumber *next3h;


@end
