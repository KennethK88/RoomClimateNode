// #include "sensors/SimulatedTemperatureSensor.h"

// void SimulatedTemperatureSensor::readTemperature()
// {
//     if(currentTemperature >= 45.0f)
//     {
//         currentTemperature = 45.0f;
//         direction = -1;
//     }
//     else if(currentTemperature <= -25.0f)
//     {
//         currentTemperature = -25.0f;
//         direction = 1;
//     }
//     currentTemperature += direction * stepsize;
// }

// float SimulatedTemperatureSensor::getTemperature() const
// {
//     return currentTemperature;
// }