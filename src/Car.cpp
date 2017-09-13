#include <string>
#include <iostream>
#include "Car.h"
#include "physics.h"

Car::Car(std::string model, double mass, double engine_force, double drag_area) {
    this->model = model;
    this->mass = mass;
    this->engine_force = engine_force;
    this->drag_area = drag_area;
}

std::string Car::getModel(){
    return model;
}

double Car::getMass(){
    return mass;
}

State* Car::getState(){
    return &car_state;
}

void Car::accelerate(bool on){
    accelerator = on;
}

void Car::drive(double dt){
    double rho = 1.225; // rho for air at room temp
    double drag_force = 0.5*rho*drag_area*car_state.velocity*car_state.velocity;
    double f_net = engine_force - drag_force;
    State* state_pt = getState();
    if (accelerator == true){
        state_pt->acceleration = physics::compute_acceleration(f_net, mass);
        state_pt->velocity = physics::compute_velocity(state_pt->velocity, state_pt->acceleration, dt);
        state_pt->position = physics::compute_position(state_pt->position, state_pt->velocity, dt);
        state_pt->time += dt;

        // std::cout << car_state << std::endl;        
    }
}

void Herbie::drive(double dt){
    double f_net = 1000; // Herbie ignores air resistance
    State* state_pt = getState();
    if (accelerator == true){
        state_pt->acceleration = physics::compute_acceleration(f_net, mass);
        state_pt->velocity = physics::compute_velocity(state_pt->velocity, state_pt->acceleration, dt);
        state_pt->position = physics::compute_position(state_pt->position, state_pt->velocity, dt);
        state_pt->time += dt;
    }
}
