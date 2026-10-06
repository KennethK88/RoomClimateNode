#pragma once

/**
 * @file IConnectionManager.h
 * @brief Interface for connection-oriented components.
 */

/**
 * @brief Abstract interface for initializing and managing a connection.
 *
 * This interface encapsulates the lifecycle of a connection independently of
 * the concrete communication technology. It can be used for components such as
 * Wi-Fi or MQTT connection managers.
 */
class IConnectionManager
{
    public:

        /**
         * @brief Virtual destructor for polymorphic use.
         */
        virtual ~IConnectionManager() = default;

        /**
         * @brief Initializes the connection component.
         */
        virtual void init() = 0;

        /**
         * @brief Attempts to establish the connection.
         *
         * Implementations may use internal timeout handling and may return
         * without an established connection. The current connection state can be
         * checked using isConnected().
         */
        virtual void connect() = 0;

        /**
         * @brief Checks whether the connection is currently established.
         *
         * @return true if the connection is established, false otherwise.
         */
        virtual bool isConnected() = 0;
        virtual void disconnect() = 0;
};