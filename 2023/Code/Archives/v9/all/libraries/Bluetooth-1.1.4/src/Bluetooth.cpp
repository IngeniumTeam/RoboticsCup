#include <Arduino.h>

#include "Bluetooth.h"

Bluetooth::Bluetooth(Stream *stream)
{
    serial = stream;
}

/**
 * Function to call each loop of the program
 * 
 * @return bool true if a complet new message is detected and false otherwise
 */
bool Bluetooth::receive()
{
    while (serial -> available() > 0)
    {
        char c = read();
        if (c == '.')
        {
            lastError = deserializeJson(json, *serial);
            return true;
        }
        else
        {
            message += c;
        }
    }
    return false;
}

/**
 * Function to send a message
 * 
 * @return bool true if the operation succeeds and false otherwise
 */
bool Bluetooth::send()
{
    serializeJson(json, *serial);
    print(".");
}

void Bluetooth::empty()
{
    while (serial -> available()) read();
}

/**
 * Function to read current char
 * 
 * @return char the current character in the bluetooth buffer
 */
char Bluetooth::read()
{
    return serial -> read();
}

/**
 * Function to print data on bluetooth
 * 
 * @param String `data` to print on the bluetooth
 */
void Bluetooth::print(String data = "")
{
    serial -> print(data);
}

/**
 * Function to println data on bluetooth
 * 
 * @return char the current character in the bluetooth buffer
 */
void Bluetooth::println(String data = "")
{
    serial -> println(data);
}
