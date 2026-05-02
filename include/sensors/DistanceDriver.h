#pragma once
#include <ISensorDriver.h>

/**
 * @file DistanceDriver.h
 * @class DistanceDriver
 * @brief Treiber zur Distanzmessung über einen Ultraschallsensor
 * 
 * Der DistanceDriver implementiert das ISensorDriver-Interface und ermöglicht
 * die Messung von Entfernungen mittels eines Ultraschallsensors.
 * 
 * Das Messprinzip basiert auf der Laufzeitmessung eines Schallsignals:
 * - Senden eines Trigger-Impulses
 * - Messen der Zeit bis zum Eintreffen des Echos
 * - Umrechnung der Zeit in eine Distanz
 * 
 * Die Klasse kapselt den direkten Hardwarezugriff sowie die Umrechnung
 * in einen Distanzwert in Zentimetern.
 */
class DistanceDriver : public ISensorDriver
{
    private:
        /**
         * @brief Liest die Rohmessung des Sensors
         * 
         * Führt eine Ultraschallmessung durch und gibt die gemessene
         * Laufzeit des Echos in Mikrosekunden zurück.
         * 
         * @return Laufzeit in Mikrosekunden
         * 
         * @note Ein Rückgabewert von 0 bedeutet, dass kein Echo empfangen wurde
         */
        unsigned long readRawValue();

        /**
         * @brief Wandelt die gemessene Laufzeit in eine Distanz um
         * 
         * @param rawValue Laufzeit des Echos in Mikrosekunden
         * @return Distanz in Zentimetern
         */
        float convertRawValueToDistance(unsigned long rawValue); 
    
    public:

        /**
         * @brief Konstruktor
         */
        DistanceDriver() = default;

        /**
         * @brief Initialisiert den Ultraschallsensor
         * 
         * Konfiguriert die benötigten Ein- und Ausgangspins.
         */
        void init() override;

        /**
         * @brief Liefert die aktuell gemessene Distanz
         * 
         * Führt eine Messung durch und gibt die berechnete Distanz zurück.
         * 
         * @return Distanz in Zentimetern
         * 
         * @note Ein Rückgabewert von 0 bedeutet, dass kein Objekt erkannt wurde
         */
        float getValue() override;
};