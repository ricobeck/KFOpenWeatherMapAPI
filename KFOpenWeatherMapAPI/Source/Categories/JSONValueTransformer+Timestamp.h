//
//  JSONValueTransformer+Timestamp.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
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
