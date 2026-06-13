#pragma once
#include <Measurements.h>

/**
 * @file IMeasurementPublisher.h
 * @brief Schnittstelle zur Veröffentlichung von Messwerten.
 */

/**
 * @brief Abstrakte Schnittstelle für Komponenten, die Messwerte bereitstellen oder veröffentlichen.
 *
 * Diese Schnittstelle entkoppelt die fachliche Messwerterfassung von der
 * konkreten Ausgabetechnologie. Eine Implementierung kann die Messwerte z. B.
 * per MQTT, HTTP oder über eine andere Schnittstelle bereitstellen.
 */
class IMeasurementPublisher
{
    public:

        /**
         * @brief Virtueller Destruktor für polymorphe Verwendung.
         */
        virtual ~IMeasurementPublisher() = default;

        /**
         * @brief Veröffentlicht die übergebenen Messwerte.
         *
         * @param measurements Die zu veröffentlichenden Messwerte.
         */
        virtual void publish(const Measurements& measurements) = 0;
};