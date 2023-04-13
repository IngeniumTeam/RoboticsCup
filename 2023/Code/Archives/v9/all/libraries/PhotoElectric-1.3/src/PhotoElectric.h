#include <Arduino.h>

class PhotoElectric
{
    public:
        PhotoElectric(uint8_t iPin, int iMinCount = 1);
        bool detects();
        bool state();
        uint8_t pin;
        int minCount;
        int count = 0;
};
