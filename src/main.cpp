#ifndef PIO_UNIT_TESTING
#include <Arduino.h>
#include <Wire.h>
#include "controller/AirMonitorController.h"

AirMonitorController airMonitorController;

void setup()
{  
  Wire.begin();
  //Serial.begin(115200);
  airMonitorController.init();
}

void loop()
{
  airMonitorController.update();
  delay(5000);
  //Serial.println("Läuft");
}

// TODO: main verschieben wg. Tests
#endif