#pragma once
#include <IConnectionManager.h>

/**
 * @file WiFiConnectionManager.h
 * @brief Wi-Fi connection component for the ESP32-based room climate node.
 */

/**
 * @brief Manages the Wi-Fi connection of the microcontroller.
 *
 * This class encapsulates Wi-Fi initialization, connection setup and connection
 * state monitoring. It implements the generic IConnectionManager interface and
 * can therefore be used by the controller independently of the concrete Wi-Fi
 * implementation.
 */
class WiFiConnectionManager : public IConnectionManager
{
    public:

        /**
         * @brief Creates a Wi-Fi connection manager.
         */
        WiFiConnectionManager() = default;

        /**
         * @brief Initializes the Wi-Fi component.
         *
         * Configures the ESP32 Wi-Fi stack for station mode.
         */
        void init() override;

        /**
         * @brief Attempts to establish the Wi-Fi connection.
         *
         * The method starts the Wi-Fi connection setup and waits until the
         * connection is established or the internal connection timeout is
         * reached. The result can be checked using isConnected().
         */
        void connect() override;

        /**
         * @brief Checks whether the Wi-Fi connection is currently established.
         *
         * @return true if the microcontroller is connected to Wi-Fi,
         *         false otherwise.
         */
        bool isConnected() override;
        void disconnect() override;
};