#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include "../include/inputoutput/UserInput.h"
#include "../include/elevator/Elevator.h"
#include "../include/controller/Controller.h"

void handleElevatorButtonInput(
    UserInput& inputHandler,
    Controller& controller, 
    std::string& input, 
    int& userFloorInput,
    int& elevatorChoice,
    int& lowestFloor, 
    int& highestFloor) {

    while (input != "q" && input != "Q") {

        userFloorInput = inputHandler.getFloorInput(lowestFloor, highestFloor, input, userFloorInput);

        std::cout << "Elevator button " << userFloorInput << " activated." << std::endl;

        controller.getElevator(elevatorChoice).handleButtonPress(userFloorInput);

        controller.setElevatorPath(elevatorChoice, userFloorInput);

        std::cin >> input;
    }

}

int main() {

    int lowestFloor, highestFloor, numElevators, elevatorChoice, currentFloor, targetFloor, userFloorInput;
    std::string direction, input;

    UserInput inputHandler;

    inputHandler.elevatorSetup(lowestFloor, highestFloor, numElevators, currentFloor);

    Controller controller(lowestFloor, highestFloor, numElevators);
    
    inputHandler.getDirection(direction);

    // TODO:    Have elevators start at diffrent floors
    //          Then have the call get the closest elevator / elevator going in the same direction          
    elevatorChoice = inputHandler.getElevatorChoice(numElevators);

    Elevator& targetElevator = controller.getElevator(elevatorChoice);
    std::set<int>& targetElevatorPath = controller.getElevatorPath(elevatorChoice);


    std::cout << "Elevator Doors Opening . . ." << std::endl;
    targetElevator.setDoorStatus(true);                                         // Set elevator door to open


    // TODO:    Need to create a timer - 5s after entering elevator

    inputHandler.floorPrompt(lowestFloor, highestFloor, 3);

    std::cin >> input;

    handleElevatorButtonInput(
        inputHandler, 
        controller, 
        input, 
        userFloorInput, 
        elevatorChoice, 
        lowestFloor, 
        highestFloor
    );
    
    std::cout << "Elevator Doors Closing . . ." << std::endl;
    targetElevator.setDoorStatus(false);                                        // Closing elevator door



    if (direction == "UP") {                                                    // Loop to iterate through the sets depending on direction

        std::cout << "Going UP . . ." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // timer start to next floor based on distance

        // begin path 

        // FIX THIS:    Will need to switch directions once end is reached

        while (!targetElevatorPath.empty()) {
            int currentFloor = targetElevator.getCurrentFloor();

            for (int floor : targetElevatorPath) {
                if (floor > currentFloor) {
                    std::cout << "Elevator moving to up to floor " << floor << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    targetElevator.setCurrentFloor(floor);
                }

                std::cout << "Arrived at floor " << floor << std::endl;
                std::cout << ". . . Elevator Doors Opening . . ." << std::endl;
                targetElevator.setDoorStatus(true); 

                targetElevatorPath.erase(floor); 

                std::cout << "Enter additional Floors? (Y / N)" << std::endl;
                std::cin >> input;

                if (input == "Y" || input == "y") {
                    inputHandler.floorPrompt(lowestFloor, highestFloor, 3);
                    std::cin >> input;
                    
                    handleElevatorButtonInput(
                        inputHandler, 
                        controller, 
                        input, 
                        userFloorInput, 
                        elevatorChoice, 
                        lowestFloor, 
                        highestFloor
                    );
                }

                std::cout << "Elevator Doors Closing . . ." << std::endl;
                targetElevator.setDoorStatus(false);                            // Closing elevator door

                break;
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
    std::cout << std::endl << "Elevator Sim Complete" << std::endl;
    std::cout << std::endl;

    return 0;
}

// TODO:    I/O - change to factory pattern later
