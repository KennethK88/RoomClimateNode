# Home Assistant Integration

This directory provides an example configuration for integrating a RoomClimateNode into Home Assistant using MQTT.

The example uses Home Assistant Packages and manual MQTT entity configuration. MQTT Discovery is not required.

## Prerequisites

- A running Home Assistant instance
- An MQTT broker configured in Home Assistant
- A RoomClimateNode configured to communicate with the MQTT broker

## Configuration Files

| File | Description |
|------|-------------|
| `roomclimatenode_dummy_room_01.yaml` | Example MQTT entity configuration |
| `expire_after.yml` | Shared sensor expiration timeout |

The example includes the following entities:

- Temperature sensor
- Humidity sensor
- Battery level sensor
- Firmware version sensor
- OTA update window status
- OTA update request switch

## Installation

### 1. Enable Home Assistant Packages

Add the following configuration to `configuration.yaml` if Packages are not already enabled:

```yaml
homeassistant:
  packages: !include_dir_named packages
```

### 2. Copy the Example Files

Copy both YAML files into your Home Assistant configuration directory:

```text
config/
├── configuration.yaml
└── packages/
    └── roomclimatenodes/
        ├── roomclimatenode_dummy_room_01.yaml
        └── expire_after.yml
```

The `expire_after.yml` file must remain in the same directory as the example configuration.

### 3. Adjust Node Settings

Update the following values to match your RoomClimateNode:

- MQTT topics
- Device identifiers
- Unique entity IDs
- Device name
- Manufacturer

The MQTT topics must match the configuration defined in `node_settings.ini`.

The repository provides `node_settings_example.ini` as a reference.

### 4. Configure Sensor Expiration

The `expire_after.yml` file defines the expiration timeout in seconds:

```yaml
1500
```

This value is shared by the temperature, humidity, and battery sensors.

Adjust the timeout according to the node's measurement interval and deep sleep configuration.

### 5. Apply the Configuration

Validate the Home Assistant configuration and restart Home Assistant to load the new entities.

## Additional Information

- [Home Assistant MQTT Integration](https://www.home-assistant.io/integrations/mqtt/)
- [Home Assistant Configuration Packages](https://www.home-assistant.io/docs/configuration/packages/)
- [Splitting the Home Assistant Configuration](https://www.home-assistant.io/docs/configuration/splitting_configuration/)