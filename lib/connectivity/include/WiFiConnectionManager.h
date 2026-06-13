#pragma once
#include <IConnectionManager.h>

class WiFiConnectionManager : public IConnectionManager
{
    public:
        WiFiConnectionManager() = default;
        void init() override;
        void connect() override;
        void reconnect() override;
        bool isConnected() override;
};