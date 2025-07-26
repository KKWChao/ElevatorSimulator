#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <set>
#include "../include/buttons/ElevatorButton.h"
#include "../include/elevator/Elevator.h"

class Controller {
    enum ElevatorDirection {UP, DOWN, IDLE};
    
    public:
        Controller(int lowFloor, int highFloor, int numElevators): 
            lowestFloor(lowFloor), highestFloor(highFloor), numElevators(numElevators), floorOffset(-lowestFloor) {
                setElevators(numElevators);
            };

        ~Controller();

        // TODO: Convert to holding multiple elevators
        Elevator getElevator(int elevatorNumber) const { return elevators.at(elevatorNumber);};
        
        
        void setElevators(int numElevators) {};

        void setElevatorDirection(ElevatorDirection elevatorDirection) { this->direction = direction; }; // either true for up or false for down
        
        void setDoorOpen(int whichElevator, bool doorStatus) {}; // DEFINE
        
        void setCurrentFloor(int whichElevator, int currentFloor);

        int getDirection(int whichElevator) const {}; 

        bool getDoorOpen(int whichElevator) const {}; // DEFINE
        
        std::set<int> getElevatorPath() const { return this->elevatorPath; };

        void handlePathLogic();
        void printInfo() const;
        
    private:
        int numElevators;
        int lowestFloor;
        int highestFloor;
        int currentFloor;
        int floorOffset;

        ElevatorDirection direction = IDLE;
        std::vector<Elevator> elevators;
        std::set<int> elevatorPath;
};

#endif