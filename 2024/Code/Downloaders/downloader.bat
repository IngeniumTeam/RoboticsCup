@ECHO OFF
set /p sketchPath=Please enter the full path of the arduino sketchbook: 
set libs=IngeniumTeam/BlackLineSensor IngeniumTeam/Bluetooth IngeniumTeam/Button IngeniumTeam/Cherry IngeniumTeam/HCSR04 IngeniumTeam/Joystick IngeniumTeam/Led IngeniumTeam/Mecanum IngeniumTeam/Motor IngeniumTeam/StepperMotor IngeniumTeam/Digit IngeniumTeam/Potentiometer IngeniumTeam/Report SimonPucheu/Timino bblanchon/ArduinoJson Chris--A/Keypad avishorp/TM1637 waspinator/AccelStepper
set repos=IngeniumTeam/Bull IngeniumTeam/Dozer24
(for %%a in (%libs%) do (
    echo %%a
))
(for %%a in (%repos%) do (
    echo %%a
))
set /p confirm=This program will download and extract the above list of releases in the specified path. Press ENTER to confirm.
(for %%a in (%libs%) do (
    powershell -ExecutionPolicy bypass -Command "Invoke-WebRequest https://github.com/%%a/archive/refs/tags/$((Invoke-WebRequest -URI https://api.github.com/repos/%%a/releases/latest -UseBasicParsing | ConvertFrom-Json).tag_name).zip -OutFile lib.zip -UseBasicParsing; Expand-Archive lib.zip -DestinationPath %sketchPath%/libraries -Force"
))
(for %%a in (%repos%) do (
    powershell -ExecutionPolicy bypass -Command "$name=('%%a' -split '/')[1]; $tag=(Invoke-WebRequest -URI https://api.github.com/repos/%%a/releases/latest | ConvertFrom-Json).tag_name; Invoke-WebRequest https://github.com/%%a/archive/refs/tags/$($tag).zip -OutFile lib.zip; Expand-Archive lib.zip -DestinationPath %sketchPath%/ -Force"
))
del lib.zip
timeout /t 10
