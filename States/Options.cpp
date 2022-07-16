#include "Options.h"

Options::Options(Data& gameData): _gameData(gameData) {
    this->_transition = Null;
    //init the cursor position
    this->_cursorX = 2;
    this->_cursorY = 9; 
    //init difficulty select position
    this->_difficultyX = 33;
    this->_difficultyY = 31;
    //init contrast vriable
    this->_contrast = 0.5f;
    //init selected variables
    this->_contrast_sel = false;
    this->_difficulty_sel = false;
}

Options::~Options() {}

void Options::update() {
    //reset state transition to null transition
    this->_transition = Null;
    //get the direction of the joystick
    Direction dir = this->_gameData.input_manager.get_direction();
    
    //if contrast is selected in the menu run this block
    if (this->_contrast_sel) {        
        if (dir == NE || dir == E || dir == SE) {
            if (this->_contrast < 1.0f) this->_contrast += 0.1f;
            
            //wait after adjusting contrast before adjusting again
            thread_sleep_for(20);
        }
        if (dir == NW || dir == W || dir == SW) {
            if (this->_contrast > 0.0f) this->_contrast -= 0.1f;
            
            thread_sleep_for(20);
        }
        this->_gameData.lcd.setContrast(this->_contrast);
        
        if (this->_gameData.input_manager.check_flag(ButtonCFlag)) {
            this->_contrast_sel = false;
        }    
    }
    //if difficulty is selected in the menu run this block
    else if (this->_difficulty_sel) {
        if (dir == NE || dir == E || dir == SE) {
            if (this->_difficultyX == 33) this->_difficultyX = 58;
            if (this->_difficultyX == 7) this->_difficultyX = 33;   
            
            //wait after moving marker before moving again
            thread_sleep_for(20);     
        }
        if (dir == NW || dir == W || dir == SW) {
            if (this->_difficultyX == 33) this->_difficultyX = 7;
            if (this->_difficultyX == 58) this->_difficultyX = 33;
            
            thread_sleep_for(20);
        }
        
        if (this->_gameData.input_manager.check_flag(ButtonAFlag)) {
            //set difficulty variable in game data
            if (this->_difficultyX == 7) this->_gameData.difficulty = 1;
            if (this->_difficultyX == 33) this->_gameData.difficulty = 2;
            if (this->_difficultyX == 58) this->_gameData.difficulty = 3;
            
            this->_difficulty_sel = false;
        }    
    }
    //default block for options menu 
    else {
        //update the position of the cursor with the joystick
        if (dir == NW || dir == N || dir == NE) {
            if (this->_cursorX == 0) this->_cursorX = 2;
            if (this->_cursorY == 17) this->_cursorY = 9;
            if (this->_cursorX == 12) this->_cursorX = 0;
            if (this->_cursorY == 33) this->_cursorY = 17;
        
            //wait after moving cursor before moving again
            thread_sleep_for(20);
        }
        if (dir == SW || dir == S || dir == SE) {
            if (this->_cursorX == 0) this->_cursorX = 12;
            if (this->_cursorY == 17) this->_cursorY = 33;
            if (this->_cursorX == 2) this->_cursorX = 0;
            if (this->_cursorY == 9) this->_cursorY = 17;
        
            thread_sleep_for(20);
        } 
        
        
        if (this->_gameData.input_manager.check_flag(ButtonAFlag)) {
            //update selection variables
            if (this->_cursorY == 9) this->_contrast_sel = true;
            if (this->_cursorY == 17) this->_difficulty_sel = true;
            //update state transition
            if (this->_cursorY == 33) {
                //next state is dependent on the previous state
                if (this->_gameData.previous_state == MainMenuState) this->_transition = Forward1;
                if (this->_gameData.previous_state == PauseState) this->_transition = Forward2;
            }
        }    
    }
}

void Options::draw_cursor(uint8_t x, uint8_t y) {
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

void Options::draw_arrows(uint8_t x, uint8_t y) {
    this->_gameData.lcd.setPixel(x + 2, y);
    this->_gameData.lcd.setPixel(x + 57, y);
    
    this->_gameData.lcd.setPixel(x + 1, y + 1);
    this->_gameData.lcd.setPixel(x + 2, y + 1);
    this->_gameData.lcd.setPixel(x + 57, y + 1);
    this->_gameData.lcd.setPixel(x + 58, y + 1);
    
    this->_gameData.lcd.setPixel(x, y + 2);
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 2, y + 2);
    this->_gameData.lcd.setPixel(x + 57, y + 2);
    this->_gameData.lcd.setPixel(x + 58, y + 2);
    this->_gameData.lcd.setPixel(x + 59, y + 2);
    
    this->_gameData.lcd.setPixel(x + 1, y + 3);
    this->_gameData.lcd.setPixel(x + 2, y + 3);
    this->_gameData.lcd.setPixel(x + 57, y + 3);
    this->_gameData.lcd.setPixel(x + 58, y + 3);
    
    this->_gameData.lcd.setPixel(x + 2, y + 4);
    this->_gameData.lcd.setPixel(x + 57, y + 4);
}

void Options::draw() {
    this->_gameData.lcd.clear();
    
    //first print the necessary selection item, i.e. contrast arrows or option menu cursor
    if (this->_contrast_sel) {
        //print contrast selection arrows
        this->draw_arrows(11, 9);   
    }
    else if (!this->_difficulty_sel) {
        //print the cursor
        this->draw_cursor(this->_cursorX, this->_cursorY);
    }
    
    //print the options menu text
    this->_gameData.lcd.printString("OPTIONS", 21, 0);
    this->_gameData.lcd.printString("Contrast", 18, 1);
    
    this->_gameData.lcd.printString("Difficulty", 14, 2);
    this->_gameData.lcd.printString("Easy", 5, 3);
    this->_gameData.lcd.printString("Med", 33, 3);
    this->_gameData.lcd.printString("Hard", 56, 3);
    //difficulty selection item always drawn to show current difficulty setting
    this->_gameData.lcd.drawLine(this->_difficultyX, this->_difficultyY, this->_difficultyX + 16, this->_difficultyY, 1);
    
    this->_gameData.lcd.printString("Back", 30, 4);
    
    this->_gameData.lcd.refresh();    
}