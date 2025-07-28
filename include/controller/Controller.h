#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <set>
#include "../common/Base.h"
#include "../include/buttons/ElevatorButton.h"
#include "../include/elevator/Elevator.h"
#include "../include/common/ElevatorDirection.h"

class Controller : public Base{

    public:
        Controller(int lowFloor, int highFloor, int numElevators): 
            lowestFloor(lowFloor), 
            highestFloor(highFloor), 
            numElevators(numElevators), 
            floorOffset(-lowestFloor) {
                setElevators(numElevators);
            };

        void setElevators(int numElevators) {

            for (int i = 0; i < numElevators; ++i) {
                elevators.emplace_back(lowestFloor, highestFloor);            // create elevators
                elevatorPaths.emplace_back();   // create elevator paths
            }
        };

        void setElevatorDirection(int whichElevator, ElevatorDirection elevatorDirection) {
            elevators.at(whichElevator).setDirection(elevatorDirection);
        };

        void setElevatorDoorStatus(int whichElevator, bool doorStatus) {
            elevators.at(whichElevator).setDoorStatus(doorStatus);
        };

        void setElevatorCurrentFloor(int whichElevator, int floor) {
            elevators.at(whichElevator).setCurrentFloor(floor);
        };

        Elevator& getElevator(int elevatorNumber) {
            return elevators.at(elevatorNumber);
        };

        int getElevatorDirection(int whichElevator) const {
            return elevators.at(whichElevator).getDirection();
        }; 

        bool getElevatorDoorStatus(int whichElevator) const {
            return elevators.at(whichElevator).getDoorStatus();
        }; 
        
        // Path logic
        void setElevatorPath(int whichElevator, int floor) {
            elevatorPaths.at(whichElevator).emplace(floor);
        }

        const std::set<int>& getElevatorPath(int whichElevator) const {
            return elevatorPaths.at(whichElevator);
        }
        const std::vector<std::set<int>>& getElevatorPaths() const { 
            return this->elevatorPaths; 
        };

        void handlePathLogic(int whichElevator, std::string direction); // TODO: FIX THIS
        void printInfo() const override;

        void handleStart();
        
    private:        
        int numElevators;
        int lowestFloor;
        int highestFloor;
        int floorOffset;

        ElevatorDirection direction = IDLE;
        std::vector<Elevator> elevators;
        std::vector<std::set<int>> elevatorPaths;
};

#endif