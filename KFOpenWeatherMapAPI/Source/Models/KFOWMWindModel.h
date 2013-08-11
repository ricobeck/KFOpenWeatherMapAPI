//
//  KFOWMWindModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@interface KFOWMWindModel : JSONModel

@property (nonatomic, strong) NSNumber *speed;

@property (nonatomic, strong) NSNumber<Optional> *gust;

@property (nonatomic, strong) NSNumber *deg;

@end
