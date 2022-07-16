#ifndef STATE_H
#define STATE_H

#include "utility.h"

//states tied to position in finite state machine, IntroState is State 0 etc.
enum States {
    IntroState,
    MainMenuState,
    OptionsState,
    GameState,
    PauseState
};

//possible state transitions
enum StateTransitions {
    Back,
    Null,
    Forward1,
    Forward2    
};

//2D vector of ints
struct IntVector2D {
    int16_t x;
    int16_t y;   
};

//rectangle struct
struct IntRect {
    IntVector2D position;
    IntVector2D size;    
};

//data struct to hold changeable game data and lcd and input manager object references
//passed to each state for access to each object from within the state
//allows game data to be changed in one state and used in a different state
struct Data {
    N5110& lcd;
    InputManager& input_manager;
    SpriteManager& sprite_manager;
    uint8_t difficulty;
    States previous_state;
    IntVector2D screen;
};

//state abstract base class for all other states to be derived from 
class State {

    public:
        //unique pointer requires a virutal destructor to overload
        virtual ~State();
        //pure virtual functions can be called from the main loop for any derived state
        virtual void update() = 0;
        virtual void draw() = 0;
        
        //get the next state transition 
        StateTransitions get_transition();
        
    protected:    
        //members common to all states
        //allows the variables to be declared internally within any state class 
        StateTransitions _transition;
        
};

//unique pointer to state abstract base class
typedef std::unique_ptr<State> state_ptr;

//state machine declaration
struct StateMachine {
    state_ptr state;
    float fps;
    States transition[4];    
};

#endif /* STATE_H */