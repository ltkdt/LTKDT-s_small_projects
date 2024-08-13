#include "pitches.h"
#include <avr/pgmspace.h>

#define BUZZER 8


const int Sheet[] PROGMEM = {
    NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_FS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_GS4, 0, NOTE_FS4, 0, NOTE_GS4, 0, NOTE_FS4, 0, NOTE_DS4, 0, NOTE_FS4, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS5, 0, 0, NOTE_CS5, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_D4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS5, 0, 0, NOTE_CS5, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, 0, 0, 0, NOTE_FS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_DS5, 0, 0, NOTE_CS5, 0, 0, NOTE_FS4, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_D4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_DS5, 0, 0, NOTE_CS5, 0, 0, NOTE_FS4, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, 0, 0, 0, NOTE_FS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, NOTE_F4, 0, 0, NOTE_FS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_DS5, 0, 0, NOTE_CS5, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_FS4, 0, 0, NOTE_F4, 0, 0, NOTE_CS4, 0, 0, NOTE_DS4, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_DS6, 0, 0, NOTE_F6, 0, 0, NOTE_FS6, 0, 0, NOTE_F6, 0, 0, NOTE_DS6, 0, 0, NOTE_CS6, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_FS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_FS4, NOTE_GS4, 0, 0, NOTE_FS4, 0, NOTE_GS4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_DS4, 0, 0, NOTE_DS4, 0, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, 0, NOTE_D4, NOTE_GS4, 0, NOTE_AS4, 0, NOTE_CS5, 0, NOTE_DS5, 0, NOTE_FS5, 0, NOTE_AS5, 0, NOTE_GS5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NOTE_AS5, 0, NOTE_GS5, NOTE_FS5, 0, 0, NOTE_GS5, 0, NOTE_FS5, NOTE_F5, 0, 0, NOTE_FS5, 0, NOTE_F5, NOTE_DS5, 0, 0, NOTE_F5, 0, NOTE_DS5, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS4, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_AS4, 0, 0, NOTE_GS4, 0, 0, NOTE_A4, 0, 0, NOTE_GS4, 0, 0, 0, 0, 0, NOTE_FS4, 0, 0, 0, 0, 0, NOTE_GS4, 0, 0, NOTE_AS4, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_FS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_DS6, 0, 0, 0, 0, 0, NOTE_DS6, 0, 0, 0, 0, 0, NOTE_FS6, 0, 0, 0, 0, 0, 0, 0, 0, NOTE_F6, 0, 0, NOTE_F6, 0, 0, NOTE_F6, 0, 0, NOTE_FS6, 0, 0, NOTE_F6, 0, 0, NOTE_DS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, NOTE_AS5, NOTE_AS5, 0, 0, 0, 0, NOTE_CS6, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, 0, 0, 0, NOTE_AS5, NOTE_GS5, NOTE_GS5, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F4, NOTE_DS4, NOTE_CS4, NOTE_DS4, 0, 0, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_F5, 0, 0, NOTE_B5, NOTE_AS5, NOTE_GS5, NOTE_AS5, 0, 0, NOTE_DS6, NOTE_CS6, NOTE_B5, NOTE_CS6, 0, 0, NOTE_B5, NOTE_AS5, NOTE_GS5, NOTE_AS5, 0, 0, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_F5, 0, 0, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_F4, 0, 0, NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_CS4, 0, 0, NOTE_AS4, 0, NOTE_AS4, NOTE_CS5, 0, NOTE_CS5, NOTE_B4, 0, NOTE_B4, NOTE_AS4, 0, NOTE_AS4, NOTE_B4, 0, NOTE_B4, NOTE_CS5, 0, NOTE_CS5, NOTE_DS5, 0, NOTE_DS5, NOTE_F5, 0, 0, NOTE_GS5, 0, 0, 0, 0, 0, NOTE_FS5, 0, 0, 0, 0, 0, 0, 0, 0, NOTE_F5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, 0, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, NOTE_GS5, 0, NOTE_FS5, 0, NOTE_F5, 0, NOTE_GS5, 0, NOTE_FS5, 0, NOTE_F5, 0, NOTE_GS5, 0, NOTE_FS5, 0, NOTE_F5, 0, NOTE_GS5, 0, NOTE_FS5, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_AS5, NOTE_CS6, 0, 0, 0, 0, NOTE_DS6, 0, 0, 0, 0, 0, NOTE_F6, 0, 0, 0, 0, 0, NOTE_FS6, 0, 0, NOTE_F6, 0, 0, NOTE_F6, 0, 0, 0, 0, 0, NOTE_DS6, 0, 0, 0, 0, 0, NOTE_CS6, 0, 0, 0, 0, 0, NOTE_CS6, 0, NOTE_D6, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, NOTE_F5, 0, 0, NOTE_FS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_CS6, 0, 0, NOTE_DS6, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_DS6, 0, 0, NOTE_F6, 0, 0, NOTE_FS6, 0, 0, NOTE_F6, 0, 0, NOTE_DS6, 0, 0, NOTE_CS6, 0, 0, NOTE_AS5, 0, 0, 0, 0, 0, NOTE_GS5, 0, 0, NOTE_AS5, 0, 0, NOTE_GS5, 0, 0, NOTE_FS5, 0, 0, NOTE_F5, 0, 0, NOTE_CS5, 0, 0, NOTE_DS5, 0, 0, 0, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_G5, 0, 0, NOTE_FS5, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, NOTE_FS5, 0, 0, NOTE_G5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_G5, 0, 0, NOTE_FS5, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, NOTE_FS5, 0, 0, NOTE_G5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_G5, 0, 0, NOTE_FS5, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0, 0, NOTE_FS5, 0, 0, NOTE_G5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_E5, 0, 0, 0, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_D6, 0, 0, NOTE_E6, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_E6, 0, 0, NOTE_FS6, 0, 0, NOTE_G6, 0, 0, NOTE_FS6, 0, 0, NOTE_E6, 0, 0, NOTE_D6, 0, 0, NOTE_B5, 0, 0, 0, 0, 0, NOTE_A5, 0, 0, NOTE_B5, 0, 0, NOTE_A5, 0, 0, NOTE_G5, 0, 0, NOTE_FS5, 0, 0, NOTE_D5, 0, 0, NOTE_E5, 0
};



/*
void Toneone() {
  int melody[] = { //tone array
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0,
    NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_A3, NOTE_G3,
    NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_A3, NOTE_G3,
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_G3, 0
  };
  int noteDurations[] = {4, 8, 8, 4, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 8, 8, 4, 4};
  for (int thisNote = 0; thisNote < 23; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration); //play tone
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);//delay
    noTone(BUZZER);//tone off
  }
}
*/

void playMusic1() {
    for(int i = 0; i < sizeof(Sheet)/sizeof(Sheet[0]); i++){
        int note = pgm_read_word(&Sheet[i]);
        tone(BUZZER, note, 50);
        delay(50 * 1.3);
        noTone(BUZZER);
    }
}


void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
    playMusic1();
}