//
//  KFOWMCityModel.h
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

@class KFOWMCoordinateModel;

/**
 *  A collection of information about a city.
 */
@interface KFOWMCityModel : JSONModel


/**
 *  The OpenWeatherMap city id.
 */
@property (nonatomic, strong) NSNumber *cityId;


/**
 *  The name of the city.
 */
@property (nonatomic, strong) NSString *cityName;


/**
 *  The geo location of the city.
 */
@property (nonatomic) KFOWMCoordinateModel *coord;


/**
 *  The country assigned to the city.
 */
@property (nonatomic, strong) NSString *country;


/**
 *  The number of inhabitants.
 */
@property (nonatomic) NSUInteger population;


@end
