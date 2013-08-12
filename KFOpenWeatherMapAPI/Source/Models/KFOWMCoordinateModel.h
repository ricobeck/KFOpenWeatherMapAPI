//
//  KFOWMCoordinateModel.h
//  KFOpenWeatherMapAPI
//
//  Created by Rico Becker on 8/11/13.
//  Copyright (c) 2013 KF Interactive. All rights reserved.
//

#import "JSONModel.h"
#import <CoreLocation/CoreLocation.h>

/**
 *  A model containing latitude and longitude of a location.
 */
@interface KFOWMCoordinateModel : JSONModel


/**
 *  The latutide for the location.
 */
@property (nonatomic) CLLocationDegrees latitude;


/**
 *  The longitude for the location.
 */
@property (nonatomic) CLLocationDegrees longitude;


/**
 *  Converts the data of this model into an CoreLocation coordinate
 *
 *  @return The location as a CoreLocation struct.
 */
- (CLLocationCoordinate2D)locationCoordinate;


@end
