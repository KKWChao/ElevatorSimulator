#include <iostream>

#include <vector>
#include <string>
#include "controller/Controller.h"


Controller::Controller(int lowestFloor, int highestFloor) {
    /*
        Initializing the buttons based on the lowest and highest
        number input
    */
    this->lowestFloor = lowestFloor;
    this->highestFloor = highestFloor;
    this->floorOffset = -lowestFloor;
}


void Controller::setCurrentFloor(int currentFloor) {
    int actualFloor = currentFloor + floorOffset;

    if (currentFloor >= lowestFloor && currentFloor <= highestFloor) {
        
        this->currentFloor = currentFloor;

    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "The current floor is: " << floorButtons[actualFloor].getFloorNumber() << '\n';
}


void Controller::handleButtonPress(int floor) {
    if (floor >= lowestFloor && floor <= highestFloor) {

        elevatorPath.insert(floor);

    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "Added floor: " << floor << '\n';
}

void Controller::handlePathLogic() {

    // Handling direction change for initial press 

    /* TODO: Figure out how to set elevator path
    - since we have a set, should it be find the index of the curr floor then iterate up/down?
    - use an if statement to skip the incorrect floors?

    */
    
    // example set: {-2, -1, 0, 2, 4, 5, 8} and direction = UP
    //                       ^ start
    // want to start at 0 and iterate through until last item of 8 is hit, then switch to down until -2 is reached

    // additionally if additional buttons are added during the path traversal
    // example set: {-2, -1, 2, 4, 5, 6, 8, 8} and direction = UP
    //                       ^ start
    // floors are removed after leaving

}

void Controller::printInfo() const {
    std::cout << "Current Floor:    " << currentFloor << '\n';
    std::cout << "Going:            " << direction << std::endl;

    std::cout << "Path: " << '\n';
    // for (int i : elevatorPath) {
        
    // }


}

