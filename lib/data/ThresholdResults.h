#pragma once

struct ThresholdResults
{
        bool temperatureTooHigh = false;
        bool humidityTooHigh = false;
        bool coTooHigh = false;

        bool temperatureTooLow = false;
        bool humidityTooLow = false;
};