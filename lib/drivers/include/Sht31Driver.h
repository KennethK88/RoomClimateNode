#pragma once

#include "ISht31SensorDriver.h"
#include "Types.h"
#include "CommonSensorConstants.h"

#include <cstdint>

/**
 * @file Sht31Driver.h
 * @brief Defines the hardware-specific driver for the SHT31 temperature and humidity sensor.
 */

/**
 * @brief Implements temperature and humidity measurement using the SHT31 sensor.
 *
 * Provides the concrete implementation of the ISht31SensorDriver interface
 * and encapsulates hardware communication with the SHT31 sensor.
 *
 * Measurements are acquired through readMeasurements() and stored internally
 * for subsequent access through getTemperature() and getHumidity().
 */
class Sht31Driver : public ISht31SensorDriver
{
    private:
        uint8_t data[6] = {0};
        Temperature temperature = SensorConstants::TEMPERATURE_NOT_INITIALIZED;
        Humidity humidity = SensorConstants::HUMIDITY_NOT_INITIALIZED;
        
    public:

        /**
         * @brief Constructs an SHT31 sensor driver.
         */
        Sht31Driver() = default;

        /**
         * @brief Initializes communication with the SHT31 sensor.
         */
        void init() override;

        /**
         * @brief Acquires temperature and humidity measurements from the SHT31 sensor.
         *
         * Triggers a single-shot measurement, reads the raw sensor data,
         * converts it into temperature and relative humidity values,
         * and stores the results internally.
         *
         * If I2C communication fails or the expected amount of data
         * cannot be received, both measurements are set to their
         * corresponding measurement error values.
         */
        void readMeasurements() override;

        /**
         * @brief Returns the most recently stored temperature measurement.
         *
         * @return Temperature in degrees Celsius.
         */
        Temperature getTemperature() override;

        /**
         * @brief Returns the most recently stored relative humidity measurement.
         *
         * @return Relative humidity in percent.
         */
        Humidity getHumidity() override;
};