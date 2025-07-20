#include <iostream>

#include "elevator/Elevator.h"
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

bool Elevator::getDoorOpen() const {
    return this->doorOpen;
}

int Elevator::getCurrentFloor() const {
    return this->currentFloor;
}

const Controller& Elevator::getControlPanel() const {
    return *controller;
}
