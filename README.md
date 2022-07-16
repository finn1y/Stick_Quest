# Stick_Quest

## About

Stick Quest is a game designed in C++ for the ARM mbed LPC1768 microcontroller with peripherals

## Install

1. Clone repo:
```
git clone https://github.com/finn1y/Stick_Quest.git
```

2. Upload code to online [compiler](https://os.mbed.com/) and compile binary

3. Flash onto microcontroller

4. Enjoy gaming!

## Hardware

The following hardware was used to test the project (pin connections are given for "out of the box" use, if different pin connections are used then the source code must be changed to reflect the new pin connections):
+ mbed LPC1768 Microcontroller
+ Push buttons (connected to pins: D 26, C 27, B 28, A 29)
+ RGB LED (connected to pins: RED 22, GREEN 23, BLUE 24)
+ Joystick (connected to pins: BUTTON 17, HORIZONTAL 19, VERTICAL 20)
+ Nokia 5110 LCD (connected to pins: VCC 14, SCE 8, RESET 9, D/C 10, MOSI 11, SCLK 13, LED BACKLIGHT 21)

### LPC1768 pinout

![Pinout diagram of LPC1768 microcontroller](Microcontroller_image.png)
