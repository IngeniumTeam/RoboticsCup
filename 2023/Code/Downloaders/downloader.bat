@ECHO OFF
set /p sketchPath=Please enter the full path of the arduino sketchbook: 
set owner=IngeniumTeam
set libs=%owner%/BlackLineSensor %owner%/Bluetooth %owner%/Button %owner%/Cherry %owner%/HCSR04 %owner%/Joystick %owner%/Led %owner%/Mecanum %owner%/Motor %owner%/PhotoElectric %owner%/Digit %owner%/Potentiometer %owner%/Report SimonPucheu/Timino bblanchon/ArduinoJson Chris--A/Keypad
set repos=%owner%/Bull %owner%/Dozer %owner%/Superbowl
(for %%a in (%libs%) do (
    echo %%a
))
(for %%a in (%repos%) do (
    echo %%a
))
set /p confirm=This program will download and extract the above list of releases in the specified path. Press ENTER to confirm.
(for %%a in (%libs%) do (
    powershell -ExecutionPolicy bypass -Command "Invoke-WebRequest https://github.com/%%a/archive/refs/tags/$((Invoke-WebRequest -URI https://api.github.com/repos/%%a/releases/latest | ConvertFrom-Json).tag_name).zip -OutFile lib.zip; Expand-Archive lib.zip -DestinationPath %sketchPath%/libraries -Force"
))
(for %%a in (%repos%) do (
    powershell -ExecutionPolicy bypass -Command "$name=('%%a' -split '/')[1]; $tag=(Invoke-WebRequest -URI https://api.github.com/repos/%%a/releases/latest | ConvertFrom-Json).tag_name; Invoke-WebRequest https://github.com/%%a/archive/refs/tags/$($tag).zip -OutFile lib.zip; Expand-Archive lib.zip -DestinationPath %sketchPath%/ -Force"
))
del lib.zip
timeout /t 10
