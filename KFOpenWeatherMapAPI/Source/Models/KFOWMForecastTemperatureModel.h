//
//  KFOWMForecastTemperatureModel.h
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

/**
 *  A model containing forecast temperatures for different times of the day.
 */
@interface KFOWMForecastTemperatureModel : JSONModel


/**
 *  The temperature during the day.
 */
@property (nonatomic, strong) NSNumber *day;


/**
 *  The minimum temperature value.
 */
@property (nonatomic, strong) NSNumber *min;


/**
 *  The maximum temperature value.
 */
@property (nonatomic, strong) NSNumber *max;

/**
 *  The temperature at night.
 */
@property (nonatomic, strong) NSNumber *night;

/**
 *  The temperature at eve.
 */
@property (nonatomic, strong) NSNumber *eve;

/**
 *  The temperature in the morning.
 */
@property (nonatomic, strong) NSNumber *morning;


@end
