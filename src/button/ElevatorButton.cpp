#include <iostream>

#include "../include/buttons/ElevatorButton.h"

ElevatorButton::ElevatorButton(int floorNumber) {
    setFloorNumber(floorNumber);
}

void ElevatorButton::setFloorNumber(int floorNumber) {
    this->floorNumber = floorNumber;
}

void ElevatorButton::setPress() {
    pressed = true;
}

void ElevatorButton::reset() {
    pressed = false;
}