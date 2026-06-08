#include <Sht31Driver.h>
#include <i2c.h>
#include <Arduino.h>

namespace
{
    constexpr uint8_t SHT31_SENSOR_ADDRESS = 0x44;

    // Single shot measurement settings for clock stretching disabled and high repeatability
    constexpr uint8_t SINGLE_SHOT_MEASUREMENT_MSB = 0x24;
    constexpr uint8_t SINGLE_SHOT_MEASUREMENT_LSB = 0x00;
    constexpr uint8_t SINGLE_SHOT_MEASUREMENT[2] = {SINGLE_SHOT_MEASUREMENT_MSB, SINGLE_SHOT_MEASUREMENT_LSB};

    // Measurement results
    constexpr uint8_t TEMPERATURE_MSB = 0;
    constexpr uint8_t TEMPERATURE_LSB = 1;
    constexpr uint8_t HUMIDITY_MSB = 3;
    constexpr uint8_t HUMIDITY_LSB = 4;

    Temperature convertMeasurementToTemperature(const uint8_t* data)
    {
        return (-45.0f + 175.0f * (data[TEMPERATURE_MSB] << 8 | data[TEMPERATURE_LSB]) / UINT16_MAX); 
    }

    Humidity convertMeasurementToHumidity(const uint8_t* data)
    {
        return (100.0f * (data[HUMIDITY_MSB] << 8 | data[HUMIDITY_LSB]) / UINT16_MAX);
    }
}

void Sht31Driver::init()
{
    i2c_init();
}

void Sht31Driver::readMeasurements()
{
    if (!i2c_write_buffer(SHT31_SENSOR_ADDRESS, SINGLE_SHOT_MEASUREMENT, sizeof(SINGLE_SHOT_MEASUREMENT)))
    {
        temperature = SensorConstants::TEMPERATURE_MEASUREMENT_ERROR;
        humidity = SensorConstants::HUMIDITY_MEASUREMENT_ERROR;
        return;
    }

    delay(50); // TODO: Von Arduino entkoppeln

    if(!i2c_read_buffer(SHT31_SENSOR_ADDRESS, data, sizeof(data)))
    {
        temperature = SensorConstants::TEMPERATURE_MEASUREMENT_ERROR;
        humidity = SensorConstants::HUMIDITY_MEASUREMENT_ERROR;
        return;
    }

    temperature = convertMeasurementToTemperature(data);
    humidity = convertMeasurementToHumidity(data);
}

Temperature Sht31Driver::getTemperature()
{
    return temperature;
}

Humidity Sht31Driver::getHumidity()
{
    return humidity;
}