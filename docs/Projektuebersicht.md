# Projektsteckbrief: AirMonitorController

## Ziel 

Ziel des Projekts ist die Entwicklung eines kompakten Raumklima-Knotens auf Mikrocontrollerbasis. Der Knoten erfasst Temperatur- und Luftfeuchtigkeitswerte, verarbeitet und validiert die Messdaten lokal und überträgt sie drahtlos an ein Smart-Home-System. Für das Wohnzimmer ist aufgrund des vorhandenen Kamins optional ein separater CO-Sensorknoten vorgesehen.


## Aktueller Stand

Aktuell erfolgt die Messung von Temperatur und Luftfeuchtigkeit über einen SHT31-Sensor. Die Messwerte werden über WLAN per MQTT an einen Mosquitto-Broker auf einem Raspberry Pi übertragen.


## Geplante Funktionsumfänge

[ ] Messwerte erfassen
    - [x] Raumtemperatur in °C
    - [x] Raumfeuchte in %
    - [ ] Ladezustand in %
[ ] Messwerte validieren
    - [x] Raumtemperatur in °C
    - [x] Raumfeuchte in %
    - [ ] Ladezustand in %
[ ] Messwerte per WLAN/MQTT bereitstellen
    - [x] Raumtemperatur in °C
    - [x] Raumfeuchte in %
    - [ ] Ladezustand in % 
[ ] Mikrocontroller zwischen den Messzyklen in den Deep-Sleep-Modus versetzen
[ ] Firmware-Updates per Over-the-Air-Update (OTA) ermöglichen
[ ] Akkubetrieb ermöglichen
[ ] Optional: Systemzustände über Status-LED anzeigen
    - [ ] Niedrigen Ladezustand anzeigen
    - [ ] Unplausible Messwerte anzeigen
    - [ ] Fehlgeschlagene WLAN-/MQTT-Verbindung anzeigen
    - [ ] Vollständig geladenen Akku bei angeschlossenem Ladegerät anzeigen
[ ] Optional: CO-Werte über einen separaten Sensorknoten erfassen


## Benötigte Hardware

[ ] Mikrocontroller (ESP32)
[ ] Akku
[ ] Laderegler / Lademodul
[x] Temperatur- und Feuchtesensor (SHT31)
[x] RGB LED
[ ] Gehäuse
[ ] Optional: CO-Sensor für separaten Sensorknoten


## Teststrategie

- Native Tests
    - Test der fachlichen Logik unabhängig von der Zielhardware
    - Test von Sensorverarbeitung, Messwertvalidierung und Zustandslogik mit Fake-Komponenten

- Embedded Tests
    - Test hardwarenaher Funktionen direkt auf dem Mikrocontroller
    - Test der Sensoranbindung, WLAN-Verbindung und MQTT-Kommunikation