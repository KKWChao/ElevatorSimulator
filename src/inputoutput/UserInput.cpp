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
    
    std::cout << "Enter your current floor:         ";
    std::cin >> currentFloor;
    std::cout << std::endl;

    return currentFloor;
};

ElevatorDirection UserInput::getDirection(std::string& inputDirection) {
    std::cout << "Going UP or DOWN?: ";
    std::cin.clear();
    std::cin >> inputDirection;
    ElevatorDirection direction;

    if (inputDirection == "UP" || inputDirection == "Up" || inputDirection == "up") {
        direction = UP;
    } else if (inputDirection == "DOWN" || inputDirection == "Down" || inputDirection == "down") { 
        direction = DOWN;
    } else {
        direction = IDLE;
    }

    std::cout << "Calling Elevator . . ." << std::endl;

    return direction;
};


void UserInput::floorPrompt(int& lowestFloor, int& highestFloor, int floor) {
    switch (floor) {
        case 1:
            break;
        case 2:
            break;
        default:
            std::cout << "Enter destination floor or 'q' to quit:  (" 
            << lowestFloor << " - " 
            << highestFloor << "): " << std::endl;
            break;
    }
}

int UserInput::getElevatorChoice(int numElevators) {
    int elevator;

    // TODO:    Setup a delay dependent on elevator distance
    
    std::cout << "Select Elevator: (1 - " << numElevators << "): "; 
    
    std::cin >> elevator;

    return elevator-1;
}

int UserInput::getFloorInput(int& lowestFloor, int& highestFloor, std::string& input, int& userFloorInput) {
    try {
        userFloorInput = std::stoi(input);

        if (userFloorInput < lowestFloor || userFloorInput > highestFloor) {
            throw std::invalid_argument("Floor input out of range");
        }

    } catch (std::invalid_argument& e) {
        std::cout << "Invalid input. Please enter a number or 'q' to quit.\n";
    } catch (std::out_of_range& e) {
        std::cout << "Input number is out of range.\n";
    }

    return userFloorInput;
}


void UserInput::elevatorSetup(int& lowestFloor, int&highestFloor, int& numElevators, int&currentFloor) {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|           ELEVATOR SIM SETUP             |" << std::endl;
    // std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;

    lowestFloor = getLowestFloor();

    highestFloor = getHighestFloor();

    numElevators = getNumElevators();

    currentFloor = getCurrentFloor();

    // std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|               END OF SETUP               |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    std::cout << std::endl;

};

