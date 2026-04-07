#include <Arduino.h>
#include "AirMonitorController.h"

AirMonitorController airMonitorController;

void setup()
{
  //airMonitorController.init();
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  //airMonitorController.update();
  delay(10000);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);

}