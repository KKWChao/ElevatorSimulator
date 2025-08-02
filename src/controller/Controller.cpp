#include <iostream>

#include <vector>
#include <string>
#include "controller/Controller.h"
#include "elevator/Elevator.h"


// ELEVATOR MANAGEMENT

void Controller::handlePathLogic(int whichElevator, std::string direction) { // unused
    
    Elevator targetElevator = getElevator(whichElevator);
    std::set<int> targetElevatorPath = getElevatorPath(whichElevator);

    if (direction == "UP") {
        for (int nextFloor : targetElevatorPath) {
            if (targetElevator.getCurrentFloor() <= nextFloor) {
                std::cout << nextFloor << " " ;
            } 
        }
    } else if (direction == "DOWN") {
        for (auto it = targetElevatorPath.rbegin(); it != targetElevatorPath.rend(); ++it) {
            if (targetElevator.getCurrentFloor() >= *it) {
                std::cout << *it << " " ;
            } 
        }    
    }

}

void Controller::updatePathLogic(int whichElevator) { // unused
    std::set<int> targetElevatorPath = getElevatorPath(whichElevator);
    std::set<int> updatedElevatorPath = getVisitedPath(whichElevator);

    
};

void Controller::updateElevator(Elevator& targetElevator, int elevatorNumber, int floor, ElevatorDirection direction) {

    std::cout << std::endl << std::endl << "Arrived at floor " << floor << std::endl;
    std::cout << std::endl <<"--- Elevator Doors Opening ---" << std::endl << std::endl;
    
    targetElevator.setDoorStatus(true);

    targetElevator.setCurrentFloor(floor);

    targetElevator.setDirection(direction);
    
    // Have to figure out why it isn't erasing the floor?
    // targetElevator.getButton(floor).reset();

    // getElevatorPath(elevatorNumber).erase(floor);
}

void Controller::printInfo() const {
    std::cout << "Number of Elevators:  " << numElevators << '\n';

    std::cout << "Path: " << '\n';
    // for (int i : elevatorPath) {
        
    // }


}

