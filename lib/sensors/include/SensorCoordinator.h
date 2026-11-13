#pragma once
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include <BatterySensor.h>
#include "Measurements.h"

/**
 * @file SensorCoordinator.h
 * @brief Defines the component for collecting sensor measurements.
 */

/**
 * @brief Collects temperature, humidity, and battery level measurements.
 *
 * The SensorCoordinator provides a central access point for retrieving
 * measurement values from the application-level sensor components.
 *
 * It combines temperature, relative humidity, and battery level values
 * into a single Measurements structure.
 *
 * The coordinator does not interact directly with hardware.
 * Hardware access is handled by the underlying sensor drivers.
 */
class SensorCoordinator
{
    private:

        /**
         * @brief Reference to the temperature sensor component.
         */
        TemperatureSensor& tempSens;

        /**
         * @brief Reference to the humidity sensor component.
         */
        HumiditySensor& humSens;

        /**
         * @brief Reference to the battery sensor component.
         */
        BatterySensor& battSens;
        
    public:

        /**
         * @brief Constructs a sensor coordinator.
         *
         * @param tempSens Temperature sensor component.
         * @param humSens Humidity sensor component.
         * @param battSens Battery sensor component.
         */
        SensorCoordinator(TemperatureSensor& tempSens, HumiditySensor& humSens, BatterySensor& battSens) : tempSens(tempSens), humSens(humSens), battSens(battSens) {}
        
        /**
         * @brief Collects measurement values from all sensor components.
         *
         * Retrieves temperature, relative humidity, and battery level
         * values from their respective sensor components and combines
         * them into a single Measurements structure.
         *
         * @return Structure containing the collected measurement values.
         */       
        Measurements readAllSensors();
};