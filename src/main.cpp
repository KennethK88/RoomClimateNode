#include <Arduino.h>
#include "RoomClimateFactory.h"
#include "RoomClimateController.h"

RoomClimateFactory roomClimateFactory;
RoomClimateController& roomClimateController = roomClimateFactory.getRoomClimateController();

void setup()
{  
  roomClimateController.init();
  roomClimateController.update();
}

void loop()
{
  
}