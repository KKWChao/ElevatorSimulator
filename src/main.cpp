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


    // TODO:    Need to create a timer - 5s after entering elevator

    inputHandler.floorPrompt(lowestFloor, highestFloor);

    std::cin >> input;

    std::cout << "Elevator Doors Opening . . ." << std::endl;
    controller.getElevator(elevatorChoice).setDoorStatus(true);                 // Set elevator door to open

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
    controller.getElevator(elevatorChoice).setDoorStatus(false);                // Closing elevator door


    if (direction == "UP") {                                                    // Loop to iterate through the sets depending on direction

        std::cout << "Going UP . . ." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // timer start to next floor based on distance

        // use iterator on set to get next floors
        auto elevatorIterator = controller.getElevatorPath(elevatorChoice).find(currentFloor);



        // begin path 

        // FIX THIS:    Will need to switch directions once end is reached
        
        while (!controller.getElevatorPath(elevatorChoice).empty() ) {

            
            if (currentFloor != controller.getElevator(elevatorChoice).getCurrentFloor()) { // arrive at next floor

                std::this_thread::sleep_for(std::chrono::seconds(5));


                std::cout << "Arrived at " << currentFloor << std::endl;

                std::cout << "Elevator Doors Opening . . ." << std::endl;
                controller.getElevator(elevatorChoice).setDoorStatus(true);     // Set elevator door to open
                
                controller.getElevator(elevatorChoice).setCurrentFloor(*elevatorIterator);

                controller.getVisitedPath(elevatorChoice).insert(currentFloor);

                // TODO:    Pause elevator for additional inputs

                std::cout << "Elevator Doors Closing . . ." << std::endl;
                controller.getElevator(elevatorChoice).setDoorStatus(false);    // Closing elevator door
            }

            elevatorIterator++;
        }


        
        for (const int floor: controller.getElevatorPath(0)) {                  // convert to while loop to be able to stop at floors
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

    std::cout << std::endl << "Elevator Sim Done" << std::endl;
    
    return 0;
}

// TODO: I/O - change to factory pattern later
