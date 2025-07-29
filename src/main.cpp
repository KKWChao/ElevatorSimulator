#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include "../include/inputoutput/UserInput.h"
#include "../include/elevator/Elevator.h"
#include "../include/controller/Controller.h"

int main() {
    int lowestFloor, highestFloor, numElevators, currentFloor, targetFloor, userFloorInput;
    std::string direction, input;

    UserInput inputHandler;

    inputHandler.elevatorSetup(lowestFloor, highestFloor, numElevators, currentFloor);

    Controller controller(lowestFloor, highestFloor, numElevators);
    
    inputHandler.getDirection(direction);



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

            controller.getElevator(0).handleButtonPress(userFloorInput);

            controller.setElevatorPath(0, userFloorInput);

        } catch (std::invalid_argument& e) {
            std::cout << "Invalid input. Please enter a number or 'q' to quit.\n";
        } catch (std::out_of_range& e) {
            std::cout << "Input number is out of range.\n";
        }
        
        std::cin >> input;
    }

 
    // Loop to iterate through the sets depending on direction
    if (direction == "UP") {
        std::cout << "Going UP . . ." << std::endl;
        
        // timer start to next floor based on distance

        // use iterator on set to get next floors
        auto elevatorIterator = controller.getElevatorPath(0).find(currentFloor);

        // begin path 
        while (elevatorIterator != controller.getElevatorPath(0).end()) {

            // arrive at next floor
            if (currentFloor != controller.getElevator(0).getCurrentFloor()) {

                std::this_thread::sleep_for(std::chrono::seconds(5));


                std::cout << "Arrived at " << currentFloor << std::endl;
                
                controller.getElevator(0).setCurrentFloor(*elevatorIterator);

                // pause elevator for additional inputs


            }

            elevatorIterator++;
        }


        // convert to while loop to be able to stop at floors
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
