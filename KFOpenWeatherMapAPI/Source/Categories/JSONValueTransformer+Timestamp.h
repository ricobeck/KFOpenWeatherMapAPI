//
//  JSONValueTransformer+Timestamp.h
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

#import "JSONValueTransformer.h"

/**
 *  Provides methods for transforming timestamps into `NSDate`s and vice versa.
 */
@interface JSONValueTransformer (Timestamp)

/**
 *  Converts an UNIX timestamp into an `NSDate`.
 *
 *  @param timestamp Seconds since 01.01.1970.
 *
 *  @return A `NSDate` with a time interval since 1970.
 */
-(NSDate *)NSDateFromNSNumber:(NSNumber *)timestamp;

/**
 *  Converts a `NSDate` into seconds since 01.01.1970
 *
 *  @param date The date for calculation.
 *
 *  @return Passed seconds since 01.01.1970.
 */
-(id)NSNumberFromNSDate:(NSDate *)date;


@end
