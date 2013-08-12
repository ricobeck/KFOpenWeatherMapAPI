//
//  KFOWMSearchResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/12/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"

@protocol KFOWMWeatherResponseModel;

/**
 *  A model representing the response of the search resource.
 */
@interface KFOWMSearchResponseModel : JSONModel

/**
 *  The response code of the request
 */
@property (nonatomic) NSUInteger responseCode;

/**
 *  A returned message from the api. Currently it looks like the net request time.
 */
@property (nonatomic) NSString *message;

/**
 *  The number of returned cities.
 */
@property (nonatomic) NSInteger count;


/**
 *  The list of cities containing `KFOWMWeatherResponseModel`s.
 */
@property (nonatomic, strong) NSArray<KFOWMWeatherResponseModel> *list;


@end
