#include <iostream>
#include <../include/inputoutput/UserInput.h>

int UserInput::getLowestFloor() {
    int lowestFloor;

    std::cout << "Enter the lowest floor number:    ";
    std::cin >> lowestFloor;
    std::cout << std::endl;

    return lowestFloor;
};

int UserInput::getHighestFloor() {
    int highestFloor;

    std::cout << "Enter the highest floor number:   ";
    std::cin >> highestFloor;
    std::cout << std::endl;

    return highestFloor;
};

int UserInput::getNumElevators() {
    int numElevators;

    std::cout << "Enter the number of elevators:    ";
    std::cin >> numElevators;
    std::cout << std::endl;
    
    return numElevators;
};

int UserInput::getCurrentFloor() {
    int currentFloor;
    
    std::cout << "Enter your current floor: ";
    std::cin >> currentFloor;
    std::cout << std::endl;

    return currentFloor;
};

void UserInput::getDirection(std::string& direction) {
    std::cout << "Going UP or DOWN?: ";
    std::cin.clear();
    std::cin >> direction;

    if (direction == "UP" || direction == "Up" || direction == "up") {
        direction = "UP";
    } else if (direction == "DOWN" || direction == "Down" || direction == "down") { 
        direction = "DOWN";
    } else {
        direction = "IDLE";
    }

    std::cout << "Calling Elevator ..." << std::endl;
};

void UserInput::elevatorSetup(int& lowestFloor, int&highestFloor, int& numElevators, int&currentFloor) {
    // Sim setup
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|       ELEVATOR SIM SETUP        |" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;

    lowestFloor = getLowestFloor();

    highestFloor = getHighestFloor();

    numElevators = getNumElevators();

    currentFloor = getCurrentFloor();

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|          END OF SETUP           |" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    
    std::cout << std::endl;

};

