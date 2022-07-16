#include "Entity.h"

Entity::Entity() {
    this->_vel = {0, 0};  
    
    this->_frame_counter = 0; 
    
    this->_collisionX = false;
    this->_collisionY = false;
    this->_jumping = false;
}

Entity::~Entity() {
    delete this->_sprite0;
    delete this->_sprite1;
    delete this->_sprite2;
}

void Entity::initVars(Direction facing, uint8_t health, uint8_t damage, IntRect rect) {
    this->_facing = facing;
    this->_health = health;
    this->_damage = damage;
    this->_rect = rect;
}

void Entity::set_animation(int* sprite0, int* sprite1, int* sprite2) {
    this->_sprite0 = sprite0;
    this->_sprite1 = sprite1;
    this->_sprite2 = sprite2;    
}

bool Entity::collisionX(std::vector<IntRect> collision_points) {
    //loop through all rects in vector
    for (size_t i = 0; i < collision_points.size(); i++) {
        //check the position of the entity after the next move
        //if collision would occur then no move will occur in movement aspect
        if ((this->_rect.position.x + this->_rect.size.x + this->_vel.x > collision_points[i].position.x) && (this->_rect.position.x + this->_vel.x < collision_points[i].position.x + collision_points[i].size.x)) {
            if ((this->_rect.position.y + this->_rect.size.y > collision_points[i].position.y) && (this->_rect.position.y < collision_points[i].position.y + collision_points[i].size.y)) {
                return true;
            }
        }
    }

    return false;
}

bool Entity::collisionY(std::vector<IntRect> collision_points) {
    for (size_t i = 0; i < collision_points.size(); i++) {
        if ((this->_rect.position.x + this->_rect.size.x > collision_points[i].position.x) && (this->_rect.position.x < collision_points[i].position.x + collision_points[i].size.x)) {
            if ((this->_rect.position.y + this->_rect.size.y + this->_vel.y > collision_points[i].position.y) && (this->_rect.position.y + this->_vel.y < collision_points[i].position.y + collision_points[i].size.y) ||
                (this->_rect.position.y + this->_rect.size.y + (this->_vel.y / 2) > collision_points[i].position.y) && (this->_rect.position.y + (this->_vel.y / 2) < collision_points[i].position.y + collision_points[i].size.y)) {
                if (this->_rect.position.y < collision_points[i].position.y) {
                    this->_jumping = false;
                }
                
                return true;
            }
        }
    }
    
    return false;
}

void Entity::move(Direction dir) {
    //only call methods from entity aspects if the aspect has been created
    //prevents errors if method called before aspect creation
    if (dir == NE || dir == E || dir == SE) this->_vel.x = 1;
    if (dir == NW || dir == W || dir == SW) this->_vel.x = -1;
    //only change the facing if direction is left or right
    if (dir != CENTRE && dir != N && dir != S) {
        this->_facing = dir;
    }
}

void Entity::jump() {
    this->_vel.y = -20;
    //set jumping flag
    this->_jumping = true; 
}

void Entity::collision(std::vector<IntRect> collision_points) {
    //set collision flags in movement aspect
    this->_collisionX = this->collisionX(collision_points);
    this->_collisionY = this->collisionY(collision_points);
}

void Entity::attacked(IntRect weapon, uint8_t damage) {
    if (this->collisionX({weapon})) {
        //if weapon collides with entity then take damage
        this->_health -= damage;
        
        //health should not go below 0
        if (this->_health <= 0) {
            this->_health = 0;    
        }
    }    
}

IntRect Entity::get_rect() {
    return this->_rect;    
}

IntRect Entity::get_weapon() {
    //weapon size is constant
    IntRect weapon = {{0, 0}, {2, 2}};
    
    //weapon position should be determined for entity facing
    if (this->_facing == NE || this->_facing == E || this->_facing == SE) {
        weapon.position.x = this->_rect.position.x + this->_rect.size.x;
        weapon.position.y = this->_rect.position.y + 3;
    }
    if (this->_facing == NW || this->_facing == W || this->_facing == SW) {
        weapon.position.x = this->_rect.position.x - 2;
        weapon.position.y = this->_rect.position.y + 3;
    }
    return weapon;    
}

uint8_t Entity::get_health() {
    return this->_health;    
}

uint8_t Entity::get_maxHealth() {
    return this->_maxHealth;    
}

uint8_t Entity::get_damage() {
    return this->_damage;
}

bool Entity::is_jumping() {
    return this->_jumping;    
}

void Entity::update() {
    //if collision would occur movement does not occur
    if (!this->_collisionX) {
        this->_rect.position.x += this->_vel.x;
    }
    //reset velocity in x direction to 0
    this->_vel.x = 0;    

    if (!this->_collisionY) {
        this->_rect.position.y += this->_vel.y;   
    }
    //reset velocity in y direction to 1 to implement gravity
    this->_vel.y = 1;
}

void Entity::draw(N5110& lcd, IntVector2D screen) {
    //frame counter loops through 0 to 5
    //modulo 5 to produce this loop
    this->_frame_counter %= 5;
    
    //print the desired sprite to the lcd
    if (this->_frame_counter == 0) lcd.drawSprite(this->_rect.position.x - (84 * screen.x), this->_rect.position.y - (48 * screen.y), this->_rect.size.y, this->_rect.size.x, this->_sprite0);
    if (this->_frame_counter == 1 || this->_frame_counter == 2) lcd.drawSprite(this->_rect.position.x - (84 * screen.x), this->_rect.position.y - (48 * screen.y), this->_rect.size.y, this->_rect.size.x, this->_sprite1);
    if (this->_frame_counter == 3 || this->_frame_counter == 4) lcd.drawSprite(this->_rect.position.x - (84 * screen.x), this->_rect.position.y - (48 * screen.y), this->_rect.size.y, this->_rect.size.x, this->_sprite2);

    //increment counter once per frame
    this->_frame_counter++;
}

//reset changeable variables to initial values
void Entity::reset(Direction facing, uint8_t health, IntVector2D position) {
    this->_facing = facing;
    this->_health = health;
    this->_rect.position = position;    
}