#include <iostream>

#include "elevator/Elevator.h"
#include "buttons/ElevatorButton.h"

Elevator::Elevator(int lowestFloor, int highestFloor):
    doorStatus(false), 
    currentFloor(0), 
    floorOffset(-lowestFloor) {
        setElevatorButtons(lowestFloor, highestFloor);
}

void Elevator::handleButtonPress(int floorNumber) {
    elevatorButtons.at(floorNumber + floorOffset).setPress();
};

void Elevator::printInfo() const {
    std::cout << "Floor:        " << getCurrentFloor() << '\n';
    std::cout << "Door Status:  " << getDoorStatus() << '\n';
    std::cout << std::endl;

    printActiveButtons();
}

void Elevator::printActiveButtons() const {
    std::cout << std::endl << "Active Buttons: " << std::endl;
    std::cout << "[ ";
    for (const ElevatorButton& e : elevatorButtons) {
        if (e.getPress() == true) {
            std::cout << e.getFloorNumber() << " ";
        }
    }
    std::cout << "]" << std::endl;
}