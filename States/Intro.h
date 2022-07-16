#ifndef INTRO_H
#define INTRO_H

#include "utility.h"

//class for the 'intro' state 
//draws a splash screen
class Intro: public State {

    public:
        Intro(Data& gameData);
        ~Intro();
        
        void update();
        void draw();
        
    private:
        Data& _gameData;
    
        const int _splash[12][12] = {
                        {1,0,0,0,1,1,1,1,0,0,0,1},
                        {0,1,0,0,1,1,1,1,0,0,1,0},
                        {0,0,1,0,1,1,1,1,0,1,0,0},
                        {0,0,0,1,0,1,1,0,1,0,0,0},
                        {1,1,1,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,1,1,0,0,0,0,0},
                        {0,0,0,0,0,1,1,0,0,0,0,0},
                        {0,0,0,0,0,1,1,0,0,0,0,0},
                        {0,0,0,0,1,1,1,1,0,0,0,0},
                        {0,0,0,1,1,0,0,1,1,0,0,0},
                        {0,0,1,0,1,0,0,1,0,1,0,0},
                        {0,1,0,0,1,0,0,1,0,0,1,0},
            };

};

#endif /* INTRO_H */