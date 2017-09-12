#include <iostream>
#include "State.h"

int main(){
    State my_state = State();

    // my_state.set(1,2,3,4);
    
    // std::cout << my_state.position << std::endl;
    // std::cout << my_state.velocity << std::endl;
    // std::cout << my_state.acceleration << std::endl;
    // std::cout << my_state.time;

    std::cout << my_state << std::endl;
    return 0;
}