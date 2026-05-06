# Arduino Custom Bluetooth Controller
* *Disclaimer: This controller is NOT perfect. This was just a project for my HS Comp-Sci class.

This is code for a gamepad controller made with an Arduino ESP32 microcontroller which I also wired a board for.
It allows for 4 different buttons and 1 joystick. It was made to suit top-down 2D games. It's been tested on Android devices, 
but feel free to test it or alter it for PC as well.

## Requirements
- a wired breadboard with 4 buttons and a joystick that has VRX, VRY, +5V and GND pins
- an ESP32
- a USB-A to USB-C cable or USB-C to USB-C cable 
- an installation of VScode with the pioarduino plugin and dependencies listed in the platformio.ini 

## How to run it
Simply import the repo into VScode, and then upload it to the microcontroller by plugging in the USB-C cable into it and connecting it to your computer.
The controller does not have a battery, so it also needs the the USB-C cable to provide power.
Once uploaded, make sure bluetooth is enabled on the device you wish to connect the controller to, and pair the device "Yuko's Gamepad". 
From there it should work!

## Wiring Schematic
### Microcontroller used: ESP32 - NodeMCU-32S Microcontroller

joystick VRX -> GPIO15 w/capacitor connecting to ground
joystick VRY -> GPIO4
joystick +5V -> 5V0

A button -> GPIO12, GND
B button -> GPIO14, GND
X button -> GPIO26, GND
Y button -> GPIO27, GND
ESP32 GND pin connecting to ground 
ESP32 5V0 connecting to ground
