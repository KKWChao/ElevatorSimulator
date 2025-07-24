#ifndef ELEVATORBUTTON_H
#define ELEVATORBUTTON_H

#include "./Button.h"

class ElevatorButton : public Button {
    public:
        ElevatorButton();
        ElevatorButton(int floor);
        
        void setFloorNumber(int floorNumber);
        void setPress();
        void reset() override;

        int getFloorNumber() const { return this->floorNumber; };
    private:
        int floorNumber;
};

#endif