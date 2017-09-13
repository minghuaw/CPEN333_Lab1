#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Car.h"
#include "Car.cpp"

int main() {
    Car* cars[100];
    int rdm;
    double dt = 0.01;
    int N = 20000;

    // fill the vector with random cars
    for (int i=0; i<100; i++){
        rdm = rand() % 4;
        
        if (rdm == 0){
            cars[i] = new Prius();
        }
        else if (rdm == 1){
            cars[i] = new Mazda3();
        }
        else if (rdm == 2){
            cars[i] = new Tesla3();
        }
        else{
            cars[i] = new Herbie();
        }

    }
    for (int i=0; i<N; i++){
        for (int j=0; j<100; j++) {
            State* state_pt = cars[j]->getState();
            if (state_pt->velocity <= 27.8){
                cars[j]->accelerate(true);
            }
            else{
                cars[j]->accelerate(false);
            }
    
            cars[j]->drive(dt);
        }
    }

    for (int i=0; i<100; i++) {
        State* state_pt = cars[i]->getState();
        std::cout << cars[i]->getModel() << " reached: " << state_pt->position << std::endl;
    }
    
    return 0;
}
