//
//  KFWeatherModel.h
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
 *  Provides conformation to the `KFOWMWeatherModel`.
 */
@protocol KFOWMWeatherModel @end


/**
 *  Bundled information about weather.
 */
@interface KFOWMWeatherModel : JSONModel


/**
 *  The weather condition code. A list of codes can be found at http://bugs.openweathermap.org/projects/api/wiki/Weather_Condition_Codes
 */
@property (nonatomic, strong) NSNumber *weatherId;

/**
 *  A short title for the current conditions .
 */
@property (nonatomic, strong) NSString *main;


/**
 *  A more detailed description for the current condidions.
 */
@property (nonatomic, strong) NSString *weatherDescription;


/**
 *  The code for the icon.  A list of weather icon codes can be found at http://bugs.openweathermap.org/projects/api/wiki/Weather_Condition_Codes 
 */
@property (nonatomic, strong) NSString *icon;


@end
