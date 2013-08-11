//
//  JSONValueTransformer+Timestamp.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/10/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONValueTransformer.h"

@interface JSONValueTransformer (Timestamp)


-(NSDate *)NSDateFromNSNumber:(NSNumber *)timestamp;

-(id)NSNumberFromNSDate:(NSDate *)date;


@end
