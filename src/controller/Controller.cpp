#include <iostream>

#include <vector>
#include <string>
#include "controller/Controller.h"
#include "elevator/Elevator.h"


// ELEVATOR MANAGEMENT

void Controller::handlePathLogic(int whichElevator, std::string direction) {
    if (direction == "UP") {
        for (std::set<int>::iterator it = getElevatorPath(0).find(getElevator(0).getCurrentFloor()); it != getElevatorPath(0).end(); ++it) {
            if (getElevator(whichElevator).getCurrentFloor() <= *it) {
                std::cout << *it << " " ;
            } 
        }
    } else if (direction == "DOWN") {
        for (std::set<int>::iterator it = getElevatorPath(0).end(); it != getElevatorPath(0).find(getElevator(0).getCurrentFloor()); --it) {
            if (getElevator(whichElevator).getCurrentFloor() >= *it) {
                std::cout << *it << " " ;
            } 
        }    
    }

}

void Controller::printInfo() const {
    std::cout << "Number of Elevators:  " << numElevators << '\n';

    std::cout << "Path: " << '\n';
    // for (int i : elevatorPath) {
        
    // }


}

