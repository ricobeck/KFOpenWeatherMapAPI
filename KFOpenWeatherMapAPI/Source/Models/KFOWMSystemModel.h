//
//  KFOWMSystemModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@interface KFOWMSystemModel : JSONModel


@property (nonatomic, strong) NSString<Optional> *country;

@property (nonatomic, strong) NSDate<Optional> *sunrise;

@property (nonatomic, strong) NSDate<Optional> *sunset;

@property (nonatomic, strong) NSString<Optional> *pod;

@end
