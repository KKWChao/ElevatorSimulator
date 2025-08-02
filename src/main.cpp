#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include "../include/inputoutput/UserInput.h"
#include "../include/elevator/Elevator.h"
#include "../include/controller/Controller.h"
#include "../include/common/ElevatorDirection.h"

void handleElevatorButtonInput(
    UserInput& inputHandler,
    Controller& controller, 
    std::string& input, 
    int& userFloorInput,
    int& elevatorChoice,
    int& lowestFloor, 
    int& highestFloor) {

    Elevator& targetElevator = controller.getElevator(elevatorChoice);

    while (input != "q" && input != "Q") {
        
        userFloorInput = inputHandler.getFloorInput(lowestFloor, highestFloor, input, userFloorInput);

        std::cout << "Elevator button " << userFloorInput << " activated." << std::endl;

        targetElevator.handleButtonPress(userFloorInput);

        controller.setElevatorPath(elevatorChoice, userFloorInput);

        std::cin >> input;
    }

}

int main() {

    int lowestFloor, highestFloor, numElevators, elevatorChoice, currentFloor, targetFloor, userFloorInput;
    std::string direction, input;
    bool directionSwitch;

    UserInput inputHandler;

    inputHandler.elevatorSetup(lowestFloor, highestFloor, numElevators, currentFloor);

    Controller controller(lowestFloor, highestFloor, numElevators);

    std::cout << std::endl;
    std::cout << "--- Beginning Elevator Sim ---" << std::endl << std::endl;
 
    

    // TODO:    Have elevators start at diffrent floors
    //          Then have the call get the closest elevator / elevator going in the same direction          
    elevatorChoice = inputHandler.getElevatorChoice(numElevators);

    Elevator& targetElevator = controller.getElevator(elevatorChoice);
    std::set<int>& targetElevatorPath = controller.getElevatorPath(elevatorChoice);


    targetElevator.setDirection(inputHandler.getDirection(direction));

    std::cout << '\n' << "--- Elevator Doors Opening ---" << '\n' << std::endl;
    targetElevator.setDoorStatus(true);


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

    bool movingDirection;

    std::cout << '\n' << "--- Elevator Doors Closing ---" << '\n' << std::endl;
    targetElevator.setDoorStatus(false);

    std::this_thread::sleep_for(std::chrono::seconds(1));


    // Loop through all floors of the set 
    while (!targetElevatorPath.empty()) {
        // TODO:   thought to use this to fix the direction output 
        movingDirection = false; 
    
        std::cout << "--- Going " 
        << ((targetElevator.getDirection() == ElevatorDirection::UP && movingDirection == false) ? "Up": "Down") 
        << " ---" << std::endl;

        // Check for Up direction first
        if (targetElevator.getDirection() == ElevatorDirection::UP) {
                                                 
            // Looping through the elevator set
            for (int floor : targetElevatorPath) {

                // if (targetElevator.getDirection() == ElevatorDirection::UP) std::cout << "--- Going UP ---" << std::endl;

                // only will execute on floor greater than current floor
                if (floor > targetElevator.getCurrentFloor()) {

                    std::cout << "Next Floor: " << floor << std::endl << std::endl;

                    // To simulate time delay going up
                    for (int i = 0; i < floor - targetElevator.getCurrentFloor(); ++i) {
                        std::cout << " . " << std::flush;
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    }
                
                    // resetting the active button after arriving at the floor
                    targetElevator.getButton(floor).reset();

                    // removing the floor from the path
                    targetElevatorPath.erase(floor); 

                    // Updating path by removing the current floor, current direciton, and door status of the elevator
                    controller.updateElevator(targetElevator, elevatorChoice, floor, UP);


                    // prints out the remaining active buttons
                    std::cout << std::endl << "Active Buttons: " << std::endl;
                    std::cout << "[ ";
                    for (int i : targetElevatorPath) {
                        std::cout << i << " ";
                    }
                    std::cout << "]" << std::endl;

                    // prompt user for additional inputs
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

                    std::cout  << '\n' <<  "--- Elevator Doors Closing ---"  << std::endl <<  std::endl;
                    targetElevator.setDoorStatus(false);                   
                    std::cout << std::endl;

                    movingDirection = true;

                    break;
                
                }

                // switching direction to down
                if (!movingDirection) {
                    direction = DOWN;
                    targetElevator.setDirection(DOWN);
                }                
            }
        }

        // Down direction for elevator iteration (This matches the Up motion, could possibly simplify this program)
        if (targetElevator.getDirection() == ElevatorDirection::DOWN) {

            // creating iterator for the set using the current floor
            auto it = targetElevatorPath.find(currentFloor);

            // reversing iterator to move through the set
            auto reverseIt = std::make_reverse_iterator(it);

            // looping through the set from the target to the beginning using a reversed iterator
            for (; reverseIt != targetElevatorPath.rend(); ++reverseIt) {
                int floor = *reverseIt;

                // if (targetElevator.getDirection() == ElevatorDirection::DOWN) std::cout << "--- Going Down ---" << std::endl;

                // only will execute on floor lower than current floor
                if (floor < targetElevator.getCurrentFloor()) {
                
                    std::cout << "Next Floor: " << floor << std::endl << std::endl;

                    // To simulate time delay going down
                    for (int i = 0; i < targetElevator.getCurrentFloor() - floor; ++i) {
                        std::cout << " . " << std::flush;
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    }

                    // resetting the active button after arriving at the floor
                    targetElevator.getButton(floor).reset();

                    // removing the floor from the path
                    targetElevatorPath.erase(floor); 

                    // Updating path by removing the current floor, setting the current floor,
                    // setting the current direciton, and door status of the elevator
                    controller.updateElevator(targetElevator, elevatorChoice, floor, DOWN);
 
                    // prints out the remaining active buttons
                    std::cout << std::endl << "Active Buttons: " << std::endl;
                    std::cout << "[ ";
                    for (int i : targetElevatorPath) {
                        std::cout << i << " ";
                    }
                    std::cout << "]" << std::endl;


                    // prompt user for additional inputs
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

                    std::cout  << '\n' <<  "--- Elevator Doors Closing ---"  << std::endl <<  std::endl;
                    targetElevator.setDoorStatus(false);

                    movingDirection = true;

                    break;
                
                }

                if (!movingDirection) {
                    direction = UP;
                    targetElevator.setDirection(UP);
                }                
            }

        } 
        
        // Prompt for addtional inputs else set the elevator to idle
        if (targetElevatorPath.empty()) {
            std::cout << "Elevator is IDLE" << std::endl;
            std::cout << "To continue press Y else to quit press N: ";
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

                targetElevator.setDirection(UP);

            } else {
                break;
            }
        }
    }
    std::cout << std::endl << "--- Elevator Sim Complete ---" << std::endl;
    std::cout << std::endl;

    return 0;
}

// TODO:    I/O - change to factory pattern later
