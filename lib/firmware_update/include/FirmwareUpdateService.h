#pragma once

class FirmwareUpdateService
{
    private:

    public:
        bool init();
        void handle();
        bool runMaintenanceWindow();
};