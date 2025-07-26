#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "../buttons/ElevatorButton.h"
#include "../controller/Controller.h"

class Elevator {
    public:
        Elevator();

        ~Elevator() = default;

        void setDoorOpen(bool doorOpen);
        void setCurrentFloor(int floorNumber);
        void setControlPanel(int lowestFloor, int highestFloor);
        void setElevatorButtons(int lowestFloor, int highestFloor);

        int getLowestFloor() const {return lowestFloor;};
        int getHighestFloor() const {return highestFloor;};
        bool getDoorOpen() const;
        int getNextFloor();
        int getCurrentFloor() const;
        const Controller& getControlPanel() const;
        ElevatorButton getButton(int floorNumber); 

        void printInfo();

    private:
        int lowestFloor;
        int highestFloor;
        bool doorOpen;
        int currentFloor;
        int floorNumber;
        int floorOffset;
        
        Controller* controller;
        std::vector<ElevatorButton> elevatorButtons;
};

#endif