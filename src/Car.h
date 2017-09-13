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
    State car_state;
    
public:
    bool accelerator;
    // variables
    // constructor
    Car(std::string model, double mass, double engine_force, double drag_area);

    std::string getModel();
    double getMass();
    void accelerate(bool on);
    virtual void drive(double dt);
    State getState();
};

class Prius: public Car{
public:
    //constructor
    Prius() : Car("Toyota Prius", 1450, 740, 0.58) {}
};

class Mazda3: public Car{
public:
    //constructor
    Mazda3() : Car("Mazda 3", 1600, 790, 0.61) {}
};

class Tesla3: public Car{
public:
    //constructor
    Tesla3() : Car("Tesla 3", 1800, 850, 0.60) {}
};

class Herbie: public Car{
    State herbieState;
    double mass;
public:
    //constructor
    Herbie() : Car("Herbie", 1200, 780, 0.59) {
        herbieState = State();
        mass = 1200;
    }

    //override original drive function
    void drive(double dt);
};

#endif //