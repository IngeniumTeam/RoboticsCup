#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

class Bluetooth
{
    public:
        Bluetooth(Stream *stream);
        bool receive();
        bool send();
        void empty();
        char read();
        void print(String data = "");
        void println(String data = "");
        String message;
        Stream *serial;
        StaticJsonDocument<300> json;
        DeserializationError lastError;
};
