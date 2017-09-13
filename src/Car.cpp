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

State Car::getState(){
    return car_state;
}

void Car::accelerate(bool on){
    accelerator = on;
}

void Car::drive(double dt){
    double rho = 1.225; // rho for air at room temp
    double drag_force = 0.5*rho*drag_area*car_state.velocity*car_state.velocity;
    double f_net = engine_force - drag_force;
    if (accelerator == true){
        car_state.acceleration = physics::compute_acceleration(f_net, mass);
        car_state.velocity = physics::compute_velocity(car_state.velocity, car_state.acceleration, dt);
        car_state.position = physics::compute_position(car_state.position, car_state.velocity, dt);
        car_state.time += dt;

        // std::cout << car_state << std::endl;        
    }
}

void Herbie::drive(double dt){
    double f_net = 10000; // Herbie ignores air resistance
    if (accelerator == true){
        herbieState.acceleration = physics::compute_acceleration(f_net, mass);
        herbieState.velocity = physics::compute_velocity(herbieState.velocity, herbieState.acceleration, dt);
        herbieState.position = physics::compute_position(herbieState.position, herbieState.velocity, dt);
        herbieState.time += dt;
    }
}
