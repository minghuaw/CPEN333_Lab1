#include <string>
#include <iostream>
#include "Car.h"
#include "physics.h"


Car::Car(std::string model, double mass, double engine_force, double drag_area) {
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

void Car::accelerate(bool on){
    accelerator = on;
}

void Car::drive(double dt){
    double rho = 1.225 // rho for air at room temp
    double drag_force = 0..5*rho*drag_area*v*v;
    double f_net = engine_force - drag_force;
    t_step = 0.01;
    N = (int)(dt / t_step);
    if (accelerator == true){
        for (int i=0; i<N; i++){
            car_state.acceleration = physics::compute_acceleration(f_net, mass);
            car_state.velocity = physics::compute_velocity(car_state.velocity, car_state.acceleration, t_step);
            car_state.position = physics::compute_position(car_state.position, car_state.velocity, t_step);
            car_state.time += t_step;

            std::cout << car_state << std::endl;
        }
    }
}
