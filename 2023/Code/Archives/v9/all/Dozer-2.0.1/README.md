# Dozer
This is the robot code from the Ingenium team.

## Software
### Description
The [src code](./src/) consists of an arduino sketch containing:
* [`Dozer.ino`](#dozerino)
* [`AutoPilot.h`](#autopiloth)

#### [`Dozer.ino`](./src/Dozer/Dozer.ino)
##### Receive values
* Read values received by `Bluetooth` on the `Serial1` and deserialize them with the [ArduinoJson](https://github.com/bblanchon/ArduinoJson)

##### Robot control
* `switch...case` the value of the keypad and make actions:

| Number | Key    | Action                 | Description                          |
| :----: | :----: | ---------------------- | ------------------------------------ |
| 1      | 1      | collect cherries       | bring the cherries on board          |
| 2      | 2      | drop cherries (basket) | drop the cherries in the basket      |
| 3      | 3      | drop cherries (cake)   | drop the cherries on the top of the cake |
| 4      | 4      | line on left           | Go to the left until find the line   |
| 5      | 5      | follow line            | Follow the line until the robot stops due to obstacle detection |
| 6      | 6      | line on right          | Go to the right until find the line  |
| 7      | 7      |                        |                                      |
| 8      | 8      |                        |                                      |
| 9      | 9      |                        |                                      |
| 10     | #      |                        |                                      |
| 11     | 0      | stop                   | stop the robot (motor and actuators) |
| 12     | *      | win dance!             | do a little win dance                |

* Read the value of the switch on the top of the bull and open/close the fence of the cakes

* Control the motors according the values of the joysticks

#### [`AutoPilot.h`](./src/Dozer/AutoPilot.h)
Provides auto pilot functions such as:
* Follow the black line

### Dependecies
The INO file depends of the following list of libraries:
* [Bluetooth](https://github.com/IngeniumTeam/Bluetooth)
    * [Arduino/SoftwareSerial](https://docs.arduino.cc/learn/built-in-libraries/software-serial): This library is built into the Arduino IDE
    * [bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [Mecanum](https://github.com/IngeniumTeam/Mecanum)
    * [Motor](https://github.com/IngeniumTeam/Motor)
* [BlackLineSensor](https://github.com/IngeniumTeam/BlackLineSensor)
* [HCSR04](https://github.com/IngeniumTeam/HCSR04)
* [Report](https://github.com/IngeniumTeam/Report)

## Hardware
* Arduino Mega 2560
* 4 motors equipped with [mecanum wheels](https://en.wikipedia.org/wiki/Mecanum_wheel)
* HC-05 bluetooth module
