#include "MainMenu.h"
#include "Options.h"
#include "Game.h"

MainMenu::MainMenu(Data& gameData): _gameData(gameData) {
    this->_transition = Null;    

    //init cursor position
    this->_cursorX = 12;
    this->_cursorY = 17;
}

MainMenu::~MainMenu() {}

void MainMenu::update() {
    //reset the state transition to null transition
    this->_transition = Null; 
    //set the LEDs to all on
    this->_gameData.input_manager.set_leds(0b1111);
    //get the direction of the joystick
    Direction dir = this->_gameData.input_manager.get_direction();
    
    //update the position of the cursor using joystick
    if (dir == NW || dir == N || dir == NE) {
        if (this->_cursorX == 3) this->_cursorX = 12;
        if (this->_cursorY == 33) this->_cursorY = 17;
        
        //wait after moving cursor before moving again
        thread_sleep_for(20);
    }
    if (dir == SW || dir == S || dir == SE) {
        if (this->_cursorX == 12) this->_cursorX = 3;
        if (this->_cursorY == 17) this->_cursorY = 33;
        
        thread_sleep_for(20);
    }
    
    //update the state transition
    if (this->_gameData.input_manager.check_flag(ButtonAFlag)) {
        if (this->_cursorY == 17) this->_transition = Forward2;
        if (this->_cursorY == 33) this->_transition = Forward1;    
    }
}

void MainMenu::draw() {
    this->_gameData.lcd.clear();
    
    //print the main menu text
    this->_gameData.lcd.printString("Stick Quest", (WIDTH / 2) - 33, 0);
    this->_gameData.lcd.drawLine( (WIDTH / 2) - 33, 7, (WIDTH / 2) + 31, 7, 1);
    this->_gameData.lcd.printString("Play", 30, 2);
    this->_gameData.lcd.printString("Options", 21, 4);
    //print the cursor
    this->draw_cursor(this->_cursorX, this->_cursorY);
    
    this->_gameData.lcd.refresh();
}

void MainMenu::draw_cursor(uint8_t x, uint8_t y) {
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