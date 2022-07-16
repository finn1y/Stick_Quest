#ifndef WORLD_H
#define WORLD_H

#include "utility.h"

class World {
    
    public:
        World(Data& gameData);
        ~World();
        
        //get world variables
        IntRect get_viewPort();
        std::vector<IntRect> get_worldRects();
        std::vector<IntVector2D> get_enemyPositions();
        std::vector<IntVector2D> get_punchBagPositions();
        IntVector2D get_playerPosition();
        IntVector2D get_goal();
        
        void reset_level();
        void update_level(uint8_t level_number);
        
        void move_viewPort(IntVector2D offset);
        
        void update();
        void draw();
        void draw_foreground();
    
    private:
        Data& _gameData;
        //view port defines the area if the world currently displayed on the LCD
        IntRect _viewPort;
        
        //level variable
        uint8_t _level;
        
        //level limit variables
        int16_t _levelLimitMin, _levelLimitMax;
        //vector of all world rects and clouds in level
        std::vector<IntRect> _worldRects;
        std::vector<IntVector2D> _clouds;
        //vector of all enemy starting positios in level
        std::vector<IntVector2D> _enemyPositions;
        //player starting position in level
        IntVector2D _playerPosition;
        //goal position in level
        IntVector2D _goal;
        
        //functions to draw background
        void draw_joyLeftRight(int16_t x, int16_t y);
        void draw_joyJump(int16_t x, int16_t y);
        void draw_buttonA(int16_t x, int16_t y);
        void draw_goalArrow(int16_t x, int16_t y);
        void draw_ledsArrow(int16_t x, int16_t y);
        void draw_background();
        void draw_cloud(int16_t x, int16_t y);
        void draw_goal(int16_t x, int16_t y);
        
};

//unique pointer to the world class
typedef std::unique_ptr<World> world_ptr;

#endif /* WORLD_H */