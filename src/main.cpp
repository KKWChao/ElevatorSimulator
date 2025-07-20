#include <iostream>
#include <string>

#include "../include/elevator/Elevator.h"

int main() {
    int lowestFloor;
    int highestFloor;

    char userInput;

    Elevator elevator;

    try {
        std::cout << "Enter the lowest floor number: ";
        std::cin >> lowestFloor;

        std::cout << "Enter the highest floor number: ";
        std::cin >> highestFloor;
    } catch (std::invalid_argument& exception) {
        std::cout << "Error: " << exception.what() << '\n';
    }

    elevator.setControlPanel(lowestFloor, highestFloor);
    
    std::cout << "Enter a floor from " << lowestFloor << " to " << highestFloor << ": " << '\n';
    std::cin >> userInput;

    while (userInput != 'q') {
        elevator.setCurrentFloor(userInput);
        
        std::cin >> userInput;
    }


    std::cout << "This is a test"<< '\n';
    
    return 0;
}