#pragma once
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <BatterySensor.h>
#include <Measurements.h>

/**
 * @file SensorCoordinator.h
 * @brief Bündelt die Messwerte der fachlichen Sensorkomponenten.
 */

/**
 * @class SensorCoordinator
 * @brief Fasst Temperatur- und Luftfeuchtigkeitswerte in einer gemeinsamen Datenstruktur zusammen.
 *
 * Der SensorCoordinator koordiniert den Zugriff auf die fachlichen
 * Sensorkomponenten und stellt deren aktuelle Werte als konsolidierten
 * Messwertsatz bereit.
 *
 * Die Klasse greift nicht direkt auf die Hardware zu. Der konkrete
 * Hardwarezugriff erfolgt über die jeweiligen Sensortreiber.
 */
class SensorCoordinator
{
    private:

        /**
         * @brief Referenz auf die fachliche Temperatursensorkomponente.
         */
        TemperatureSensor& tempSens;

        /**
         * @brief Referenz auf die fachliche Luftfeuchtigkeitssensorkomponente.
         */
        HumiditySensor& humSens;

        BatterySensor& battSens;
        
    public:

        /**
         * @brief Erstellt einen SensorCoordinator.
         *
         * @param tempSens Referenz auf die Temperatursensorkomponente.
         * @param humSens Referenz auf die Luftfeuchtigkeitssensorkomponente.
         */
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens, BatterySensor& battSens) : tempSens(tempSens), humSens(humSens), battSens(battSens) {}
        
        /**
         * @brief Liest die aktuellen Werte der Sensorkomponenten und fasst sie zusammen.
         *
         * Fragt Temperatur und Luftfeuchtigkeit über die jeweiligen
         * Sensorkomponenten ab und gibt die Werte als gemeinsames
         * Measurements-Objekt zurück.
         *
         * @return Struktur mit den aktuellen Messwerten.
         */        
        Measurements readAllSensors();
};