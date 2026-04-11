#pragma once

struct ThresholdResult
{
        bool temperatureTooHigh = false;
        bool humidityTooHigh = false;
        bool coTooHigh = false;

        bool temperatureTooLow = false;
        bool humidityTooLow = false;
};

//FIXME: ThresholdResults?