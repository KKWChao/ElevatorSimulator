#include <iostream>

#include "ElevatorButton.h"

ElevatorButton::ElevatorButton(int floorNumber) {
    setFloorNumber(floorNumber);
}

void ElevatorButton::setFloorNumber(int floorNumber) {
    this->floorNumber = floorNumber;
}

void ElevatorButton::setPress(bool pressed) {
    this->pressed = pressed;
}

int ElevatorButton::getFloorNumber() const {
    return floorNumber;
}