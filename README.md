# Elevator Simulation

## Overview
This is a simple console-based elevator simulation written in C++. 
The program simulates an elevator system where users can interactively call elevators, choose floors, and observe elevator movement and door behavior.

## Features

#### Object oriented design
- Modular classes: Elevator, controller, userInput classes
- Encapsulation: For statuses, paths, directions etc

#### Step/Time Based Simulation
- Uses sleep for delays and steps for each floor
- Responds to user input during runtime

#### Additional Information
- Allows the user to configure building floor range and number of elevators.

- Supports selection of a specific elevator.

- Simulates elevator travel between floors.

- Allows real-time floor button input during elevator operation.

- Displays elevator direction and active floor buttons.

- Simulates delays and door open/close behavior.

## Installation Instructions

#### Prerequisites
```
g++ -std=c++17 -o elevator_sim main.cpp

```

#### Build Instructions

```
// Run the commands in the ElevatorSim directory
mkdir build && cd build
cmake ..
cmake build .

```

#### Running the Program

```
// In the ElevatorSim directory
cd build
./ElevatorSim

```
