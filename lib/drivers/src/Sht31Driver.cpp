#include <Sht31Driver.h>
#ifdef ARDUINO_ARCH_ESP32
    #include <Wire.h>
#else
    #include <i2c.h>
#endif
#include <Arduino.h>
#include <HardwareConfig.h>

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
    #ifdef ARDUINO_ARCH_ESP32
        Wire.begin(HardwareConfig::ESP32_I2C_SDA_PIN, HardwareConfig::ESP32_I2C_SCL_PIN);
    #else
        i2c_init();
    #endif
}

void Sht31Driver::readMeasurements()
{
    #ifdef ARDUINO_ARCH_ESP32
        Wire.beginTransmission(SHT31_SENSOR_ADDRESS);
        Wire.write(SINGLE_SHOT_MEASUREMENT_MSB);
        Wire.write(SINGLE_SHOT_MEASUREMENT_LSB);

        if (Wire.endTransmission() != 0)
        {
            temperature = SensorConstants::TEMPERATURE_MEASUREMENT_ERROR;
            humidity = SensorConstants::HUMIDITY_MEASUREMENT_ERROR;
            return;
        }

        delay(50);

        if (Wire.requestFrom(SHT31_SENSOR_ADDRESS, sizeof(data)) != sizeof(data))
        {
            temperature = SensorConstants::TEMPERATURE_MEASUREMENT_ERROR;
            humidity = SensorConstants::HUMIDITY_MEASUREMENT_ERROR;
            return;  
        }
        for (int i = 0; i < sizeof(data); i++)
        {
            data[i] = Wire.read();
        }
    #else
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
    #endif

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