#include "Enemy.h"

Enemy::Enemy(Direction facing, uint8_t health, uint8_t damage, IntRect rect) {
    this->initVars(facing, health, damage, rect);
    
    this->_attack = false; 
    this->_currentAnimation = Idle;
    this->_previousAnimation = Run;        
}

Enemy::~Enemy() {}

bool Enemy::is_attacking() {
    return this->_attack;   
}

void Enemy::ai(SpriteManager& sprite_manager, IntRect playerRect, std::vector<IntRect> worldRects, uint8_t difficulty) {
    //find the distance between the player and the enemy
    int16_t player_distance = this->_rect.position.x - playerRect.position.x;

    //attack timer reset if a certain time has passed since last attack 
    //time is based on difficulty
    if ((difficulty == 1 && this->_timer.read() > 2.1f) || (difficulty == 2 && this->_timer.read() > 1.5f) || (difficulty == 3 && this->_timer.read() > 1.0f)) {
        this->_timer.stop();
        this->_timer.reset();    
    }

    //enemy action if player is at similar height as player
    if ((playerRect.position.y > this->_rect.position.y - 5) && (playerRect.position.y < this->_rect.position.y + 5)) {    
        //if player is 30 pixels to the left of the enemy
        if (player_distance > 0 && player_distance < 30) {
            //if player is within attack distance and timer is 0 enemy attack
            if (player_distance < 12 && this->_timer.read() == 0.0f) {
                //set attack flag
                this->_attack = true;
                //set animation to attack
                this->_currentAnimation = Attack;  
                //start timer to space out enemy attacks
                this->_timer.start();
            }
            else {
                //if player not within attack distance then reset attack flag
                this->_attack = false;    
                
                //move toward player
                this->move(W);
                //set animation to run
                this->_currentAnimation = Run;
            }            
        }
        //if player is 30 pixels to the right of the enemy do as above but for opposite facing
        if (player_distance > -30 && player_distance < 0) {
            if (player_distance > -12 && this->_timer.read() == 0.0f) {
                this->_attack = true;    
                this->_currentAnimation = Attack;
                
                this->_timer.start();
            }
            else {
                this->_attack = false;    
                
                this->move(E);
                this->_currentAnimation = Run;
            }
        }
    }
    //else do nothing and set animation to idle
    else {
        this->_currentAnimation = Idle;
    }
    
    //set enemy animation
    if (this->_currentAnimation != this->_previousAnimation) {
        this->set_animation_dir(sprite_manager, this->_currentAnimation);    
        this->_previousAnimation = this->_currentAnimation;
    }
}

void Enemy::set_animation_dir(SpriteManager& sprite_manager, Animations animation) {
    //switch statement used to determine animation
    switch (animation) {
        case Idle:
            //facing variable determines the direction of the animation
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_enemyIdleLeft(), sprite_manager.get_enemyIdleLeft(), sprite_manager.get_enemyIdleLeft());
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_enemyIdleRight(), sprite_manager.get_enemyIdleRight(), sprite_manager.get_enemyIdleRight());
            break;
        
        case Run:
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_enemyIdleLeft(), sprite_manager.get_enemyRunLeft0(), sprite_manager.get_enemyRunLeft1());    
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_enemyIdleRight(), sprite_manager.get_enemyRunRight0(), sprite_manager.get_enemyRunRight1()); 
            break;
            
        case Jump:
            break;
        
        case Attack:
            if (this->_facing == NW || this->_facing == W || this->_facing == SW) this->set_animation(sprite_manager.get_enemyAttackLeft(), sprite_manager.get_enemyAttackLeft(), sprite_manager.get_enemyAttackLeft());  
            if (this->_facing == NE || this->_facing == E || this->_facing == SE) this->set_animation(sprite_manager.get_enemyAttackRight(), sprite_manager.get_enemyAttackRight(), sprite_manager.get_enemyAttackRight()); 
            break;
        
    }    
}