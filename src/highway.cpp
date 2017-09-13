#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Car.h"
#include "Car.cpp"

int main() {
    std::vector<Car> cars;
    int rdm;
    double dt = 0.01;
    int N = 20000;

    // fill the vector with random cars
    for (int i=0; i<100; i++){
        rdm = rand() % 4;
        
        switch(rdm){
            case 0: cars.push_back(Prius());
            case 1: cars.push_back(Mazda3());
            case 2: cars.push_back(Tesla3());
            case 3: cars.push_back(Herbie());
        }
    }
    for (int i=0; i<N; i++){
        for (Car& car : cars) {
            if (car.getState().velocity <= 27.8){
                car.accelerate(true);
            }
            else{
                car.accelerate(false);
            }
    
            car.drive(dt);
        }
    }

    for (Car& car : cars) {
        std::cout << car.getModel() << " reached: " << car.getState().position << std::endl;
    }
    
    return 0;
}
