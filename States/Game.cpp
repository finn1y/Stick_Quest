#include "Game.h"
#include "Pause.h"

Game::Game(Data& gameData): _gameData(gameData) {
    this->_transition = Null;
    
    this->_world = std::make_unique<World>(this->_gameData);
    
    this->_player = player_ptr(new Player(E, 100, (uint8_t)(20 / this->_gameData.difficulty), {this->_world->get_playerPosition(), {11, 12}}));

    for (size_t i = 0; i < this->_world->get_enemyPositions().size(); i++) {
        this->_enemies.push_back(std::move(enemy_ptr(new Enemy(W, 100, (uint8_t)(5 * this->_gameData.difficulty), {this->_world->get_enemyPositions()[i], {11, 12}}))));
    }
    
    this->_playerLives = 4;
    this->_currentLevel = 1;
    this->_death = false;
    this->_gameOver = false;
    this->_gameComplete = false;
    this->_reset = false;
    
    this->_currentAnimation = Idle;
    this->_previousAnimation = Jump;
    
}

Game::~Game() {
    this->_player.reset();
    this->_world.reset();
    
    this->_enemies.clear();   
}

void Game::update() {
    //reset state transition to null transition 
    this->_transition = Null;
    
    //if previous state was main menu state restart the game 
    if (this->_gameData.previous_state == MainMenuState && this->_reset) {
        this->_currentLevel = 1;
        this->_world->update_level(this->_currentLevel);
        this->_playerLives = 4;
        this->reset();
    }
    
    //calculate the int value of the LEDs based on the number of lives
    uint8_t leds = 2;
    for (uint8_t i = 0; i < (this->_playerLives - 1); i++) {
        leds *= 2;
    }
    //set the LEDs to show the number of lives
    this->_gameData.input_manager.set_leds(leds - 1);
    
    //set the colour of the RGB led based on the players health
    if (this->_player->get_health() < 30) {
        //red if less than 30 (low health)
        this->_gameData.input_manager.set_rgb(0b110);   
    }
    else {
        //green otherwise
        this->_gameData.input_manager.set_rgb(0b101);
    }
    
    //get direction of jostick
    Direction dir = this->_gameData.input_manager.get_direction();
    //move player       
    this->_player->move(dir);
    //set current animation based on movement of joystick
    if (dir == CENTRE || dir == S || dir == N) {
        //if no movement occured set idle
        this->_currentAnimation = Idle;    
    }
    if (dir == NE || dir == E || dir == SE || dir == NW || dir == W || dir == SW) {
        //if movement occured set run 
        this->_currentAnimation = Run;    
    }
    
    //check for player jump
    if (this->_gameData.input_manager.check_flag(ButtonJoyFlag) && (!this->_player->is_jumping())) {   
        //if jump button pressed and not jumping then player jump     
        this->_player->jump();
        //set animation to jump
        this->_currentAnimation = Jump;
    }
    
    //check for player attack
    if (this->_gameData.input_manager.check_flag(ButtonAFlag)) {
        for (size_t i = 0; i < this->_enemies.size(); i++) {
            //all enemies looped through to check if attack damages each
            this->_enemies[i]->attacked({this->_player->get_weapon()} , this->_player->get_damage());
            //if enemy has 0 health then set dead flag
            if (!this->_enemies[i]->get_health()) {
                this->_enemies.erase(this->_enemies.begin() + i); 
            }
        }
        //set animation to attack
        this->_currentAnimation = Attack;
    }
    
    //set player animation
    if (this->_currentAnimation != this->_previousAnimation) {
        this->_player->set_animation_dir(this->_gameData.sprite_manager, this->_currentAnimation);    
        this->_previousAnimation = this->_currentAnimation;
    }

    //all enemy AI is called
    for (size_t i = 0; i < this->_enemies.size(); i++) {
        //AI is disabled for the frist two enemies in the first level
        if (this->_currentLevel == 1 && ((this->_enemies.size() == 3 && (i == 1 || i == 2)) || (this->_enemies.size() == 2 && i == 1))) {
            //without a call to AI animation is not set 
            //set animation to idle
            this->_enemies[i]->set_animation_dir(this->_gameData.sprite_manager, Idle);   
        }
        else {
            this->_enemies[i]->ai(this->_gameData.sprite_manager, this->_player->get_rect(), this->_world->get_worldRects(), this->_gameData.difficulty);
            
            if (this->_enemies[i]->is_attacking()) {
                this->_player->attacked({this->_enemies[i]->get_weapon()} , this->_enemies[i]->get_damage());   
            }
        }
    }

    //entity movement collision
    //make a temporary vector of world rects
    std::vector<IntRect> world_rects = this->_world->get_worldRects(); 
    
    world_rects.push_back(this->_player->get_rect());
    for (size_t i = 0; i < this->_enemies.size(); i++) {
        this->_enemies[i]->collision(world_rects);
    }
    
    world_rects.pop_back();
    for (size_t i = 0; i < this->_enemies.size(); i++) {
        world_rects.push_back(this->_enemies[i]->get_rect());
    }
    this->_player->collision(world_rects);
    //free up memeory by clearing vector
    world_rects.clear();
    
    //move view port in x direction if player is near edge of screen
    if (this->_player->get_rect().position.x < this->_world->get_viewPort().position.x + 5) {
        this->_world->move_viewPort({-84, 0});    
    }    
    if (this->_player->get_rect().position.x > this->_world->get_viewPort().position.x + this->_world->get_viewPort().size.x - 5) {
        this->_world->move_viewPort({84, 0});    
    }
    //move view port in y direction if player crosses roof or floor border
    if (this->_player->get_rect().position.y < this->_world->get_viewPort().position.y - 5) {
        this->_world->move_viewPort({0, -48}); 
    }
    //only move the view port down if not moving below floor
    if (this->_world->get_viewPort().position.y < 0 && this->_player->get_rect().position.y > this->_world->get_viewPort().position.y + this->_world->get_viewPort().size.y - 5) {
        this->_world->move_viewPort({0, 48}); 
    }
    
    //update world
    this->_world->update();
    
    //update entities
    for (size_t i = 0; i < this->_enemies.size(); i++) {
        this->_enemies[i]->update();
    }
    this->_player->update();
    
    //check if player dead
    if (this->_player->get_rect().position.y > 48 || !this->_player->get_health()) {
        //set the death flag
        this->_death = true;
        //reduce number of lives by 1
        this->_playerLives--;  
        //if player has 0 lives reset to level 1 
        if (this->_playerLives == 0) {
            this->_currentLevel = 1;
            this->_world->update_level(this->_currentLevel);
            this->_playerLives = 4;
            
            //reset the death flag and set game over flag
            this->_death = false;
            this->_gameOver = true;
        }
        //reset variables
        this->reset(); 
    }
    
    //check if player has reached goal 
    if (this->_world->get_goal().x > this->_player->get_rect().position.x && this->_world->get_goal().x < this->_player->get_rect().position.x + this->_player->get_rect().size.x ) {
        if (this->_world->get_goal().y > this->_player->get_rect().position.y && this->_world->get_goal().y < this->_player->get_rect().position.y + this->_player->get_rect().size.y ) {    
            if (this->_currentLevel == 3) {
                //if final goal reached then game completed
                this->_gameComplete = true;
                this->_currentLevel = 1;
                this->_world->update_level(this->_currentLevel);
            }
            else {
                //if goal reached increment and update the current level
                this->_currentLevel++;
                this->_world->update_level(this->_currentLevel);
            }
            //reset variables to updated level initial variables
            this->reset();
        }
    }
    
    if (this->_gameData.input_manager.check_flag(ButtonCFlag)) {        
        //set the reset flag
        //if exit to main menu then return to game the game will restart
        this->_reset = true;
        //go to Pause state
        this->_transition = Forward1;        
    } 
}

void Game::draw() {
    if (this->_death) {
        //only the area for the death message is cleared
        this->_gameData.lcd.drawRect(14, 13, 57, 13, FILL_WHITE);
        //draw the death message
        this->_gameData.lcd.drawRect(14, 13, 57, 13, FILL_TRANSPARENT);
        this->_gameData.lcd.printString("YOU DIED!", 17, 2);
        
        this->_gameData.lcd.refresh(); 
        //sleep to display message for short time
        thread_sleep_for(3000);
        //reset death flag
        this->_death = false;    
    }
    if (this->_gameOver) {
        //only the area for the game over message is cleared
        this->_gameData.lcd.drawRect(13, 13, 63, 13, FILL_WHITE);
        //draw the game over message
        this->_gameData.lcd.drawRect(13, 13, 63, 13, FILL_TRANSPARENT);
        this->_gameData.lcd.printString("GAME OVER!", 16, 2);
        
        this->_gameData.lcd.refresh(); 
        //sleep to display message for short time
        thread_sleep_for(3000);
        //reset game over flag
        this->_gameOver = false;
    }
    if (this->_gameComplete) {
        //only the area for the game complete message is cleared
        this->_gameData.lcd.drawRect(14, 13, 54, 13, FILL_WHITE);
        //draw the game complete message
        this->_gameData.lcd.drawRect(14, 13, 54, 13, FILL_TRANSPARENT);
        this->_gameData.lcd.printString("YOU WIN!", 17, 2);
        
        this->_gameData.lcd.refresh(); 
        //sleep to display message for short time
        thread_sleep_for(3000);
        //reset game complete flag
        this->_gameComplete = false;
    }
    
    this->_gameData.lcd.clear();
    
    //draw the world
    this->_world->draw();
    //draw the enemies
    for (size_t i = 0; i < this->_enemies.size(); i++) {    
        //only draw the enemies that are on screen (within the view port)
        if ((this->_enemies[i]->get_rect().position.x + this->_enemies[i]->get_rect().size.x > this->_world->get_viewPort().position.x) && (this->_enemies[i]->get_rect().position.x < this->_world->get_viewPort().position.x + this->_world->get_viewPort().size.x)) { 
            if ((this->_enemies[i]->get_rect().position.y + this->_enemies[i]->get_rect().size.y > this->_world->get_viewPort().position.y) && (this->_enemies[i]->get_rect().position.y < this->_world->get_viewPort().position.y + this->_world->get_viewPort().size.y)) { 
                this->_enemies[i]->draw(this->_gameData.lcd, this->_gameData.screen);
            }
        }
    }
    //draw the player
    this->_player->draw(this->_gameData.lcd, this->_gameData.screen);
    //draw the health points (hp) box
    this->_gameData.lcd.printString("HP", 1, 0);
    this->_gameData.lcd.drawRect(14, 1, 30, 5, FILL_TRANSPARENT);
    this->_gameData.lcd.drawRect(14, 1, (30 - (30 * ((this->_player->get_maxHealth() - this->_player->get_health())) / this->_player->get_maxHealth())), 5, FILL_BLACK);
    
    //draw the foreground
    this->_world->draw_foreground();
    
    this->_gameData.lcd.refresh();    
}

//reset all variables
void Game::reset() {
    this->_world->reset_level();
    
    uint8_t health = this->_player->get_health();
    //health is reset to 100 if dead, game over or game complete
    if (this->_death || this->_gameOver || this->_gameComplete) {
        health = 100;    
    }
    
    this->_player->reset(E, health, this->_world->get_playerPosition());
        
    for (size_t i = 0; i < (this->_world->get_enemyPositions().size() - this->_enemies.size()); i++) {
        this->_enemies.push_back(std::move(enemy_ptr(new Enemy(W, 100, (uint8_t)(5 * this->_gameData.difficulty), {this->_world->get_enemyPositions()[i], {11, 12}}))));
    }
    
    for (size_t i = 0; i < this->_enemies.size(); i++) {
        this->_enemies[i]->reset(W, 100, this->_world->get_enemyPositions()[i]);
    }
    
    this->_reset = false;    
    
    this->_currentAnimation = Idle;
    this->_previousAnimation = Jump;
}
