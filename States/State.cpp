#include "State.h"

//abstract class only needs defintions for non pure virtual functions
//any function that can be used by all derived state classes should be declared here
State::~State() {}

//get the next state transition
StateTransitions State::get_transition() {
    return this->_transition;    
}