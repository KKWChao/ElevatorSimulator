#include <iostream>

#include "elevator/Elevator.h"
#include "buttons/ElevatorButton.h"

Elevator::Elevator(int lowestFloor, int highestFloor):
    doorStatus(false), 
    currentFloor(0), 
    floorOffset(-lowestFloor) {
        setElevatorButtons(lowestFloor, highestFloor);
}

int Elevator::getNextFloor() {
    // TODO: Finish this
    return 0;
}

void Elevator::handleButtonPress(int floorNumber) {
    elevatorButtons.at(floorNumber + floorOffset).setPress();
};

void Elevator::printInfo() const {
    std::cout << "Floor:        " << getCurrentFloor() << '\n';
    std::cout << "Door Status:  " << getDoorStatus() << '\n';
    std::cout << std::endl;

    std::cout << "Inactive buttons: " << '\n';
    // for (const ElevatorButton& e : elevatorButtons) {
    //     if (!e.getPress()) {
    //         std::cout << e.getFloorNumber() << " ";
    //     }
    // }
}
