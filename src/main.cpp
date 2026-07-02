#include <Arduino.h>
#include <AirMonitorFactory.h>
#include <AirMonitorController.h>

AirMonitorFactory airMonitorFactory;
AirMonitorController& airMonitorController = airMonitorFactory.getAirMonitorController();

void setup()
{  
  airMonitorController.init();
  airMonitorController.update();
}

void loop()
{
  
}