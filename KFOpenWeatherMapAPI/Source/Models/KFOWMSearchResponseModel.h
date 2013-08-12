//
//  KFOWMSearchResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/12/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@protocol KFOWMWeatherResponseModel;


@interface KFOWMSearchResponseModel : JSONModel


@property (nonatomic) NSUInteger responseCode;

@property (nonatomic) NSString *message;

@property (nonatomic) NSInteger count;

@property (nonatomic, strong) NSArray<KFOWMWeatherResponseModel> *list;


@end
