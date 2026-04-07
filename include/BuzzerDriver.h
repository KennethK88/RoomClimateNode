#pragma once

class BuzzerDriver
{
    public:
        BuzzerDriver() = default;
        void initBuzzer();
        void activateBuzzer();
        void deactivateBuzzer();
};