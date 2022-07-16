#include "Intro.h"
#include "MainMenu.h"

Intro::Intro(Data& gameData): _gameData(gameData) {
    this->_transition = Forward1;
}

Intro::~Intro() {}

void Intro::update() {
    this->_gameData.input_manager.set_leds(0b1111);    
}

void Intro::draw() {
    this->_gameData.lcd.clear();
    
    this->_gameData.lcd.drawSprite((WIDTH / 2) - 6, (HEIGHT / 2) - 15, 12, 12, (int*)this->_splash);
    this->_gameData.lcd.drawRect((WIDTH / 2) - 7, (HEIGHT / 2) - 16, 14, 14, FILL_TRANSPARENT);
    this->_gameData.lcd.printString("Vitruvian", (WIDTH / 2) - 27, 3);
    this->_gameData.lcd.printString("Games", (WIDTH / 2) - 15, 4);
    
    this->_gameData.lcd.refresh();
}