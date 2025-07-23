#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <set>
#include "../buttons/ElevatorButton.h"

class Controller {
    public:
        Controller(int lowFloor, int highFloor);

        ~Controller();

        void setDirection(bool direction) { this->direction = direction; }; // either true for up or false for down
        void setDoorOpen(bool doorStatus) { this->doorStatus = doorStatus; };

        void handleButtonPress(int floor);
        void handlePathLogic();


        void setCurrentFloor(int currentFloor);


        
        int getDirection() const { return this->direction; };
        bool getDoorOpen() const { return this->doorStatus; };
        int getCurrentFloor() const { return this->currentFloor; };
        std::set<int> getElevatorPath() const { return this->elevatorPath; };
        
    private:
        int lowestFloor;
        int highestFloor;
        int currentFloor;
        int floorOffset;
        bool doorStatus;
        bool direction;
        std::vector<ElevatorButton> floorButtons;
        std::set<int> elevatorPath;
};

#endif