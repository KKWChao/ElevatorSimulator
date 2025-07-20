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
        this->floorButtons.push_back(ElevatorButton(i-floorOffset));
    };
}


void Controller::setCurrentFloor(int currFloor) {
    if (currFloor >= this->lowestFloor && currFloor <= this->highestFloor) {
        this->currentFloor = currFloor;
        
        // TODO: remove first element in the elevator path
        
        // TODO: re sort the elevator path 
    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "The current floor is: " << this->currentFloor << '\n';
}


void Controller::handleButtonPress(int floor) {
    if (floor >= this->lowestFloor && floor <= this->highestFloor) {
        this->elevatorPath.push_back(floor);
        
        // TODO: setting button active
        this->floorButtons[floor+floorOffset].setPress(true);

    } else {
        throw std::invalid_argument("Invalid floor");
    };

    std::cout << "Added floor: " << floor << '\n';
}

void Controller::handlePathLogic() {
    // TODO: handlePathLogic
    // is it better to have a deque?
    //      - can pop front
    //      - but would have to sort the vector before that

    // or is it better to use a vector?
    //      - worse time for removing front item after sorting
}

/* 
Path logic
- if statement to check for increasing?
- or sort the vector based on direction?

*/