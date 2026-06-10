#pragma once
#include <Measurements.h>

class IMeasurementPublisher
{
    public:
        virtual ~IMeasurementPublisher() = default;
        virtual void publish(const Measurements& measurements) = 0;
};