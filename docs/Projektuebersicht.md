# Projektsteckbrief: RoomClimateNode / AirMonitorController

## Ziel

Der AirMonitorController wird zu seinem Sensorknoten umgestaltet. Mehrere kleine Sensorknoten messen in verschiedenen Räumen Temperatur und Luftfeuchte. Die Werte werden drahtlos an Home Assistant übertragen und dort angezeigt. Für das Wohnzimmer gibt es optional einen separaten CO-Sensorknoten wegen des Kamins.


## Geplante Funktionsumfänge / Anforderungen

[x] Raumtemperatur in °C ermitteln
[x] Raumfeuchte in % ermitteln
[ ] Ladezustand in % ermitteln
[ ] Raumtemperatur- und feuchte sowie Ladezustand validieren
[ ] Raumtemperatur und -feuchte sowie Ladezustand über WLAN-/MQTT an Home Assistant OS übermitteln
[ ] Deep Sleep Modus
[ ] Akkubetrieb
[ ] Rote LED soll bei niedrigem Ladezustand leuchten
[ ] Rote LED soll bei unplausibler Raumtemperatur- und feuchte leuchten
[ ] Rote LED soll bei fehlgeschlagener WLAN-/MQTT Verbind leuchten
[ ] Grüne LED soll leuchten, wenn Akku vollständig geladen und Sensorknoten noch am Ladegerät ist
[ ] OTA Updates


## Benötigte Hardware

[ ] ESP32
[ ] Akku
[ ] Laderegler
[x] Temperatur- und Feuchtesensor (SHT31)
[ ] RGB LED
[ ] Gehäuse


## Teststrategie

- Native Tests
- Embedded Tests