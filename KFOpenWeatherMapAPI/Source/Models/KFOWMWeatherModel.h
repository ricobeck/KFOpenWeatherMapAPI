//
//  KFWeatherModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"


@protocol KFOWMWeatherModel @end


@interface KFOWMWeatherModel : JSONModel


@property (nonatomic, strong) NSNumber *weatherId;

@property (nonatomic, strong) NSString *main;

@property (nonatomic, strong) NSString *weatherDescription;

@property (nonatomic, strong) NSString *icon;


@end
