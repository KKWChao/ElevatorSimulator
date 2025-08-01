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
    
    std::cout << '\n' << "--- Elevator Doors Closing ---" << '\n' << std::endl;
    targetElevator.setDoorStatus(false);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    while (!targetElevatorPath.empty()) {
        if (targetElevator.getDirection() == UP) {
                                                  
            for (int floor : targetElevatorPath) {
                bool movingDirection = false;

                if (floor > targetElevator.getCurrentFloor()) {
                    std::cout << "--- Going UP ---" << std::endl;

                    std::cout << "Next Floor: " << floor << std::endl << std::endl;

                    for (int i = 0; i < floor - targetElevator.getCurrentFloor(); ++i) {
                        std::cout << " . " << std::flush;
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    }
                    


                    std::cout << std::endl << std::endl << "Arrived at floor " << floor << std::endl;
                    std::cout << std::endl <<"--- Elevator Doors Opening ---" << '\n' << std::endl;

                    targetElevator.setDoorStatus(true); 
                    targetElevator.setCurrentFloor(floor);
                    targetElevator.setDirection(UP);

                    targetElevator.getButton(floor).reset();
                    targetElevatorPath.erase(floor); 
 
                    std::cout << std::endl << "Active Buttons: " << std::endl;
                    std::cout << "[ ";
                    for (int i : targetElevatorPath) {
                        std::cout << i << " ";
                    }
                    std::cout << "]" << std::endl;




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

                if (!movingDirection) {
                    direction = DOWN;
                    targetElevator.setDirection(DOWN);
                }                
            }
        }

        else if (targetElevator.getDirection() == DOWN) {
            // fix this
            // for (int floor : targetElevatorPath) {

            // create the reverse iterator with the location of the current floor
            auto it = targetElevatorPath.lower_bound(targetElevator.getCurrentFloor());
            auto reverseIt = std::make_reverse_iterator(it);

            for (; reverseIt != targetElevatorPath.rend(); ++reverseIt) {
                int floor = *reverseIt;

                bool movingDirection = false;

                if (floor < targetElevator.getCurrentFloor()) {
                    std::cout << "--- Going Down ---" << std::endl;

                    std::cout << "Next Floor: " << floor << std::endl << std::endl;

                    for (int i = 0; i < targetElevator.getCurrentFloor() - floor; ++i) {
                        std::cout << " . " << std::flush;
                        std::this_thread::sleep_for(std::chrono::milliseconds(150));
                    }
                    


                    std::cout << std::endl << std::endl << "Arrived at floor " << floor << std::endl;
                    std::cout << std::endl <<"--- Elevator Doors Opening ---" << '\n' << std::endl;

                    targetElevator.setDoorStatus(true); 
                    targetElevator.setCurrentFloor(floor);
                    targetElevator.setDirection(DOWN);

                    targetElevator.getButton(floor).reset();
                    targetElevatorPath.erase(floor); 
 
                    // TODO:    can update method to print active buttons on the elevator
                    std::cout << std::endl << "Active Buttons: " << std::endl;
                    std::cout << "[ ";
                    for (int i : targetElevatorPath) {
                        std::cout << i << " ";
                    }
                    std::cout << "]" << std::endl;




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

                if (!movingDirection) {
                    direction = UP;
                    targetElevator.setDirection(UP);
                }                
            }

        } else {
            std::cout << "ERROR" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl << "--- Elevator Sim Complete ---" << std::endl;
    std::cout << std::endl;

    return 0;
}

// TODO:    I/O - change to factory pattern later
