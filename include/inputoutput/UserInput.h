#ifndef USERINPUT_H
#define USERINPUT_H

#include "../common/ElevatorDirection.h"
class UserInput {
    public:
        int getLowestFloor();
        int getHighestFloor();
        int getNumElevators();
        int getCurrentFloor();
        ElevatorDirection getDirection(std::string& direction);

        void floorPrompt(int& lowestFloor, int& highestFloor, int floor);
        int getElevatorChoice(int numElevators);
        int getFloorInput(int& lowestFloor, int& highestFloor, std::string& input, int& userFloorInput);

        void elevatorSetup(int& lowestFloor, int& highestFloor, int& numElevators, int& currentFloor);
};



#endif