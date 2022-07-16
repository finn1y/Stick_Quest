#include "World.h"

World::World(Data& gameData): _gameData(gameData) {
    this->_viewPort = {{0, 0}, {84, 48}};
    //initial level is level 1
    this->_level = 1;
    this->_levelLimitMin = 0;
    this->_levelLimitMax = 420;
    
    this->_worldRects = {
                //rects outside world limits
                //cause collision to prevent entites leaving world
                {{-2, 0}, {1, 48}},
                {{422, 0}, {1, 48}},
                //world rects within world limits
                //screen 0
                {{0, 45}, {84, 3}}, 
                {{50, 35}, {5 ,10}}, 
                //screen 1
                {{84, 45}, {84, 3}}, 
                //screen 2                
                {{168, 45}, {14, 3}},
                {{204, 45}, {48, 3}},
                {{216, 28}, {22, 2}},
                //screen 3
                {{252, 45}, {84, 3}},
                {{267, 30}, {5, 15}},
                {{316, 30}, {5, 15}},
                //screen 4
                {{336, 45}, {12, 3}},
                {{404, 45}, {16, 3}},
                {{352, 28}, {20, 2}}
            };    
    
    this->_clouds = {
                //screen 1
                {86, 14},
                {132, 10},
                {145, 17},
                {151, 6},
                //screen 2
                {175, 18},
                {224, 4},
                {230, 16},
                //screen 3
                {260, 10},
                {283, 13},
                {302, 5},
                {321, 7},
                //screen 4
                {340, 11},
                {353, 13},
                {384, 6}
            };    
    
    this->_enemyPositions = {
                //screen 1
                {109, 33},
                //screen 2
                {221, 33},
                //screen 3
                {290, 33}                
            };
    
    this->_playerPosition = {10, 33};
    
    this->_goal = {411, 36};
}

World::~World() {}

IntRect World::get_viewPort() {
    return this->_viewPort;    
}

std::vector<IntRect> World::get_worldRects() {
    return this->_worldRects;    
}

std::vector<IntVector2D> World::get_enemyPositions() {
    return this->_enemyPositions;    
}

IntVector2D World::get_playerPosition() {
    return this->_playerPosition;    
}

IntVector2D World::get_goal() {
    return this->_goal;    
}

void World::reset_level() {
    //when level is reset view port should be set to beginning of level
    this->_viewPort = {{0, 0}, {84, 48}};
}

//function to update world variables for new level
void World::update_level(uint8_t level_number) {
    this->_level = level_number;
    
    switch (level_number) {
        case 1:
            //level 1
            this->_levelLimitMin = 0;
            this->_levelLimitMax = 420;
            
            this->_worldRects = {
                    //rects outside world limits
                    //cause collision to prevent entites leaving world
                    {{-2, 0}, {1, 48}},
                    {{422, 0}, {1, 48}},
                    //world rects within world limits
                    //screen 0
                    {{0, 45}, {84, 3}}, 
                    {{50, 35}, {5 ,10}}, 
                    //screen 1
                    {{84, 45}, {84, 3}}, 
                    //screen 2                
                    {{168, 45}, {14, 3}},
                    {{204, 45}, {48, 3}},
                    {{216, 28}, {22, 2}},
                    //screen 3
                    {{252, 45}, {84, 3}},
                    {{267, 30}, {5, 15}},
                    {{316, 30}, {5, 15}},
                    //screen 4
                    {{336, 45}, {12, 3}},
                    {{404, 45}, {16, 3}},
                    {{352, 28}, {20, 2}}
                };    
            
            this->_clouds = {
                        //screen 1
                        {86, 14},
                        {132, 10},
                        {145, 17},
                        {151, 6},
                        //screen 2
                        {175, 18},
                        {224, 4},
                        {230, 16},
                        //screen 3
                        {260, 10},
                        {283, 13},
                        {302, 5},
                        {321, 7},
                        //screen 4
                        {340, 11},
                        {353, 13},
                        {384, 6}
                    };   
            
            this->_enemyPositions = {
                        //screen 1
                        {109, 33},
                        //screen 2
                        {221, 33},
                        //screen 3
                        {290, 33}                
                    };
            
            this->_playerPosition = {10, 33};
            
            this->_goal = {411, 36};
            break; 
            
        case 2:
            //level 2
            this->_levelLimitMin = 0;
            this->_levelLimitMax = 420;
            
            this->_worldRects = {
                        //rects outside world limits
                        //cause collision to prevent entites leaving world
                        {{-2, 0}, {1, 48}},
                        {{422, 0}, {1, 48}},
                        //world rects within world limits
                        //screen 0
                        {{0, 45}, {52, 3}},
                        {{52, 27}, {32, 21}},
                        {{26, 30}, {14, 2}},
                        //screen 1
                        {{84, 27}, {37, 21}},
                        {{95, 24}, {26, 3}},
                        {{144, 23}, {24, 27}},
                        {{153, 14}, {15, 9}},
                        //screen 2
                        {{168, 14}, {15, 34}},
                        {{183, 24}, {44, 24}},
                        {{227, 31}, {25, 17}},
                        //screen 3
                        {{252, 31}, {12, 17}},
                        {{294, 39}, {42, 9}},
                        {{314, 23}, {17, 2}},
                        //screen 4
                        {{336, 39}, {56, 9}},
                        {{392, 21}, {28, 27}}
                    };
            
            this->_clouds = {
                        //screen 0
                        {10, 12},
                        {27, 10},
                        {48, 6},
                        {59, 9},
                        {70, 4},
                        //screen 1
                        {131, 4},
                        {151, 2},
                        //screen 2
                        {221, 4},
                        {237, 8},
                        //screen 3
                        {258, 11},
                        {273, 9},
                        {303, 4},
                        {314, 7},
                        {332, 9},
                        //screen 4
                        {348, 12},
                        {367, 10},
                        {394, 4},
                        {409, 2}
                    };
                 
            this->_enemyPositions = {
                        //screen 1
                        {104, 12},
                        //screen 2
                        {195, 12},
                        {240, 19},
                        //screen 3
                        {315, 27},
                        {318, 11}
                    };
                
            this->_playerPosition = {10, 33};
            
            this->_goal = {408, 12};            
            break;   
            
        case 3:
            //level 3
            this->_levelLimitMin = 0;
            this->_levelLimitMax = 504;
            
            this->_worldRects = {
                        //rects outside world limits
                        //cause collision to prevent entites leaving world
                        {{-2, 0}, {1, 48}},
                        {{506, 0}, {1, 48}},
                        //world rects within world limits
                        //screen 0
                        {{0, 21}, {19, 27}},
                        {{19, 21}, {33, 2}},
                        {{52, 21}, {14, 27}},
                        {{66, 24}, {18, 24}},
                        //screen 1
                        {{84, 24}, {5, 24}},
                        {{89, 29}, {13, 19}},
                        {{102, 35}, {17, 13}},
                        {{119, 39}, {14, 9}},
                        {{133, 42}, {18, 6}},
                        {{151, 45}, {17, 3}},
                        //screen 2
                        {{168, 45}, {20, 3}},
                        {{185, 43}, {36, 2}},
                        {{221, 17}, {21, 5}},
                        {{221, 43}, {21, 5}},
                        {{242, 43}, {44, 5}},
                        {{221, 11}, {4, 6}},
                        {{238, 11}, {4, 6}},
                        //screen 3
                        {{252, 43}, {84, 5}},
                        {{278, 26}, {31, 2}},
                        {{270, 6}, {44, 2}},
                        //screen 4
                        {{336, 43}, {29, 5}},
                        {{377, 37}, {3, 2}},
                        {{379, 18}, {1, 2}},
                        {{380, 17}, {24, 31}},
                        {{380, 10}, {5, 7}},
                        {{403, 15}, {4, 2}},
                        {{406, 13}, {4, 2}},
                        {{409, 11}, {4, 2}}, 
                        {{412, 9}, {4, 2}},
                        {{415, 7}, {4, 2}},
                        {{418, 5}, {4, 2}},
                        //screen 5
                        {{421, 3}, {4, 2}},
                        {{424, 1}, {4, 2}},
                        {{427, -1}, {4, 2}},
                        {{430, -3}, {4, 2}},
                        {{430, -3}, {3, 51}},
                        {{433, -5}, {4, 2}},
                        {{436, -7}, {4, 2}},                        
                        {{439, -7}, {25, 2}},
                        {{439, 36}, {7, 2}},
                        {{461, 45}, {24, 3}},
                        {{501, -7}, {3, 2}},
                        {{501, 0}, {3, 48}}
                    };
            
            this->_clouds = {
                        //screen 0
                        {50, 3},
                        {69, 2},
                        //screen 1
                        {101, 9},
                        {114, 12},
                        {134, 9},
                        {145, 4},                        
                        {156, 15},
                        //screen 2
                        {170, 8},
                        {182, 10},
                        {196, 9},
                        {241, 4},
                        //screen 4
                        {342, -8},
                        {347, 7},
                        {351, -15},
                        {367, -7},                        
                        {386, 3},
                        {390, -2},
                        {409, -12},
                        {416, -4},
                        //screen 5
                        {434, -15},
                        {445, -17},
                        {462, -20},
                        {473, -19}
                    };
                 
            this->_enemyPositions = {
                        //screen 2
                        {227, 5},
                        {227, 31},
                        //screen 3
                        {290, 31},
                        {281, 14},                        
                        //screen 4
                        {387, 5},
                    };
                
            this->_playerPosition = {10, 9};
            
            this->_goal = {440, 27};            
            break;
    }  
}

void World::move_viewPort(IntVector2D offset) {
    //move view port if the new view port is within the world limits
    if (this->_viewPort.position.x + offset.x >= this->_levelLimitMin && this->_viewPort.position.x + this->_viewPort.size.x + offset.x <= this->_levelLimitMax) {
        this->_viewPort.position.x += offset.x;
        this->_viewPort.position.y += offset.y;
    }
}

void World::update() {
    //update screen variable
    this->_gameData.screen.x = this->_viewPort.position.x / 84;  
    this->_gameData.screen.y = this->_viewPort.position.y / 48;  
}

void World::draw_joyLeftRight(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 1, y);
    this->_gameData.lcd.setPixel(x + 5, y);
    this->_gameData.lcd.setPixel(x + 6, y);
    this->_gameData.lcd.setPixel(x + 10, y);
    
    this->_gameData.lcd.setPixel(x, y + 1);
    this->_gameData.lcd.setPixel(x + 1, y + 1);
    this->_gameData.lcd.setPixel(x + 4, y + 1);
    this->_gameData.lcd.setPixel(x + 5, y + 1);
    this->_gameData.lcd.setPixel(x + 6, y + 1);
    this->_gameData.lcd.setPixel(x + 7, y + 1);
    this->_gameData.lcd.setPixel(x + 10, y + 1);
    this->_gameData.lcd.setPixel(x + 11, y + 1);
    
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 4, y + 2);
    this->_gameData.lcd.setPixel(x + 5, y + 2);
    this->_gameData.lcd.setPixel(x + 6, y + 2);
    this->_gameData.lcd.setPixel(x + 7, y + 2);
    this->_gameData.lcd.setPixel(x + 10, y + 2);
    
    this->_gameData.lcd.setPixel(x + 5, y + 3);
    this->_gameData.lcd.setPixel(x + 6, y + 3);
    
    this->_gameData.lcd.setPixel(x + 5, y + 4);
    this->_gameData.lcd.setPixel(x + 6, y + 4);
    
    this->_gameData.lcd.setPixel(x + 3, y + 5);
    this->_gameData.lcd.setPixel(x + 4, y + 5);
    this->_gameData.lcd.setPixel(x + 5, y + 5);
    this->_gameData.lcd.setPixel(x + 6, y + 5);
    this->_gameData.lcd.setPixel(x + 7, y + 5);
    this->_gameData.lcd.setPixel(x + 8, y + 5);
    
    this->_gameData.lcd.setPixel(x + 3, y + 6);
    this->_gameData.lcd.setPixel(x + 4, y + 6);
    this->_gameData.lcd.setPixel(x + 5, y + 6);
    this->_gameData.lcd.setPixel(x + 6, y + 6);
    this->_gameData.lcd.setPixel(x + 7, y + 6);
    this->_gameData.lcd.setPixel(x + 8, y + 6);
}

void World::draw_joyJump(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 1, y);
    this->_gameData.lcd.setPixel(x + 2, y);
    this->_gameData.lcd.setPixel(x + 3, y);
    this->_gameData.lcd.setPixel(x + 4, y);
    
    this->_gameData.lcd.setPixel(x + 2, y + 1);
    this->_gameData.lcd.setPixel(x + 3, y + 1);    
    
    this->_gameData.lcd.setPixel(x + 2, y + 3);    
    this->_gameData.lcd.setPixel(x + 3, y + 3); 
    
    this->_gameData.lcd.setPixel(x + 1, y + 4);    
    this->_gameData.lcd.setPixel(x + 2, y + 4);    
    this->_gameData.lcd.setPixel(x + 3, y + 4);    
    this->_gameData.lcd.setPixel(x + 4, y + 4); 
    
    this->_gameData.lcd.setPixel(x + 1, y + 5);    
    this->_gameData.lcd.setPixel(x + 2, y + 5);    
    this->_gameData.lcd.setPixel(x + 3, y + 5);    
    this->_gameData.lcd.setPixel(x + 4, y + 5);  
    
    this->_gameData.lcd.setPixel(x + 2, y + 6);
    this->_gameData.lcd.setPixel(x + 3, y + 6);    
    
    this->_gameData.lcd.setPixel(x + 2, y + 7);    
    this->_gameData.lcd.setPixel(x + 3, y + 7);   
    
    this->_gameData.lcd.setPixel(x, y + 8);
    this->_gameData.lcd.setPixel(x + 1, y + 8);    
    this->_gameData.lcd.setPixel(x + 2, y + 8);    
    this->_gameData.lcd.setPixel(x + 3, y + 8);    
    this->_gameData.lcd.setPixel(x + 4, y + 8); 
    this->_gameData.lcd.setPixel(x + 5, y + 8);
    
    this->_gameData.lcd.setPixel(x, y + 9);    
    this->_gameData.lcd.setPixel(x + 1, y + 9);    
    this->_gameData.lcd.setPixel(x + 2, y + 9);    
    this->_gameData.lcd.setPixel(x + 3, y + 9);    
    this->_gameData.lcd.setPixel(x + 4, y + 9);      
    this->_gameData.lcd.setPixel(x + 5, y + 9);    
}

void World::draw_buttonA(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 3, y);
    this->_gameData.lcd.setPixel(x + 4, y);
    this->_gameData.lcd.setPixel(x + 5, y);
    
    this->_gameData.lcd.setPixel(x + 2, y + 1);
    this->_gameData.lcd.setPixel(x + 6, y + 1); 
    
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 4, y + 2);    
    this->_gameData.lcd.setPixel(x + 7, y + 2);
    
    this->_gameData.lcd.setPixel(x, y + 3);
    this->_gameData.lcd.setPixel(x + 3, y + 3);
    this->_gameData.lcd.setPixel(x + 5, y + 3);    
    this->_gameData.lcd.setPixel(x + 8, y + 3);
    
    this->_gameData.lcd.setPixel(x, y + 4);
    this->_gameData.lcd.setPixel(x + 3, y + 4);
    this->_gameData.lcd.setPixel(x + 4, y + 4);
    this->_gameData.lcd.setPixel(x + 5, y + 4);    
    this->_gameData.lcd.setPixel(x + 8, y + 4);    
    
    this->_gameData.lcd.setPixel(x + 1, y + 5);
    this->_gameData.lcd.setPixel(x + 3, y + 5);    
    this->_gameData.lcd.setPixel(x + 5, y + 5);
    this->_gameData.lcd.setPixel(x + 7, y + 5);
    
    this->_gameData.lcd.setPixel(x + 2, y + 6);
    this->_gameData.lcd.setPixel(x + 6, y + 6); 

    this->_gameData.lcd.setPixel(x + 3, y + 7);
    this->_gameData.lcd.setPixel(x + 4, y + 7);
    this->_gameData.lcd.setPixel(x + 5, y + 7);
} 

void World::draw_ledsArrow(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 2, y);    

    this->_gameData.lcd.setPixel(x + 1, y + 1);
    this->_gameData.lcd.setPixel(x + 2, y + 1); 
    this->_gameData.lcd.setPixel(x + 3, y + 1);
    this->_gameData.lcd.setPixel(x + 4, y + 1); 
    this->_gameData.lcd.setPixel(x + 5, y + 1);
    this->_gameData.lcd.setPixel(x + 6, y + 1); 

    this->_gameData.lcd.setPixel(x, y + 2); 
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 2, y + 2); 
    this->_gameData.lcd.setPixel(x + 3, y + 2);
    this->_gameData.lcd.setPixel(x + 4, y + 2); 
    this->_gameData.lcd.setPixel(x + 5, y + 2);
    this->_gameData.lcd.setPixel(x + 6, y + 2); 

    this->_gameData.lcd.setPixel(x + 1, y + 3);
    this->_gameData.lcd.setPixel(x + 2, y + 3); 
    this->_gameData.lcd.setPixel(x + 3, y + 3);
    this->_gameData.lcd.setPixel(x + 4, y + 3); 
    this->_gameData.lcd.setPixel(x + 5, y + 3);
    this->_gameData.lcd.setPixel(x + 6, y + 3);

    this->_gameData.lcd.setPixel(x + 2, y + 4);  
}

void World::draw_goalArrow(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 1, y);
    this->_gameData.lcd.setPixel(x + 2, y); 
    this->_gameData.lcd.setPixel(x + 3, y);

    this->_gameData.lcd.setPixel(x + 1, y + 1);
    this->_gameData.lcd.setPixel(x + 2, y + 1); 
    this->_gameData.lcd.setPixel(x + 3, y + 1);
    
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 2, y + 2); 
    this->_gameData.lcd.setPixel(x + 3, y + 2);

    this->_gameData.lcd.setPixel(x, y + 3);
    this->_gameData.lcd.setPixel(x + 1, y + 3);
    this->_gameData.lcd.setPixel(x + 2, y + 3); 
    this->_gameData.lcd.setPixel(x + 3, y + 3);
    this->_gameData.lcd.setPixel(x + 4, y + 3);

    this->_gameData.lcd.setPixel(x + 1, y + 4);
    this->_gameData.lcd.setPixel(x + 2, y + 4); 
    this->_gameData.lcd.setPixel(x + 3, y + 4);
    
    this->_gameData.lcd.setPixel(x + 2, y + 5);
}

//function for drawing instructions/controls to background
//only on level 1
void World::draw_background() {
    if (!this->_gameData.screen.y) {
        switch (this->_gameData.screen.x) {
            //screen 0
            case 0:
                this->_gameData.lcd.printString("Move", 11, 2);
                this->draw_joyLeftRight(16, 8);
        
                this->_gameData.lcd.printString("Jump", 50, 2);
                this->draw_joyJump(58, 5);
                break;
            
            //screen 1
            case 1:
                this->_gameData.lcd.printString("Attack", 15, 2);
                this->draw_buttonA(27, 7);
                break;
                
            //screen 2
            case 2:
                this->_gameData.lcd.printString("Lives", 13, 1);
                this->draw_ledsArrow(2, 9);
                break;
                
            //screen 3
            case 3:
                break;
                
            //screen 4
            case 4:
                this->_gameData.lcd.printString("Goal", 60, 1);
                this->draw_goalArrow(74, 18);
                break;            
                
            default:
                break;
        }
    }
}

void World::draw_cloud(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 2, y);
    this->_gameData.lcd.setPixel(x + 3, y);
    
    this->_gameData.lcd.setPixel(x + 1, y + 1);
    this->_gameData.lcd.setPixel(x + 2, y + 1);
    this->_gameData.lcd.setPixel(x + 3, y + 1);
    this->_gameData.lcd.setPixel(x + 4, y + 1);
    
    this->_gameData.lcd.setPixel(x + 1, y + 2);
    this->_gameData.lcd.setPixel(x + 2, y + 2);
    this->_gameData.lcd.setPixel(x + 3, y + 2);
    this->_gameData.lcd.setPixel(x + 4, y + 2);
    this->_gameData.lcd.setPixel(x + 5, y + 2);
    
    this->_gameData.lcd.setPixel(x, y + 3);
    this->_gameData.lcd.setPixel(x + 1, y + 3);
    this->_gameData.lcd.setPixel(x + 2, y + 3);
    this->_gameData.lcd.setPixel(x + 3, y + 3);
    this->_gameData.lcd.setPixel(x + 4, y + 3);
    this->_gameData.lcd.setPixel(x + 5, y + 3);
    this->_gameData.lcd.setPixel(x + 6, y + 3);
}

void World::draw_goal(int16_t x, int16_t y) {
    this->_gameData.lcd.setPixel(x + 1, y);    
    this->_gameData.lcd.setPixel(x + 2, y);    
    this->_gameData.lcd.setPixel(x + 3, y);    
    
    this->_gameData.lcd.setPixel(x, y + 1);    
    this->_gameData.lcd.setPixel(x + 1, y + 1);    
    this->_gameData.lcd.setPixel(x + 2, y + 1);    
    this->_gameData.lcd.setPixel(x + 3, y + 1);    
    
    this->_gameData.lcd.setPixel(x + 1, y + 2);    
    this->_gameData.lcd.setPixel(x + 2, y + 2);    
    this->_gameData.lcd.setPixel(x + 3, y + 2);    
    
    this->_gameData.lcd.setPixel(x + 3, y + 3);    
    this->_gameData.lcd.setPixel(x + 3, y + 4);    
    this->_gameData.lcd.setPixel(x + 3, y + 5);    
    this->_gameData.lcd.setPixel(x + 3, y + 6);    
    this->_gameData.lcd.setPixel(x + 3, y + 7);    
    this->_gameData.lcd.setPixel(x + 3, y + 8);    
}

void World::draw() {
    if (this->_level == 1) {
        //draw background
        this->draw_background();
    }
    
    //draw world clouds
    for (size_t i = 0; i < this->_clouds.size(); i++) {
        //only draw the clouds which are on screen (within the view port)
        if ((this->_clouds[i].x + 7 > this->_viewPort.position.x) && (this->_clouds[i].x < this->_viewPort.position.x + this->_viewPort.size.x)) {
            if ((this->_clouds[i].y + 4 > this->_viewPort.position.y) && (this->_clouds[i].y < this->_viewPort.position.y + this->_viewPort.size.y)) {
                this->draw_cloud(this->_clouds[i].x - (84 * this->_gameData.screen.x), this->_clouds[i].y - (48 * this->_gameData.screen.y));    
            }
        }    
    }
    
    //draw world rects
    for (size_t i = 0; i < this->_worldRects.size(); i++) {
        //only draw the rects which are on screen (within the view port)
        if ((this->_worldRects[i].position.x + this->_worldRects[i].size.x > this->_viewPort.position.x) && (this->_worldRects[i].position.x < this->_viewPort.position.x + this->_viewPort.size.x)) {
            if ((this->_worldRects[i].position.y + this->_worldRects[i].size.y > this->_viewPort.position.y) && (this->_worldRects[i].position.y < this->_viewPort.position.y + this->_viewPort.size.y)) {
                this->_gameData.lcd.drawRect(this->_worldRects[i].position.x - (84 * this->_gameData.screen.x), this->_worldRects[i].position.y - (48 * this->_gameData.screen.y), this->_worldRects[i].size.x, this->_worldRects[i].size.y, FILL_BLACK);    
            }
        }    
    }
    
    //draw goal flag
    if ((this->_goal.x + 4 > this->_viewPort.position.x) && (this->_goal.x < this->_viewPort.position.x + this->_viewPort.size.x)) {
        if ((this->_goal.y + 9 > this->_viewPort.position.y) && (this->_goal.y < this->_viewPort.position.y + this->_viewPort.size.y)) {
            this->draw_goal(this->_goal.x - (84 * this->_gameData.screen.x), this->_goal.y - (48 * this->_gameData.screen.y));    
        }
    }   
}

//draw fore ground objects
//non-collidable objects that are in front of player
void World::draw_foreground() {
    if (this->_level == 3) {
        if (243 > this->_viewPort.position.x && 221 < this->_viewPort.position.x + this->_viewPort.size.x) {
            if (22 > this->_viewPort.position.y && 43 < this->_viewPort.position.y + this->_viewPort.size.y) {
                //tower
                this->_gameData.lcd.drawRect(221 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), 21, 21, FILL_BLACK);
                
                //tower cross
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 20 - (48 * this->_gameData.screen.y), false);
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 20 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 21 - (48 * this->_gameData.screen.y), false);    
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 21 - (48 * this->_gameData.screen.y), false);   
        
                this->_gameData.lcd.setPixel(229 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);      
                this->_gameData.lcd.setPixel(230 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);      
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);           
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);
                this->_gameData.lcd.setPixel(233 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);      
                this->_gameData.lcd.setPixel(234 - (84 * this->_gameData.screen.x), 22 - (48 * this->_gameData.screen.y), false);   
                
                this->_gameData.lcd.setPixel(229 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(230 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(233 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(234 - (84 * this->_gameData.screen.x), 23 - (48 * this->_gameData.screen.y), false);   
        
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 24 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 25 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(231 - (84 * this->_gameData.screen.x), 26 - (48 * this->_gameData.screen.y), false);           
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 24 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 25 - (48 * this->_gameData.screen.y), false);   
                this->_gameData.lcd.setPixel(232 - (84 * this->_gameData.screen.x), 26 - (48 * this->_gameData.screen.y), false);   
                
                //bridge connectors
                for (int i = 0; i < 26; i++) {
                    this->_gameData.lcd.setPixel((195 + i) - (84 * this->_gameData.screen.x), 42 - i - (48 * this->_gameData.screen.y));   
                } 
            }
        }
        
        if (336 > this->_viewPort.position.x && 252 < this->_viewPort.position.x + this->_viewPort.size.x) {
            if (16 > this->_viewPort.position.y && 46 < this->_viewPort.position.y + this->_viewPort.size.y) {       
                //house 1
                this->_gameData.lcd.drawRect(261 - (84 * this->_gameData.screen.x), 16 - (48 * this->_gameData.screen.y), 2, 32, FILL_BLACK);
                this->_gameData.lcd.drawRect(322 - (84 * this->_gameData.screen.x), 16 - (48 * this->_gameData.screen.y), 2, 32, FILL_BLACK);
                
                //roof 1
                for (int i = 0; i < 12; i++) {
                    this->_gameData.lcd.setPixel((258 + i) - (84 * this->_gameData.screen.x), 18 - i - (48 * this->_gameData.screen.y)); 
                    this->_gameData.lcd.setPixel((259 + i) - (84 * this->_gameData.screen.x), 18 - i - (48 * this->_gameData.screen.y));     
                } 
                for (int i = 0; i < 12; i++) {
                    this->_gameData.lcd.setPixel((313 + i) - (84 * this->_gameData.screen.x), 6 + i - (48 * this->_gameData.screen.y)); 
                    this->_gameData.lcd.setPixel((314 + i) - (84 * this->_gameData.screen.x), 6 + i - (48 * this->_gameData.screen.y));   
                } 
            }
        }
    }
}