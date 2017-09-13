#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "State.h"
#include "physics.h"

class Car{
private:
    // member variables
    std::string model;
    double mass;
    double engine_force;
    double drag_area;
    int N;
    bool accelerator;
    State car_state;
    
public:
    // variables
    // constructor
    Car(std::string model, double mass, double engine_force, double drag_area);

    std::string getModel();
    double getMass();
    void accelerate(bool on);
    void drive(double dt);
    State getState();
};

#endif //