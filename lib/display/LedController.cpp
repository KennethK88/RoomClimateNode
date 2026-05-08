#include <LedController.h>

void LedController::updateLeds(SystemState systemState)
{
    switch(systemState)
    {
        case SystemState::Normal:
            normalLed.turnOn();
            warningLed.turnOff();
            errorLed.turnOff();
            break;
        case SystemState::Warning:
            normalLed.turnOff();
            warningLed.turnOn();
            errorLed.turnOff();
            break;
        case SystemState::Error:
            normalLed.turnOff();
            warningLed.turnOff();
            errorLed.turnOn();
            break;        
        default:
            // NOTE: Sollte nie erreicht werden, da alle SystemState-Werte behandelt werden.
            normalLed.turnOff();
            warningLed.turnOff();
            errorLed.turnOff();  
    }
}