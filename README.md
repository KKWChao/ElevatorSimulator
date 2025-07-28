# Project 1: Elevator Simulation

### Overview

In this project, your team will design and implement a simulation of an elevator system using C++. 
The simulation should model the behavior of a multi-floor building with one or more elevators, handling 
user requests, managing elevator movement, and simulating real-time actions. The main goal is to 
practice object-oriented programming (OOP), system design, and interactive console input/output.

### Requirements

- Apply object-oriented principles (classes, inheritance, polymorphism).
- Practice modular design and system decomposition.
- Implement time-based or event-driven simulations.
- Strengthen skills in C++ syntax, control flow, and basic file I/O.

### Functional Requirements

##### 1. Building Configuration:

    - Configurable number of floors (e.g., 5 to 20).
    - One or more elevators.

##### 2. Elevator Behavior:

    - Moves up/down between floors.
    - Responds to user requests (floor buttons and external up/down calls).
    - Opens/closes doors.
    - Can be idle if no requests.

##### 3. Request System:

    - Simulate people pressing buttons on different floors.
    - Handle multiple requests efficiently.

##### 4. Console Interface:

    - Display current state of elevators (floor, direction, status).
    - Allow user to input requests during runtime.

##### 5. Timing/Simulation:

    - Time-based or step-based simulation.
    - Delays between actions for realism.

##### Optional Enhancements (Bonus):

    - Prioritize requests based on proximity or direction.
    - Add capacity limits to elevators.
    - Implement a basic GUI using a library like SFML or ncurses (optional).
    - Add elevator sound or floor announcements.

##### Deliverables:

    - Source code in C++ (with comments).
    - A README file explaining:
    - How to compile and run the simulation
    - Team members and their roles
    - Features implemented
    - A short demo video (max 3 minutes) showing the simulation in action.

### Installation Instructions

#### Build Instructions

```
// Run the commands in the project directory
mkdir build && cd build
cmake ..
cmake build .

```

#### Running the Program

```
// In the project directory
cd build
./Project

```
