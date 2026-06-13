#pragma once
#include <Sht31Driver.h>
#include <WiFiConnectionManager.h>
#include <MqttClientService.h>
#include <MqttMeasurementPublisher.h>
#include <AirMonitorController.h>

/**
 * @file AirMonitorFactory.h
 * @brief Factory zur Erstellung und Verdrahtung des Raumklima-Knotens.
 */

/**
 * @class AirMonitorFactory
 * @brief Erzeugt die konkreten Komponenten und verdrahtet den zentralen Controller.
 *
 * Die AirMonitorFactory kapselt den Aufbau des Systems. Sie erzeugt die
 * konkreten Sensor-, WLAN- und MQTT-Komponenten und verdrahtet diese mit dem
 * AirMonitorController.
 *
 * Dadurch bleibt der AirMonitorController von konkreten Hardware- und
 * Kommunikationsimplementierungen entkoppelt und kann in Tests über
 * Fake-Komponenten betrieben werden.
 *
 * Verantwortlichkeiten:
 * - Erzeugung konkreter Sensor- und Verbindungskomponenten
 * - Erzeugung des MQTT-basierten Messwertpublishers
 * - Verdrahtung der Komponenten mit dem AirMonitorController
 * - Bereitstellung eines vollständig aufgebauten Controller-Objekts
 *
 * @note Der Klassenname AirMonitorController ist historisch gewachsen. Fachlich
 * wird hier aktuell der zentrale Controller eines Raumklima-Knotens aufgebaut.
 */
class AirMonitorFactory
{
    private:
        Sht31Driver sht31Driver;
        WiFiConnectionManager wifiConnectionManager;
        MqttClientService mqttClientService;
        MqttMeasurementPublisher mqttMeasurementPublisher{mqttClientService};
        AirMonitorController airMonitorController{sht31Driver, wifiConnectionManager, mqttClientService, mqttMeasurementPublisher};

    public:
    
        /**
         * @brief Liefert den vollständig verdrahteten AirMonitorController.
         *
         * @return Referenz auf den aufgebauten AirMonitorController.
         */
        AirMonitorController& getAirMonitorController();
};