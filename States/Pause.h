#ifndef PAUSE_H
#define PAUSE_H

#include "utility.h"

class Pause: public State {

    public:
        Pause(Data& gameData);
        ~Pause();
        
        void update();
        void draw();
        
    private:
        Data& _gameData;
    
        //cursor position
        uint8_t _cursorX, _cursorY;

        //function to draw cursor
        void draw_cursor(uint8_t x, uint8_t y);

};

#endif /* PAUSE_H */