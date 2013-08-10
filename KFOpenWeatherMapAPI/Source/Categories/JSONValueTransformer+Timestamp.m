//
//  JSONValueTransformer+Timestamp.m
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONValueTransformer+Timestamp.h"

@implementation JSONValueTransformer (Timestamp)


-(NSDate *)NSDateFromNSNumber:(NSNumber *)timestamp
{
    return [NSDate dateWithTimeIntervalSince1970:timestamp.doubleValue];
}


-(id)NSNumberFromNSDate:(NSDate *)date
{
    return @([date timeIntervalSince1970]);
}


@end
