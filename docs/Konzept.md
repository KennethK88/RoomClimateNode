# Luftüberwachung – Konzept

## 1\. Messgrößen

* Temperatur (°C) – Komfort
* Luftfeuchte (%) – Komfort / Schimmelrisiko
* CO (ppm) – Sicherheit

## 2\. Systemverhalten

* System stellt aktuelle Messwerte bereit
* System bewertet Messwerte gegen Grenzwerte
* System signalisiert kritische Zustände

## 3\. Zustände

* Normal:
  Alle Messgrößen liegen innerhalb der definierten Grenzwerte.
  Das System zeigt die aktuellen Messwerte an.
* Warnung:
  Mindestens eine Messgröße liegt außerhalb ihres Grenzwertes.
  Das System signalisiert einen kritischen Zustand (optisch / akustisch).
* Fehler:
  Eine Messgröße ist nicht verfügbar oder liefert ungültige Werte.
  Das System signalisiert einen Sensor- oder Systemfehler.

## 4\. Verantwortlichkeiten

* Messwerte erfassen
* Bewertung gegen Grenzwerte
* Validierung/Fehlererkennung der Messwerte
* Zustände koordinieren
* Messwerte anzeigen
* Akustische Warnung ausgeben
