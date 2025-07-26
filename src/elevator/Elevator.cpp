#include <iostream>

#include "elevator/Elevator.h"
#include "buttons/ElevatorButton.h"
#include "controller/Controller.h"

Elevator::Elevator():doorOpen(false), currentFloor(0), controller() {}

void Elevator::setDoorOpen(bool doorOpen) {
    this->doorOpen = doorOpen;
}

void Elevator::setCurrentFloor(int floorNumber) {
    this->floorNumber=floorNumber;
};

void Elevator::setControlPanel(int lowestFloor, int highestFloor) {
    controller = new Controller(lowestFloor, highestFloor);
};

void Elevator::setElevatorButtons(int lowestFloor, int highestFloor) {
    for (int i=lowestFloor; i<=highestFloor; ++i) {
        elevatorButtons.push_back(ElevatorButton(i));
    };
}

bool Elevator::getDoorOpen() const {
    return this->doorOpen;
}

int Elevator::getCurrentFloor() const {
    return this->currentFloor;
}

int Elevator::getNextFloor() {
    // TODO: Finish this
    return 0;
}

const Controller& Elevator::getControlPanel() const {
    if (!controller) {
        throw std::runtime_error("Controller not initialized");
    }

    return *controller;
}

ElevatorButton Elevator::getButton(int floorNumber) {
    return elevatorButtons.at(floorNumber+floorOffset);
}

void Elevator::printInfo() {
    std::cout << "Floor:        " << getCurrentFloor() << '\n';
    std::cout << "Door Status:  " << getDoorOpen() << '\n';
    std::cout << std::endl;

    std::cout << "Inactive buttons: " << '\n';
    for (const ElevatorButton& e : elevatorButtons) {
        if (!e.getPress()) {
            std::cout << e.getFloorNumber() << " ";
        }
    }
}
