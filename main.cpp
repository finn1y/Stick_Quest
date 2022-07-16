#include "Game.h"
#include "Intro.h"
#include "MainMenu.h"
#include "Options.h"
#include "Pause.h"

//LCD   VCC,SCE,RST,D/C,MOSI,SCLK,LED
N5110 lcd(p14,p8,p9,p10,p11,p13,p21);

//input manager
InputManager input_manager;

//sprite manager
SpriteManager sprite_manager;

//init previous state variable
States previous_state = IntroState;

//game data struct
Data GameData = {
    lcd, 
    input_manager,
    sprite_manager,
    2,
    previous_state,
    {0, 0}
};

//finite state machine 
StateMachine g_fsm[] = {
//                     state            fps     back        null       forward1       forward2
    {std::make_unique<Intro>(GameData), 0.4f, {IntroState, IntroState, MainMenuState, MainMenuState}},
    {std::make_unique<MainMenu>(GameData), 5.0f, {MainMenuState, MainMenuState, OptionsState, GameState}},
    {std::make_unique<Options>(GameData), 5.0f, {OptionsState, OptionsState, MainMenuState, PauseState}},
    {std::make_unique<Game>(GameData), 9.0f, {GameState, GameState, PauseState, GameState}},
    {std::make_unique<Pause>(GameData), 5.0f, {GameState, PauseState, OptionsState, MainMenuState}} 
};

int main() {
    //init lcd
    lcd.init();
    lcd.backLightOn();
    lcd.setContrast(0.5);
    
    //init input manager
    input_manager.init();
    
    //init current state variable
    States current_state = IntroState;
    //init state transition variable
    StateTransitions state_transition = g_fsm[current_state].state->get_transition();

    //game loop
    while (1) {
        //call the update function for the current state
        //updates the game engine inputs, outputs and logic
        g_fsm[current_state].state->update();
        //call the draw function for the current state
        //draws the current frame to the lcd
        g_fsm[current_state].state->draw();
        //put microcontroller to sleep until the next frame update
        //time determined by the fps of the current state
        thread_sleep_for((uint32_t)(1000/g_fsm[current_state].fps));
        
        //get the state transition
        state_transition = g_fsm[current_state].state->get_transition();
        if (state_transition != Null) {
            //update previous state if next state is a different state
            GameData.previous_state = current_state;    
        }
        //update current state
        current_state = g_fsm[current_state].transition[state_transition];
    }

    return 0;    
}