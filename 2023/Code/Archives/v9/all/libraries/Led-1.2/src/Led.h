#include <Arduino.h>

class Led
{
    public:
        Led(uint8_t iPin, bool iReversed = false);
        void on();
        void off();
        void toggle();
        void blink(int delayTime, int times);
    private:
        void apply();
        uint8_t pin;
        bool reversed = false;
        bool state;
};

class LedRGBAnalog
{
    public:
        LedRGBAnalog(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iAnode = false);
        void on(int iR, int iG, int iB);
        void on();
        void off();
        void toggle();
        void blink(int delayTime, int times);
    private:
        void apply();
        uint8_t pins[3];
        bool anode = false;
        bool state;
        int r = 255;
        int g = 255;
        int b = 255;
};

class LedRGB
{
    public:
        LedRGB(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iAnode = false);
        void on(bool iR, bool iG, bool iB);
        void on();
        void off();
        void toggle();
        void blink(int delayTime, int times);
    private:
        void apply();
        uint8_t pins[3];
        bool anode = false;
        bool state;
        bool r;
        bool g;
        bool b;
};
