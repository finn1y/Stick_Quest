#include "Pause.h"
#include "MainMenu.h"
#include "Options.h"

Pause::Pause(Data& gameData): _gameData(gameData) {
    this->_transition = Null;
    //init the cursor position
    this->_cursorX = 13;
    this->_cursorY = 9;
}

Pause::~Pause() {}

void Pause::update() {
    //reset the state transition to null transition
    this->_transition = Null;
    //get the direction of the joystick
    Direction dir = this->_gameData.input_manager.get_direction();
    
    //update the position of the cursor with the joystick
    if (dir == NW || dir == N || dir == NE) {
        if (this->_cursorY == 17) this->_cursorY = 9;
        if (this->_cursorY == 25) this->_cursorY = 17;
        
        //wait after moving cursor before moving again
        thread_sleep_for(20);
    }
    if (dir == SW || dir == S || dir == SE) {
        if (this->_cursorY == 17) this->_cursorY = 25;
        if (this->_cursorY == 9) this->_cursorY = 17;
        
        thread_sleep_for(20);
    } 
    
    //update the state transition
    if (this->_gameData.input_manager.check_flag(ButtonAFlag)) {
        if (this->_cursorY == 9) this->_transition = Back;
        if (this->_cursorY == 17) this->_transition = Forward1;
        if (this->_cursorY == 25) this->_transition = Forward2;
    }
}

void Pause::draw_cursor(uint8_t x, uint8_t y) {
    this->_gameData.lcd.setPixel(x + 3, y);
    this->_gameData.lcd.setPixel(x + 4, y);
    
    this->_gameData.lcd.setPixel(x + 3, y + 1);
    this->_gameData.lcd.setPixel(x + 4, y + 1);
    this->_gameData.lcd.setPixel(x + 5, y + 1);
    this->_gameData.lcd.setPixel(x + 6, y + 1);
    this->_gameData.lcd.setPixel(x + 7, y + 1);
    this->_gameData.lcd.setPixel(x + 8, y + 1);
    this->_gameData.lcd.setPixel(x + 9, y + 1);
    this->_gameData.lcd.setPixel(x + 10, y + 1);
    this->_gameData.lcd.setPixel(x + 11, y + 1);
    
    this->_gameData.lcd.setPixel(x, y + 2);
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 2, y + 2);
    this->_gameData.lcd.setPixel(x + 3, y + 2);
    this->_gameData.lcd.setPixel(x + 4, y + 2);
    this->_gameData.lcd.setPixel(x + 5, y + 2);
    this->_gameData.lcd.setPixel(x + 6, y + 2);
    this->_gameData.lcd.setPixel(x + 7, y + 2);
    this->_gameData.lcd.setPixel(x + 8, y + 2);
    this->_gameData.lcd.setPixel(x + 9, y + 2);
    this->_gameData.lcd.setPixel(x + 10, y + 2);
    this->_gameData.lcd.setPixel(x + 11, y + 2);
    this->_gameData.lcd.setPixel(x + 12, y + 2);
    
    this->_gameData.lcd.setPixel(x + 3, y + 3);
    this->_gameData.lcd.setPixel(x + 4, y + 3);
    this->_gameData.lcd.setPixel(x + 5, y + 3);
    this->_gameData.lcd.setPixel(x + 6, y + 3);
    this->_gameData.lcd.setPixel(x + 7, y + 3);
    this->_gameData.lcd.setPixel(x + 8, y + 3);
    this->_gameData.lcd.setPixel(x + 9, y + 3);
    this->_gameData.lcd.setPixel(x + 10, y + 3);
    this->_gameData.lcd.setPixel(x + 11, y + 3);   
    
    this->_gameData.lcd.setPixel(x + 3, y + 4);
    this->_gameData.lcd.setPixel(x + 4, y + 4); 
} 

void Pause::draw() {
    if (this->_gameData.previous_state == OptionsState) {
        //clear the LCD if the previous state was the options menu
        this->_gameData.lcd.clear();    
    }
    if (this->_gameData.previous_state == GameState) {
        //only the area for the pause menu is cleared if the previous state was the game state
        this->_gameData.lcd.drawRect(10, 6, 64, 27, FILL_WHITE);
    }
    //print the pause menu text
    this->_gameData.lcd.drawRect(10, 6, 64, 27, FILL_TRANSPARENT);
    this->_gameData.lcd.printString("Resume", 30, 1);
    this->_gameData.lcd.printString("Options", 30, 2);
    this->_gameData.lcd.printString("Exit", 30, 3);
    //print the cursor
    this->draw_cursor(this->_cursorX, this->_cursorY);

    this->_gameData.lcd.refresh();    
}