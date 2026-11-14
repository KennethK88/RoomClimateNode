#include "RoomClimateFactory.h"
#include "RoomClimateController.h"

#include <Arduino.h>

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