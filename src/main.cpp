#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "../include/elevator/Elevator.h"
#include "../include/controller/Controller.h"

int main() {
    int lowestFloor;
    int highestFloor;
    int numElevators;
    std::string direction;
    int currentFloor;
    std::string userInput;
    int targetFloor;
    std::string input;
    int userFloorInput;

    // Sim setup
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|       ELEVATOR SIM SETUP        |" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Enter the lowest floor number:    ";
    std::cin >> lowestFloor;
    std::cout << std::endl;

    std::cout << "Enter the highest floor number:   ";
    std::cin >> highestFloor;
    std::cout << std::endl;

    std::cout << "Enter the number of elevators:    ";
    std::cin >> numElevators;
    std::cout << std::endl;

    std::cout << "-----------END OF SETUP-----------" << std::endl << std::endl;

    Controller controller(lowestFloor, highestFloor, numElevators);
    
    std::cout << "Enter your current floor: ";
    std::cin >> currentFloor;

    std::cout << "Going UP or DOWN?: ";
    std::cin >> direction;

    if (direction == "UP") {
        std::cout << "UP";
    } else if (direction == "DOWN") {
        std::cout << "DOWN";  
    } else {
        std::cout << "IDLE";
    }
    std::cout << std::endl;

    // TODO: Need to create a timer - 5s after entering elevator


    // Floor Selection
    std::cout << "Enter destination floor or 'q' to quit:  (" 
        << lowestFloor << " - " 
        << highestFloor << "): " << std::endl;

    
    // string stream for input
    std::cin >> input;

    // Activating buttons on the elevator and adding it to the controller 
    while (input != "q" && input != "Q") {
        try {
            userFloorInput = std::stoi(input);
            
            std::cout << "Adding floor " << userFloorInput << " to the path." << std::endl;

            // Set button to active
            controller.getElevator(0).handleButtonPress(userFloorInput);

            // add it to the path
            controller.setElevatorPath(0, userFloorInput);

        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cout << "Invalid input. Please enter a number or 'q' to quit.\n";
        } catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            std::cout << "Input number is out of range.\n";
        }
        
        std::cin >> input;
    }

 


    // for route testing 
    if (direction == "UP") {
        std::cout << "Going UP" << std::endl;

        for (const int floor: controller.getElevatorPath(0)) {
            if (currentFloor <= floor) {
                std::cout << floor << " " ;
            }
        }
    } else if (direction == "DOWN") {
           std::cout << "Going DOWN" << std::endl;
        for (auto it = controller.getElevatorPath(0).rbegin(); it != controller.getElevatorPath(0).rend(); ++it) {
            if (currentFloor >= *it) {
                std::cout << *it << " " ;
            }
        }    
    }

    std::cout << std::endl;
    
    return 0;
}

// TODO: I/O - change to factory pattern later
