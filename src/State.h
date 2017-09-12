#ifndef STATE_H
#define STATE_H

#include <iostream>

class State{
public:
    double position;
    double velocity;
    double acceleration;
    double time;


    State(){
        position = 0;
        velocity = 0;
        acceleration = 0;
        time = 0;
    }

    void set(double pos,  double vel, double acc, double t){
        position = pos;
        velocity = vel;
        acceleration = acc;
        time = t;
    }
};

// prints out a State class information
inline std::ostream& operator<<(std::ostream& os, State& state) {  
    os << "t: " << state.time << ", x: " << state.position 
       << ", v: " << state.velocity << ", a: " << state.acceleration;
    return os;
}  

#endif
