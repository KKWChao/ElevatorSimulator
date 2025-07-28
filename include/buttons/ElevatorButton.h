#ifndef ELEVATORBUTTON_H
#define ELEVATORBUTTON_H

#include "./Button.h"

class ElevatorButton : public Button {
    public:
        ElevatorButton();
        ElevatorButton(int floor):floorNumber(floor) {};
        
        void setPress() {pressed = true;};
        void reset() override {pressed = false;}; 

        int getFloorNumber() const { return this->floorNumber; };

        void printInfo() const override {
            std::cout << "Elevator Button" << '\n'
            << "Floor Number: " << getFloorNumber() <<'\n'
            << "Pressed: "<< getPress() << std::endl;            
        };
    private:
        int floorNumber;
};

#endif