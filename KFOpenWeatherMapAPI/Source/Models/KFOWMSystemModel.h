//
//  KFOWMSystemModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@interface KFOWMSystemModel : JSONModel


@property (nonatomic, strong) NSString *country;

@property (nonatomic, strong) NSDate *sunrise;

@property (nonatomic, strong) NSDate *sunset;


@end
