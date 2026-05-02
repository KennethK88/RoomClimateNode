#pragma once
#include <IDisplayOutput.h>
#include <U8g2lib.h>

/**
 * @file OledDriver.h
 * @class OledDriver
 * @brief Treiber zur Ansteuerung eines OLED-Displays über die U8g2-Library
 * 
 * Der OledDriver implementiert das IDisplayOutput-Interface und ermöglicht
 * die Darstellung von Text auf einem OLED-Display.
 * 
 * Die Klasse kapselt den Zugriff auf die U8g2-Bibliothek sowie die konkrete
 * Display-Hardware und stellt eine einfache Schnittstelle für das Schreiben
 * von Textzeilen und die Aktualisierung der Anzeige bereit.
 */
class OledDriver : public IDisplayOutput
{
    private:

        /**
         * @brief Instanz des OLED-Displays (U8g2)
         * 
         * Konfiguriert für ein SSD1306-Display mit 128x64 Pixeln über I2C.
         */
        U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled{U8G2_R0, U8X8_PIN_NONE};

    public:

        /**
         * @brief Konstruktor
         */
        OledDriver() = default;

        /**
         * @brief Initialisiert das Display
         * 
         * Initialisiert die U8g2-Library und bereitet das Display für die
         * Ausgabe vor.
         */
        void init();

        /**
         * @brief Löscht den aktuellen Bildinhalt
         * 
         * Setzt den internen Bildpuffer zurück.
         */
        void clear() override;

        /**
         * @brief Schreibt eine Textzeile in den internen Puffer
         * 
         * @param line Zielzeile auf dem Display
         * @param text Darzustellender Text
         * 
         * @note Die tatsächliche Anzeige erfolgt erst nach Aufruf von display()
         */
        void writeLine(int line, const char* text) override;

        /**
         * @brief Überträgt den Bildpuffer auf das Display
         * 
         * Aktualisiert die Anzeige mit den aktuell gesetzten Inhalten.
         */
        void display() override;

        /**
         * @brief Versetzt das Display in den Energiesparmodus
         */
        void sleepOn() override;

        /**
         * @brief Aktiviert das Display aus dem Energiesparmodus
         */
        void sleepOff() override;
};