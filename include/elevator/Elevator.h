#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../controller/Controller.h"

class Elevator {
    public:
        Elevator();

        ~Elevator() = default;

        void setDoorOpen(bool doorOpen);
        void setCurrentFloor(int floorNumber);
        void setControlPanel(int lowestFloor, int highestFloor);

        bool getDoorOpen() const;
        int getCurrentFloor() const;
        const Controller& getControlPanel() const;

    private:
        bool doorOpen;
        int currentFloor;
        int floorNumber;
        Controller* controller;

};

#endif