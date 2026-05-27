#pragma once

/**
 * @file IDisplayOutput.h
 * @class IDisplayOutput
 * @brief Interface zur Abstraktion der Display-Ausgabe
 * 
 * Dieses Interface definiert die grundlegenden Operationen zur Ansteuerung
 * eines Displays.
 * 
 * Konkrete Implementierungen kapseln den Zugriff auf die jeweilige Hardware
 * (z. B. OLED, LCD) und ermöglichen eine einheitliche Nutzung durch den
 * DisplayController.
 * 
 * Ziel ist die Entkopplung von Darstellungslogik und konkreter Hardware,
 * wodurch Tests und alternative Implementierungen vereinfacht werden.
 */
class IDisplayOutput
{
    public:

        /**
         * @brief Virtueller Destruktor
         */
        virtual ~IDisplayOutput() = default;

        virtual void init() = 0;

        /**
         * @brief Löscht den aktuellen Displayinhalt
         */
        virtual void clear() = 0;

        /**
         * @brief Schreibt Text in eine bestimmte Zeile des Displays
         * 
         * @param line Zielzeile auf dem Display
         * @param text Darzustellender Text
         */
        virtual void writeLine(int line, const char* text) = 0;

        /**
         * @brief Aktualisiert die Anzeige des Displays
         * 
         * Überträgt den aktuell vorbereiteten Inhalt auf das Display.
         */
        virtual void display() = 0;

        /**
         * @brief Versetzt das Display in den Energiesparmodus
         */
        virtual void sleepOn() = 0;

        /**
         * @brief Aktiviert das Display aus dem Energiesparmodus
         */
        virtual void sleepOff() = 0;
};