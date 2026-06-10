#pragma once

class IConnectionManager
{
    public:
        virtual ~IConnectionManager() = default;
        virtual void init() = 0;
        virtual void connect() = 0;
        virtual void reconnect() = 0;
        virtual bool isConnected() = 0;

};