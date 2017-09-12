#include <iostream>
#include "Car.h"

Car::Car(std::string model, double mass, double engine_force, double drag_area) car_state{
    model = model;
    mass = mass;
    engine_force = engine_force;
    drag_area = drag_area;
}

double Car::getMass(){
    return mass;
}

double Car::getState(){
    return car_state;
}

