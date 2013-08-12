//
//  KFOWMSystemModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

/**
 *  Contains information about a specific location.
 */
@interface KFOWMSystemModel : JSONModel


/**
 *  The country of the location.
 */
@property (nonatomic, strong) NSString<Optional> *country;


/**
 *  The moment of sunrise.
 */
@property (nonatomic, strong) NSDate<Optional> *sunrise;


/**
 *  The moment of sunset.
 */
@property (nonatomic, strong) NSDate<Optional> *sunset;

/**
 *  No information available.
 */
@property (nonatomic, strong) NSString<Optional> *pod;

@end
