#pragma once

/**
 * @file IConnectionManager.h
 * @brief Schnittstelle für verbindungsorientierte Komponenten.
 */

/**
 * @brief Abstrakte Schnittstelle zum Initialisieren und Verwalten einer Verbindung.
 *
 * Diese Schnittstelle kapselt den Lebenszyklus einer Verbindung unabhängig von
 * der konkreten Technologie. Sie kann z. B. für WLAN- oder MQTT-Verbindungen
 * verwendet werden.
 */
class IConnectionManager
{
    public:

        /**
         * @brief Virtueller Destruktor für polymorphe Verwendung.
         */
        virtual ~IConnectionManager() = default;

        /**
         * @brief Initialisiert die Verbindungskomponente.
         */
        virtual void init() = 0;

        /**
         * @brief Baut die Verbindung auf.
         */
        virtual void connect() = 0;

        /**
         * @brief Stellt die Verbindung bei Bedarf erneut her.
         */
        virtual void reconnect() = 0;

        /**
         * @brief Prüft, ob die Verbindung aktuell besteht.
         *
         * @return true, wenn die Verbindung besteht, sonst false.
         */
        virtual bool isConnected() = 0;
};