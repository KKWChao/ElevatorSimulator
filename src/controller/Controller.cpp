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

    for (int i=0; i<=highestFloor+floorOffset; ++i) {
        floorButtons.push_back(ElevatorButton(i-floorOffset));
    };
}


void Controller::setCurrentFloor(int currentFloor) {
    int actualFloor = currentFloor + floorOffset;

    if (currentFloor >= lowestFloor && currentFloor <= highestFloor) {
        
        this->currentFloor = currentFloor;
        
        // TODO: remove first element in the elevator path
        elevatorPath.erase(elevatorPath.begin());
        
        // TODO: re sort the elevator path
        handlePathLogic();

        floorButtons[actualFloor].setPress(false);

    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "The current floor is: " << floorButtons[actualFloor].getFloorNumber() << '\n';
}


void Controller::handleButtonPress(int floor) {
    if (floor >= lowestFloor && floor <= highestFloor) {
        // TODO: need to handle initial press to set direction 
        if (elevatorPath.empty()) {
            if (floor < currentFloor) {
                setDirection(false);
            } 
        }

        elevatorPath.push_back(floor);
        
        // TODO: setting button active
        floorButtons[floor+floorOffset].setPress(true);

    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "Added floor: " << floor << '\n';
}

void Controller::handlePathLogic() {
    // no need to swap
    // just use a pointer = currFloor and move along the vector until the list is empty

    // TODO: sort the list first

    // TODO: find the curr floor in the vector

    // TODO: depending on direction move up or down the array while removing items
    
    // TODO: once reaching beginning or end, switch directions until vector is empty
    

}

// basic sorting method
void sortVector() {

}

/* 
Path logic
- if statement to check for increasing?
- or sort the vector based on direction?

*/