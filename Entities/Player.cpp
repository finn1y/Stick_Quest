#include "Player.h"

Player::Player(Direction facing, uint8_t health, uint8_t damage, IntRect rect) {
    this->initVars(facing, health, damage, rect); 
}

Player::~Player() {}

void Player::set_animation_dir(SpriteManager& sprite_manager, Animations animation) {
    //switch statement used to determine animation
    switch (animation) {
        case Idle:
            //facing variable determines the direction of the animation
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_playerIdleLeft(), sprite_manager.get_playerIdleLeft(), sprite_manager.get_playerIdleLeft());
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_playerIdleRight(), sprite_manager.get_playerIdleRight(), sprite_manager.get_playerIdleRight());
            break;
        
        case Run:
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_playerIdleLeft(), sprite_manager.get_playerRunLeft0(), sprite_manager.get_playerRunLeft1());    
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_playerIdleRight(), sprite_manager.get_playerRunRight0(), sprite_manager.get_playerRunRight1()); 
            break;
            
        case Jump:
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_playerJumpLeft(), sprite_manager.get_playerJumpLeft(), sprite_manager.get_playerJumpLeft());  
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_playerJumpRight(), sprite_manager.get_playerJumpRight(), sprite_manager.get_playerJumpRight());          
            break;
        
        case Attack:
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_playerAttackLeft(), sprite_manager.get_playerAttackLeft(), sprite_manager.get_playerAttackLeft());  
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_playerAttackRight(), sprite_manager.get_playerAttackRight(), sprite_manager.get_playerAttackRight()); 
            break;
        
    }    
}