//
//  KFOWMDailyForecastResponseModel.h
//  KFOpenWeatherMapAPI
//
//  Copyright (c) 2013 Rico Becker, KF Interactive
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import "JSONModel.h"

@class KFOWMCityModel;

@protocol KFOWMDailyForecastListModel;

/**
 *  A model representing the response of the daily forecast resource.
 */
@interface KFOWMDailyForecastResponseModel : JSONModel


/**
 *  The response code of the request.
 */
@property (nonatomic) NSUInteger responseCode;

/**
 *  A returned message from the api. Currently it looks like the net request time.
 */
@property (nonatomic) NSString *message;

/**
 *  The number of returned days.
 */
@property (nonatomic) NSInteger count;

/**
 *  A `KFOWMCityModel` containing additional information about the requested city.
 */
@property (nonatomic, strong) KFOWMCityModel *city;


/**
 *  A list of `KFOWMDailyForecastListModel`.
 */
@property (nonatomic, strong) NSArray<KFOWMDailyForecastListModel> *list;


@end
