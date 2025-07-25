#include <iostream>
#include <string>

#include "../include/elevator/Elevator.h"

int main() {
    int lowestFloor;
    int highestFloor;

    char userInput;

    Elevator elevator;

    std::cout << "Enter the lowest floor number: ";
    std::cin >> lowestFloor;

    std::cout << "Enter the highest floor number: ";
    std::cin >> highestFloor;

    elevator.setControlPanel(lowestFloor, highestFloor);
    
    std::cout << "Enter destination floor:  (" << lowestFloor << " - " << highestFloor << "): " << '\n';
    std::cin >> userInput;

    // while (userInput != 'q') {
    //     elevator.setCurrentFloor(userInput);
    //     elevator.getControlPanel().getElevatorPath();
        
    //     std::cin >> userInput;
    // }

    
    elevator.printInfo();

    elevator.getControlPanel().printInfo();

    std::cout << elevator.getCurrentFloor() << std::endl;
    std::cout << "This is a test"<< '\n';
    
    return 0;
}

// TODO: I/O - change to factory pattern later
