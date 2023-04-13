#include <Arduino.h>

class HCSR04
{
    public:
        HCSR04(uint8_t iTriggerPin, uint8_t iEchoPin, int iLowLimit = 1, int iHighLimit = 100);
        int getRawValue();
        int getValue();
        uint8_t triggerPin;
        uint8_t echoPin;
        int lowLimit = 1;
        int highLimit = 100;
};
