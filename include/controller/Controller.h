#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <set>
#include "../include/buttons/ElevatorButton.h"

class Controller {
    enum ElevatorDirection {UP, DOWN, IDLE};
    
    public:
        Controller(int lowFloor, int highFloor);

        ~Controller();

        void setDirection(ElevatorDirection elevatorDirection) { this->direction = direction; }; // either true for up or false for down
        void setDoorOpen(bool doorStatus) { this->doorStatus = doorStatus; };

        void handleButtonPress(int floor);
        void handlePathLogic();

        void setCurrentFloor(int currentFloor);

        int getDirection() const { return this->direction; };
        bool getDoorOpen() const { return this->doorStatus; };
        int getCurrentFloor() const { return this->currentFloor; };
        std::set<int> getElevatorPath() const { return this->elevatorPath; };

        void printInfo() const;
        
    private:
        int lowestFloor;
        int highestFloor;
        int currentFloor;
        int floorOffset;
        bool doorStatus;
        ElevatorDirection direction = IDLE;
        std::vector<ElevatorButton> floorButtons;
        std::set<int> elevatorPath;
};

#endif