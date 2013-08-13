//
//  KFOWMResponseModel.h
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
#import <CoreLocation/CoreLocation.h>

@class KFOWMMainWeatherModel;
@class KFOWMWindModel;
@class KFOWMSystemModel;
@class KFOWMCloudModel;
@class KFOWMCoordinateModel;


@protocol KFOWMWeatherModel;

/**
 *  A model representing the response of the current weather resource.
 */
@interface KFOWMWeatherResponseModel : JSONModel

/**
 *  The local date and time
 */
@property (nonatomic, strong) NSDate *dt;


/**
 *  The OpenWeatherMap city id.
 */
@property (nonatomic, strong) NSNumber *cityId;


/**
 *  The name of the city.
 */
@property (nonatomic, strong) NSString *cityName;


/**
 *  The latitude and longitude of the location.
 */
@property (nonatomic) KFOWMCoordinateModel *coord;


/**
 *  No information provided.
 */
@property (nonatomic, strong) NSString<Optional> *base;


/**
 *  The response code of the request.
 */
@property (nonatomic) NSNumber<Optional> *responseCode;


/**
 *  The main weather conditions.
 */
@property (nonatomic, strong) KFOWMMainWeatherModel *mainWeather;


/**
 *  The wind conditions
 */
@property (nonatomic, strong) KFOWMWindModel *wind;


/**
 *  A list of `KFOWMWeatherModel`s.
 */
@property (nonatomic, strong) NSArray<KFOWMWeatherModel> *weather;


/**
 *  Additional information provided for the location.
 */
@property (nonatomic, strong) KFOWMSystemModel *systemInfo;


/**
 *  The cloud situation.
 */
@property (nonatomic, strong) KFOWMCloudModel *clouds;


@end
