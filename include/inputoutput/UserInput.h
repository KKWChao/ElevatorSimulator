#ifndef USERINPUT_H
#define USERINPUT_H

class UserInput {
    public:
        int getLowestFloor();
        int getHighestFloor();
        int getNumElevators();
        int getCurrentFloor();
        void getDirection(std::string& direction);

        void floorPrompt(int& lowestFloor, int& highestFloor);
        int getElevatorChoice(int numElevators);
        int getFloorInput(int& lowestFloor, int& highestFloor, std::string& input, int& userFloorInput);

        void elevatorSetup(int& lowestFloor, int& highestFloor, int& numElevators, int& currentFloor);
};



#endif