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
  delay(5000);
  airMonitorController.update();
  //Serial.println("Läuft");
}

// TODO: main verschieben wg. Tests
// FEATURE: Abstandssensor integrieren -> Screen off
// FEATURE: Weitere Status LEDs integrieren
// FEATURE: Über Photoresistor OLED Helligkeit regulieren
// FIXME: Datentypen auf <cstdint> umbauen
#endif