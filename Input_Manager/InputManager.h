#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Joystick.h"

// Forward declaration of the classes that we use from the mbed library
// This avoids the need for us to include the huge mbed.h header inside our
// own library API
namespace mbed {
    class InterruptIn;
    class BusOut;
}

//flags for each isr
enum Flags {
    ButtonJoyFlag,
    ButtonAFlag,
    ButtonCFlag,
};

//input manager class to handle all inputs from the application board
//also handles some outputs to the application board, e.g. LEDs
class InputManager {

    public:
        InputManager();
        ~InputManager();
        
        void init();
        
        //function to get joystick direction, direction enum defined in Joystick.h
        Direction get_direction();
        
        //function to check any of the interrupt flags
        //makes use of the flags enum
        uint8_t check_flag(Flags flag);
        
        //functions to control leds and get current value of LEDs
        void set_leds(uint8_t leds);
        uint8_t get_leds();
        void set_rgb(uint8_t rgb);
        uint8_t get_rgb();
    
    private:
        //joystick              y   x  
        Joystick* _joystick; //(p20,p19)
        
        //button interrups
        mbed::InterruptIn* _buttonJoy; //p(17)
        mbed::InterruptIn* _buttonA; //(p29)
        mbed::InterruptIn* _buttonC; //(p27)
        
        //LEDs
        mbed::BusOut* _leds; //(LED4, LED3, LED2, LED1)
        mbed::BusOut* _rgb; //(p24,p23,p22)
        
        //button interrupt flags
        uint8_t _buttonJoy_flag;
        uint8_t _buttonA_flag;
        uint8_t _buttonC_flag;
        
        //button interrupt isr
        void buttonJoy_isr();
        void buttonA_isr();
        void buttonC_isr();
};

#endif /* INPUT_MANAGER_H */