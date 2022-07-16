#ifndef ENTITY_H
#define ENTITY_H

#include "utility.h"

//entity class base class for all entites in the game, e.g. the player, enemies, etc. 
//defines all common methods and memebers for entites

class Entity {

    public:
        Entity();
        virtual ~Entity();
        
        //init common entity variables
        void initVars(Direction facing, uint8_t health, uint8_t damage, IntRect rect);
        void set_hitbox();
        
        //methods for movement
        void move(Direction dir);
        void jump();
        
        //methods for collision
        void collision(std::vector<IntRect> collision_points);
        
        void attacked(IntRect weapon, uint8_t damage);
        
        IntRect get_rect();
        IntRect get_weapon();
        uint8_t get_health();
        uint8_t get_maxHealth();
        uint8_t get_damage();
        bool is_jumping();
        
        void update();
        void draw(N5110& lcd, IntVector2D screen);
        
        void reset(Direction facing, uint8_t health, IntVector2D position);
        
    protected:
        //protected is accessible by derived public class
        //but not accessible by all classes/functions
        Direction _facing;
        IntRect _rect;
        
        //methods for animation
        void set_animation(int* sprite0, int* sprite1, int* sprite2);
        
    private:    
        //variables common to all entities
        const uint8_t _maxHealth = 100;
        uint8_t _health;
        uint8_t _damage;
        IntVector2D _vel;
        
        //animation variables
        //animation loops through several sprites to produce the animation
        int* _sprite0;
        int* _sprite1;
        int* _sprite2;
        //frame counter to determine which sprite to draw
        uint8_t _frame_counter;
        
        //movement variables
        bool _collisionX, _collisionY;
        bool _jumping;
        
        //hitbox variables
        bool collisionX(std::vector<IntRect> collision_points);
        bool collisionY(std::vector<IntRect> collision_points);

};

#endif /* ENTITY_H */