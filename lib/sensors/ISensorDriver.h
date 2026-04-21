#pragma once

class ISensorDriver
{
    public:
        virtual ~ISensorDriver() = default;
        virtual void init() = 0;
        virtual float getValue() = 0;
};