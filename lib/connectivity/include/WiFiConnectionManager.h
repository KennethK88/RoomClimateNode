#pragma once
#include <IConnectionManager.h>

/**
 * @file WiFiConnectionManager.h
 * @brief Konkrete WLAN-Verbindungskomponente für den Raumklima-Knoten.
 */

/**
 * @brief Verwaltet die WLAN-Verbindung des Mikrocontrollers.
 *
 * Diese Klasse kapselt den Aufbau und die Überwachung der WLAN-Verbindung.
 * Sie implementiert die allgemeine IConnectionManager-Schnittstelle und kann
 * dadurch vom Controller unabhängig von der konkreten WLAN-Implementierung
 * verwendet werden.
 */
class WiFiConnectionManager : public IConnectionManager
{
    public:

        /**
         * @brief Erzeugt einen WLAN-Verbindungsmanager.
         */
        WiFiConnectionManager() = default;

        /**
         * @brief Initialisiert die WLAN-Komponente.
         */
        void init() override;

        /**
         * @brief Baut die WLAN-Verbindung auf.
         */
        void connect() override;

        /**
         * @brief Stellt die WLAN-Verbindung bei Bedarf erneut her.
         */
        void reconnect() override;

        /**
         * @brief Prüft, ob aktuell eine WLAN-Verbindung besteht.
         *
         * @return true, wenn der Mikrocontroller mit dem WLAN verbunden ist, sonst false.
         */
        bool isConnected() override;
};