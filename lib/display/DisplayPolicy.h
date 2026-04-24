#pragma once
#include <Measurements.h>
#include <ValidationResults.h>
#include <CommonSensorConstants.h>

class DisplayPolicy
{
    private: 
        bool evaluateDisplayState(const Measurements& measurements, const ValidationResults& validationResults);

    public:
        DisplayPolicy() = default;
        bool isDisplayActive(const Measurements& measurements, const ValidationResults& validationResults);
};