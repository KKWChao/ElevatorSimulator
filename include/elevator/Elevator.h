#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "../common/Base.h"
#include "../buttons/ElevatorButton.h"
#include "../common/ElevatorDirection.h"

class Elevator : public Base{
    public:
        Elevator(int lowestFloor, int highestFloor);

        void setElevatorButtons(int lowestFloor, int highestFloor) {
            for (int i=lowestFloor; i<=highestFloor; ++i) {
                elevatorButtons.push_back(ElevatorButton(i));
            };
        };
        void setDoorStatus(bool doorStatus) {this->doorStatus = doorStatus;};
        void setCurrentFloor(int floor) {this->currentFloor = floor;};
        void setDirection(ElevatorDirection direction) {this->direction = direction;};
        void setNextFloor(int floorNumber);

        int getLowestFloor() const {return lowestFloor;};
        int getHighestFloor() const {return highestFloor;};
        bool getDoorStatus() const {return doorStatus;};
        ElevatorDirection getDirection() const {return this->direction;};

        int getCurrentFloor() const {return currentFloor;};
        ElevatorButton getButton(int floorNumber) {return elevatorButtons.at(floorNumber+floorOffset);}; 


        void handleButtonPress(int floorNumber);

        void printInfo() const override;
        void printActiveButtons() const;

    private:
        int lowestFloor;
        int highestFloor;
        ElevatorDirection direction;
        bool doorStatus;
        int currentFloor;
        int floorNumber;
        int floorOffset;
        std::vector<ElevatorButton> elevatorButtons;
};

#endif