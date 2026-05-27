#include <Arduino.h>
#include <Wire.h>
#include <AirMonitorFactory.h>

AirMonitorFactory airMonitorFactory;
AirMonitorController& airMonitorController = airMonitorFactory.getAirMonitorController();

void setup()
{  
  Wire.begin();
  airMonitorController.init();
}

void loop()
{
  delay(5000);
  airMonitorController.update();
}