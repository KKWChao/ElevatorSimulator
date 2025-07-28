#include <iostream>

#include <vector>
#include <string>
#include "controller/Controller.h"
#include "elevator/Elevator.h"


// ELEVATOR MANAGEMENT

void Controller::handlePathLogic(int whichElevator) {

    // Handling direction change for initial press 

    /* 
    TODO: Figure out how to set elevator path
    - since we have a set, should it be find the index of the curr floor then iterate up/down?
    - use an if statement to skip the incorrect floors?

    example set: {-2, -1, 0, 2, 4, 5, 8} and direction = UP
                          ^ start
    want to start at 0 and iterate through until last item of 8 is hit, then switch to down until -2 is reached

    additionally if additional buttons are added during the path traversal
    example set: {-2, -1, 2, 4, 5, 6, 8, 8} and direction = UP
                          ^ start
    floors are removed after leaving
                
    */

    
    // elevatorPaths.at(whichElevator);

}

void Controller::printInfo() const {
    std::cout << "Number of Elevators:  " << numElevators << '\n';

    std::cout << "Path: " << '\n';
    // for (int i : elevatorPath) {
        
    // }


}

