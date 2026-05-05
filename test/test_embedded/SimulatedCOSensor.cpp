// #include <SimulatedCOSensor.h>

// void SimulatedCOSensor::readCO()
// {
//     if(currentCO >= 1200.0f)
//     {
//         currentCO = 1200.0f;
//         direction = -1;
//     }
//     else if(currentCO <= -100.0f)
//     {
//         currentCO = -100.0f;
//         direction = 1;
//     }
//     currentCO += direction * stepsize;
// }

// float SimulatedCOSensor::getCO() const
// {
//     return currentCO;
// }