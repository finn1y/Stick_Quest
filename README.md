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
+ Push buttons
+ RGB LED
+ Joystick
+ Nokia 5110 LCD

### LPC1768 pinout

![Microcontroller_image](https://user-images.githubusercontent.com/75081535/180607982-215dc5e2-1476-4e84-b12e-1a585eefa617.png)

### Pin connections

Peripheral    | Peripheral connections | LPC1786 pin
--------------|------------------------|--------------
Push Button A | pin                    | p29
Push Button B | pin                    | p28
Push Button C | pin                    | p27
Push Button D | pin                    | p26
RGB LED       | Red                    | p22
"             | Green                  | p23
"             | Blue                   | p24
Joystick      | Button                 | p17
"             | Horizontal             | p19
"             | Vertical               | p20
Nokia 5110 LCD| Vcc                    | p14
"             | SCE                    | p8
"             | Reset                  | p9
"             | D/C                    | p10
"             | MOSI                   | p11
"             | SCLK                   | p13
"             | LED Backlight          | p21
