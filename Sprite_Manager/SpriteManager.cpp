#include "SpriteManager.h"

SpriteManager::SpriteManager() {}

SpriteManager::~SpriteManager() {}
        
int* SpriteManager::get_playerIdleRight() {
    return (int*)this->_playerIdleRight;
}

int* SpriteManager::get_playerIdleLeft() {            
    return (int*)this->_playerIdleLeft;
}
            
int* SpriteManager::get_playerRunRight0() {        
    return (int*)this->_playerRunRight0;
}
        
int* SpriteManager::get_playerRunLeft0() {
    return (int*)this->_playerRunLeft0;
}
        
int* SpriteManager::get_playerRunRight1() {
    return (int*)this->_playerRunRight1;
}   
        
int* SpriteManager::get_playerRunLeft1() {
    return (int*)this->_playerRunLeft1;
}
        
int* SpriteManager::get_playerJumpRight() {
    return (int*)this->_playerJumpRight;
}        
        
int* SpriteManager::get_playerJumpLeft() {
    return (int*)this->_playerJumpLeft;
}
            
int* SpriteManager::get_playerAttackRight() {
    return (int*)this->_playerAttackRight;
}   
        
int* SpriteManager::get_playerAttackLeft() {
    return (int*)this->_playerAttackLeft;     
}

int* SpriteManager::get_enemyIdleRight() {
    return (int*)this->_enemyIdleRight;
}
            
int* SpriteManager::get_enemyIdleLeft() {
    return (int*)this->_enemyIdleLeft;
}   
            
int* SpriteManager::get_enemyRunRight0() {
    return (int*)this->_enemyRunRight0;
}
        
int* SpriteManager::get_enemyRunLeft0() {
    return (int*)this->_enemyRunLeft0;
}
        
int* SpriteManager::get_enemyRunRight1() {
    return (int*)this->_enemyRunRight1;
}
        
int* SpriteManager::get_enemyRunLeft1() {
    return (int*)this->_enemyRunLeft1;
}
            
int* SpriteManager::get_enemyAttackRight() {
    return (int*)this->_enemyAttackRight;
}
        
int* SpriteManager::get_enemyAttackLeft() {
    return (int*)this->_enemyAttackLeft;
}