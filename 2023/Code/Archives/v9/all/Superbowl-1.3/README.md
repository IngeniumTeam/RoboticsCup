# Superbowl
This is the basket code from the Ingenium team.

## Software
### Description
The [src code](./src/) consists of an arduino sketch containing a `.ino` file:

* When the photo-electric sensor is obstructed (e.g. by a cherry), the receptor send a `LOW` value:
    * Wait until the cherry is passed to avoid errors
    * Increase the value of the `cherryNumber` variable by 1
    * Display the new value on the digit

### Dependecies
The INO file depends of the following list of libraries:
* [Digit](https://github.com/IngeniumTeam/Digit)
    * [avishorp/TM1637](https://github.com/avishorp/TM1637)
* [PhotoElectric](https://github.com/IngeniumTeam/PhotoElectric)

## Hardware
* Arduino Uno
