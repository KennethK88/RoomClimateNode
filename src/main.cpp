#include <Arduino.h>
#include "AirMonitorController.h"

AirMonitorController airMonitorController;

void setup()
{

}

void loop()
{
  airMonitorController.update();
  delay(1000);
}