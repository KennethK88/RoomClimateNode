#include <AirMonitorFactory.h>

AirMonitorController& AirMonitorFactory::getAirMonitorController()
{
    return airMonitorController;
}