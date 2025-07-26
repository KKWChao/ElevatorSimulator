#include <iostream>
#include <string>

#include "../include/elevator/Elevator.h"
#include "../include/controller/Controller.h"

int main() {
    int lowestFloor;
    int highestFloor;
    int numElevators;
    char userInput;
    std::string direction;
    

    // Sim setup
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|       ELEVATOR SIM SETUP        |" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Enter the lowest floor number:  ";
    std::cin >> lowestFloor;
    std::cout << std::endl;

    std::cout << "Enter the highest floor number: ";
    std::cin >> highestFloor;
    std::cout << std::endl;

    std::cout << "Enter the number of elevators: ";
    std::cin >> numElevators;
    std::cout << std::endl;

    std::cout << "----------END OF SETUP------------" << std::endl << std::endl;

    // TODO: pass the number of elevators to the controller
    //      That means that controller should not belong to the elevator
    //      Controller should have multiple elevators -> will need to redesign

    Controller controller(lowestFloor, highestFloor, numElevators);

    Elevator elevator;
    
    // Query user if they want to press the up or down button to call elevator
    std::cout << "Going UP or DOWN?: ";
    std::cin >> direction;

    if (direction == "UP") {
        
    } else if (direction == "DOWN") {

    } else {
        return 0;
    }

    // TODO: Need to create a timer - 5s after entering elevator


    // Floor Selection
    std::cout << "Enter destination floor:  (" 
        << lowestFloor << " - " 
        << highestFloor << "): " << '\n';

    // string stream for input
    std::cin >> userInput;


    // Activating buttons on the elevator and adding it to the controller 
    while (userInput != 'q') {
        
        // Set button to active

        // add it to the path

        
        
        std::cin >> userInput;
    }

    
    elevator.printInfo();

    elevator.getControlPanel().printInfo();

    std::cout << elevator.getCurrentFloor() << std::endl;
    std::cout << "This is a test"<< '\n';
    
    return 0;
}

// TODO: I/O - change to factory pattern later
