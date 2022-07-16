#ifndef PLAYER_H
#define PLAYER_H

#include "utility.h"
#include "Entity.h"

class Player: public Entity {

    public:
        Player(Direction facing, uint8_t health, uint8_t damage, IntRect rect);
        ~Player();
        
        //animations must be set in the player class
        //single function with swicth statement to set animation
        void set_animation_dir(SpriteManager& sprite_manager, Animations animation);

};

typedef std::unique_ptr<Player> player_ptr;

#endif /* PLAYER_H */