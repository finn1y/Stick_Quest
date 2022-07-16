#ifndef OPTIONS_H
#define OPTIONS_H

#include "utility.h"

class Options: public State {

    public:
        Options(Data& gameData);
        ~Options();
        
        void update();
        void draw();
        
    private:
        Data& _gameData;
            
        //cursor position
        uint8_t _cursorX, _cursorY;
        
        //difficulty select position
        uint8_t _difficultyX, _difficultyY;
        
        //LCD contrast variable
        float _contrast;
        
        //variables for if contrast or difficulty are selected
        bool _contrast_sel, _difficulty_sel;
  
        //functions to draw cursor and selection arrows
        void draw_cursor(uint8_t x, uint8_t y);
        void draw_arrows(uint8_t x, uint8_t y);
        
};

#endif /* OPTIONS_H */