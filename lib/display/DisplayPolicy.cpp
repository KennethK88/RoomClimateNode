#include <DisplayPolicy.h>

bool DisplayPolicy::evaluateDisplayState(const Measurements& measurements, const ValidationResults& validationResults)
{
    if (!validationResults.distanceValid) return true; // Wenn Distanzsensor invalide, soll das Display immer an bleiben
    if (measurements.distance == SensorConstants::DISTANCE_NO_OBJECT_DETECTED) return false;
    return (measurements.distance <= SensorConstants::DISTANCE_ON_OFF_THRESHOLD);
}

bool DisplayPolicy::isDisplayActive(const Measurements& measurements, const ValidationResults& validationResults)
{
    return evaluateDisplayState(measurements, validationResults);
}