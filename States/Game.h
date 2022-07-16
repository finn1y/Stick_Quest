#ifndef GAME_H
#define GAME_H

#include "utility.h"
#include "Player.h"
#include "Enemy.h"
#include "World.h"

class Game: public State {

    public:
        Game(Data& gameData);
        ~Game();
        
        void update();
        void draw();
        
    private:
        Data& _gameData;
        
        player_ptr _player;
        world_ptr _world;
        
        //vector of enemies for easy spawn and deletion of multiple enemies
        std::vector<enemy_ptr> _enemies;
        
        uint8_t _playerLives;
        uint8_t _currentLevel;
        bool _death, _gameOver, _gameComplete;
        bool _reset;
        
        //animation variables to detemine whether animation should be set to new animation
        Animations _previousAnimation;
        Animations _currentAnimation;
        
        void reset();
};

#endif /* GAME_H */