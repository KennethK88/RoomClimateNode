#pragma once
#include <TemperatureSensor.h>
#include <HumiditySensor.h>
#include <Measurements.h>

/**
 * @file SensorCoordinator.h
 * @class SensorCoordinator
 * @brief Koordiniert das Auslesen aller Sensoren
 * 
 * Der SensorCoordinator ist dafür verantwortlich, alle angebundenen Sensoren
 * zyklisch auszulesen und die aktuellen Messwerte in einer gemeinsamen
 * Datenstruktur bereitzustellen.
 * 
 * Die Klasse aggregiert die einzelnen Sensoren und kapselt deren Zugriff,
 * sodass aufrufende Komponenten nur noch mit einem konsolidierten
 * Messwertsatz arbeiten müssen.
 */
class SensorCoordinator
{
    private:

        /**
         * @brief Referenz auf den Temperatursensor
         */
        TemperatureSensor& tempSens;

        /**
         * @brief Referenz auf den Feuchtigkeitssensor
         */
        HumiditySensor& humSens;
        
    public:

        /**
         * @brief Konstruktor
         * 
         * @param tempSens Referenz auf den Temperatursensor
         * @param humSens Referenz auf den Feuchtigkeitssensor
         */
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens) : tempSens(tempSens), humSens(humSens) {}
        
        /**
         * @brief Liest alle Sensoren aus und gibt die aktuellen Messwerte zurück
         * 
         * Ruft die jeweiligen Sensoren auf, aktualisiert deren interne Werte
         * und fasst die Ergebnisse in einer gemeinsamen Struktur zusammen.
         * 
         * @return Struktur mit allen aktuellen Sensormesswerten
         */        
        Measurements readAllSensors();
};