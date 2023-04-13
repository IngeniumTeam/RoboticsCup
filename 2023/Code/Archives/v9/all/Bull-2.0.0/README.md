# Bull
This is the remote control code from the Ingenium team.

## Software
### Description
The [src code](./src/) consists of an arduino sketch containing a `.ino` file:

#### Reading values
* The values of the sensors such as the joysticks are readed by the librairies (listed in the [Dependecies](#dependecies))

#### Sending values
* The sending data are encoded in a json format with the [ArduinoJson](https://github.com/bblanchon/ArduinoJson) library following the next template:
```json
{
    "switch": true,
    "keypad": 3,
    "joysticks": {
        "left": {
            "x": 512,
            "y": 512,
            "clck": true
        },
        "right": {
            "x": 512,
            "y": 512,
            "clck": false
        }
    }
}
```
* Then, there are send via [SoftwareSerial](https://docs.arduino.cc/learn/built-in-libraries/software-serial) to the bluetooth module every 40 milliseconds (about 25 times per second)

**N.B.** All this process is done by the [Bluetooth](https://github.com/IngeniumTeam/Bluetooth) library

### Dependecies
The INO file depends of the following list of libraries:
* [Bluetooth](https://github.com/IngeniumTeam/Bluetooth)
    * [Arduino/SoftwareSerial](https://docs.arduino.cc/learn/built-in-libraries/software-serial): This library is built into the Arduino IDE
    * [bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [Joystick](https://github.com/IngeniumTeam/Joystick)
    * [Potentiometer](https://github.com/IngeniumTeam/Potentiometer)
    * [Button](https://github.com/IngeniumTeam/Button)
* [Led](https://github.com/IngeniumTeam/Led)
* [Report](https://github.com/IngeniumTeam/Report)
* [Chris--A/Keypad](https://github.com/Chris--A/Keypad)

## Hardware
* Arduino Nano
* Two double-axes potentiometers (joysticks)
* Three LEDs
* Switch
* ON/OFF switch
* 4x3 matrix keypad :

|<!---->|<!---->|<!---->|
|:-:|:-:|:-:|
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
| # | 0 | * |

* HC-05 bluetooth module
