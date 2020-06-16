# Bottlender prototype
# Table of contents
- [Usage](https://github.com/Onii-Chaan/Bottlender-prototype#usage)
- [Libraries used](https://github.com/Onii-Chaan/Bottlender-prototype#libraries-used)
  - [Bluetooth.h](https://github.com/Onii-Chaan/Bottlender-prototype#bluetoothh)
  - [Motor.h](https://github.com/Onii-Chaan/Bottlender-prototype#motorh)
  - [Switch.h](https://github.com/Onii-Chaan/Bottlender-prototype#switchh)
  - [Other libraries](https://github.com/Onii-Chaan/Bottlender-prototype#other-libraries)
- [Setup](https://github.com/Onii-Chaan/Bottlender-prototype#setup)
    - [ESP32](https://github.com/Onii-Chaan/Bottlender-prototype#esp32)
    - [Android](https://github.com/Onii-Chaan/Bottlender-prototype#android)
- [Circuit & result](https://github.com/Onii-Chaan/Bottlender-prototype#circuit--result)

# Usage
THIS IS PROTOTYPE!

This is mobile app code and hardware code + circuit for automatic air cannon. It was made during Sporthack 2020 to deliver small packages that would fall down from air using parachutes. The mechanical part is not included. This cannon is built like a turret and can be made to shoot at certain locations using formulas and right calculations. 

App was made using Nativescript and Angular, hardware was made using Node MCU ESP32S in C.

# Libraries used
For ESP32 I made 3 libraries for hardware control (they are in lib folder)
- Bluetooth.h
- Motor.h
- Switch.h

## Bluetooth.h
This library uses 3 additional ESP32 libraries, BLEDevice.h, BLEUtils.h, BLEServer.h for using Bluetooth v4 on ESP
- ```void checkNewData()``` checks if vale in BTv4 characteristic has been changed
- ```bool getNewData()``` if there are new data then returns true
- ```int getXAxis()``` returns X axis value
- ```int getYAxis()``` returns Y axis value
- ```bool getShoot()``` returns bool if cannon should shoot
- ```bool getReload()``` returns bool if cannon needs to be reload 
- ```void setup()``` starts Bluetooth and configures everything in object
- ```void loop()``` checks for new data, must be in main loop

## Motor.h
Used for controlling stepper motors with A4988 drivers
- ```Motor(int stepsPerRevolution, byte stepPin, byte dirPin, int step)``` initialzies object
    - ```int StepsPerRevolution``` how many steps should motor do to make one full rotation for stepper itself or gear attached to it
    - ```byte stepPin``` goes to a4988 step pin
    - ```byte dirPin``` goes to a4988 dir pin
    - ```int step``` how many rotations should motor to to make one step (more than 1 if gears are attached to stepper motor)
- ```void setup()``` setups motors
- ```void loop()``` goes to set motor position
- ```setPosition()``` sets new position for motors (0 - 360, received from bluetooth object)

## Switch.h
Used for turning on and off relays
- ```Switch(byte switchPin, int delayTime)```
    - ```byte switchPin``` switch pin
    - ```int delayTime``` time in millis for how long should switch be turned on
- ```void setup()``` starts object
- ```void loop()``` runs switch
- ```void toggle()``` turns on switch

## Other libraries
For nativescript app NativeScriptUISideDrawerModule, Bluetooth was used

# Setup
This repository contains code part only, not a whole build
## ESP32
PlatformIO was used to upload and setup the code, put lib and src folders into corresponding places and it should work. 

## Android
Nativescript and Angular were used to make this app. Put the components and other files into corresponding places.

Install Nativescript Bluetooth plugin and RadSideDrawer plugin!!

To make connection with hardware go to Bluetooth page and wait for connection, if it doesn't work, press connect. After connection go to input and input how many ammunition you put in cannon. After that you can go to main page and control the turret. Hardware doesn't take two equal input, so you can't shoot twice and must reload after every time.

# Circuit & result
![Circuit](https://imgbbb.com/images/2020/05/27/gunCircuit2.png)
![Result](https://i.ibb.co/S7mphKz/f483292f-f390-4c65-8ba4-2fffa17ebd23.jpg)
