#include "InputManager.h"
#include "mbed.h"

InputManager::InputManager() {
    this->_joystick = new Joystick(p20,p19);
    
    this->_buttonJoy = new InterruptIn(p17);
    this->_buttonA = new InterruptIn(p29);
    this->_buttonC = new InterruptIn(p27);
    
    this->_leds = new BusOut(LED4, LED3, LED2, LED1);
    this->_rgb = new BusOut(p24, p23, p22);
}

InputManager::~InputManager() {
    delete this->_joystick;
    delete this->_buttonJoy;
    delete this->_buttonA;
    delete this->_buttonC;
    delete this->_leds;
    delete this->_rgb;    
}

void InputManager::init() {
    //init joystick
    this->_joystick->init();
    
    //init button internal pull resistors
    this->_buttonA->mode(PullNone);
    this->_buttonC->mode(PullNone);
    //init button interrupts
    this->_buttonJoy->rise(callback(this, &InputManager::buttonJoy_isr));
    this->_buttonA->rise(callback(this, &InputManager::buttonA_isr));
    this->_buttonC->rise(callback(this, &InputManager::buttonC_isr));

    //init interrupt flags
    this->_buttonJoy_flag = 0;
    this->_buttonA_flag = 0;
    this->_buttonC_flag = 0;
    
    //init leds
    this->_leds->write(0b0000);
    this->_rgb->write(0b000);
}

//function to get joystick direction, direction enum defined in Joystick.h
Direction InputManager::get_direction() {
    return this->_joystick->get_direction();    
}

//function to check any interrupt flag status
//will also clear the flag if necessary
uint8_t InputManager::check_flag(Flags flag) {
    //init output variable
    uint8_t flag_status = 0;
    
    //switch statement used to determine the flag to check
    switch (flag) {
        case (ButtonJoyFlag):
            //check the status of the desired flag
            if (this->_buttonJoy_flag) {
                //output variable set if flag is set                
                flag_status = 1;
                //automatically resets flag                 
                this->_buttonJoy_flag = 0;
            }
            break;
        
        case (ButtonAFlag):
            if (this->_buttonA_flag) {
                flag_status = 1;
                this->_buttonA_flag = 0;
            }
            break;
            
        case (ButtonCFlag):
            if (this->_buttonC_flag) {
                flag_status = 1;
                this->_buttonC_flag = 0;    
            }
            break;
            
    }
    
    return flag_status; 
}

//function to set LEDs using bus out - 4-bit binary value
void InputManager::set_leds(uint8_t leds) {
    this->_leds->write(leds);
}

//function to get the current value of the LEDs - 4-bit binary value
uint8_t InputManager::get_leds() {
    return this->_leds->read();    
}

//function to set RGB LED using bus out - 3-bit binary value
void InputManager::set_rgb(uint8_t rgb) {
    this->_rgb->write(rgb);
}

//function to get the current value of the RGB LED - 3-bit binary value
uint8_t InputManager::get_rgb() {
    return this->_rgb->read();    
}

/***** interrupt service routines *****/

void InputManager::buttonJoy_isr() {
    this->_buttonJoy_flag = 1;    
}

void InputManager::buttonA_isr() {
    this->_buttonA_flag = 1;
}

void InputManager::buttonC_isr() {
    this->_buttonC_flag = 1;
}