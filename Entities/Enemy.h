#ifndef ENEMY_H
#define ENEMY_H

#include "utility.h"
#include "Entity.h"

class Enemy: public Entity {

    public:
        Enemy(Direction facing, uint8_t health, uint8_t damage, IntRect rect);
        ~Enemy();
        
        bool is_attacking();
        
        //animations must be set in the enemy class
        //single function with swicth statement to set animation
        void set_animation_dir(SpriteManager& sprite_manager, Animations animation);     
        void ai(SpriteManager& sprite_manager, IntRect playerRect, std::vector<IntRect> worldRects, uint8_t difficulty);
        
    private:
        bool _attack;
        //animation variables to detemine whether animation should be set to new animation
        Animations _previousAnimation;
        Animations _currentAnimation;
        //timer for delay between enemy attacks
        Timer _timer;
                    
};

typedef std::unique_ptr<Enemy> enemy_ptr;

#endif /* ENEMY_H */