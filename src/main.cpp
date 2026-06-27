#include <Arduino.h>
#include <AirMonitorFactory.h>
#include <AirMonitorController.h>

AirMonitorFactory airMonitorFactory;
AirMonitorController& airMonitorController = airMonitorFactory.getAirMonitorController();

void setup()
{  
  airMonitorController.init();
}

void loop()
{
  delay(30000);
  airMonitorController.update();
}