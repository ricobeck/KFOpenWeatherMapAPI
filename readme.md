#KFOpenWeatherMapAPI Client

A client connecting to the OpenWeatherMap API for fetching current weather data, interval/daily forecasts, and searching cities.

#Usage
Add
```
pod KFOpenWeatherMapAPI
```
to your podfile and run
```
pod install
```

Initialize the client with your API key obtained from http://openweathermap.org/login and an api version (currently 2.5):

```obj-c
self.apiClient = [[KFOpenWeatherMapAPIClient alloc] initWithAPIKey:@"1111111111" andAPIVersion:@"2.5"];
```
for a full documentation see http://docs.kf-interactive.com/KFOpenWeatherMapAPI

You can request weather data for a city by its name, its OpenWeatherMap city id, or by its geo location. For more acurate results you can 
#Examples
##Current Weather
For requesting the current weather for Los Angeles use:
```obj-c
[self.apiClient weatherForCityName:@"Los Angeles" withResultBlock:^(BOOL success, id responseData, NSError *error)
{
    if (success)
    {
        KFOWMWeatherResponseModel *responseModel = (KFOWMWeatherResponseModel *)responseData;
        NSLog(@"received weather: %@, temperature: %@ K, %@%%rH, %@ mbar", responseModel.cityName, responseModel.mainWeather.temperature, responseModel.mainWeather.humidity, responseModel.mainWeather.pressure);
    }
    else
    {
        NSLog(@"could not get weather: %@", error);
    }
}];
```
This will return a `KFOWMWeatherResponseModel` including all data from the api parsed as native objects:  
**KFOpenWeatherMapAPI[6102:c07] received weather: Los Angeles, temperature: 292.65 K, 71%rH, 1011 mbar**

##Forecast

To get the forecast for Los Angeles for the next hours call
```obj-c
[self.apiClient forecastForCityName:@"Los Angeles" withResultBlock:^(BOOL success, id responseData, NSError *error)
{
    if (success)
    {
        KFOWMForecastResponseModel *responseModel = (KFOWMForecastResponseModel *)responseData;
        
        NSString *humidity = [[responseModel.list valueForKeyPath:@"mainWeather.humidity"] componentsJoinedByString:@"%rH, "];
        NSLog(@"received forecast: %@, humidity: %@", responseModel.city.cityName, humidity);
    }
    else
    {
        NSLog(@"could not get forecast: %@", error);
    }
}];
```
and you get a `KFOWMForecastResponseModel`:  
**KFOpenWeatherMapAPI[6448:c07] received forecast: Los Angeles, humidity: 80%rH, 70%rH, 67%rH, 66%rH, …**

##Daily Forecast

For getting a daily forecast for 4 days for Los Angeles use
```obj-c
[self.apiClient dailyForecastForCityName:@"Los Angeles" numberOfDays:4 withResultBlock:^(BOOL success, id responseData, NSError *error)
{
    if (success)
    {
        KFOWMDailyForecastResponseModel *responseModel = (KFOWMDailyForecastResponseModel *)responseData;
        NSLog(@"received daily forecast: %@, %@", responseModel.city.cityName, [[responseModel.list valueForKeyPath:@"temperature.day"] componentsJoinedByString:@" K, "]);
    }
    else
    {
        NSLog(@"could not get daily forecast: %@", error);
    }
}];
```
that returns a `KFOWMDailyForecastResponseModel`:  
**KFOpenWeatherMapAPI[6605:c07] received daily forecast: Los Angeles, 299.71 K, 299.93 K, 300.69 K, 301.13 K**
##Search
To search for a phrase you can call
```obj-c
[self.apiClient searchForPhrase:@"London" numberOfResults:10 withResultBlock:^(BOOL success, id responseData, NSError *error)
{
    if (success)
    {
        KFOWMSearchResponseModel *responseModel = (KFOWMSearchResponseModel *)responseData;
        NSMutableArray *foundCities = [NSMutableArray new];
        for (KFOWMWeatherResponseModel *listModel in responseModel.list)
        {
            NSString *city = [NSString stringWithFormat:@"%@, %@", listModel.cityName, listModel.systemInfo.country];
            [foundCities addObject:city];
        }
        NSLog(@"search results: %@", [foundCities componentsJoinedByString:@", "]);
    }
    else
    {
        NSLog(@"could not get search results: %@", error);
    }
}];
```
that will result in a `KFOWMSearchResponseModel`:  
**KFOpenWeatherMapAPI[6976:c07] search results: London, GB, London, CA, London, US, London, US**

#License
This code is distributed under the terms and conditions of the MIT license.

#Author
Rico Becker -> @ricobeck