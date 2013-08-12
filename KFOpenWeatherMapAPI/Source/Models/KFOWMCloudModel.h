//
//  KFOWMCloudModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  The current cloud situation of an location.
 */
@interface KFOWMCloudModel : JSONModel


/**
 *  The value of coverage.
 */
@property (nonatomic) NSUInteger all;


@end
