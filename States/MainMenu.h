#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "utility.h"

//class for the main menu
class MainMenu: public State {

    public:
        MainMenu(Data& gameData);
        ~MainMenu();
        
        void update();
        void draw();
        
    private:
        Data& _gameData;

        //cursor position
        uint8_t _cursorX, _cursorY;

        //function to draw cursor    
        void draw_cursor(uint8_t x, uint8_t y);
        
};

#endif /* MAIN_MENU_H */