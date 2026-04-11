#pragma once

class ISensor
{
    public:
        virtual ~ISensor() = default;
        virtual void readValue() = 0;
        virtual float getValue() const = 0;
};