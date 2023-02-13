#include "elevator.h"

Elevator::Elevator(Floors floors[], bool callSet[])
    : floors{floors}, callSet{callSet}, currentFloor{LOBBY}, count{0}, currentState{IDLE}, currentDirection{STILL} {}

void Elevator::update() {}

void Elevator::toIdle() {
    currentState = IDLE;
}

void Elevator::toPickup() {
    currentState = PICKUP;
}

void Elevator::toDeliver() {
    currentState = DELIVER;
}

void Elevator::setState() {
    // 
}

void Elevator::setDirection() {
    if (currentState == IDLE) {
        currentDirection = STILL;
    }
    else if (currentState == PICKUP) {
        // 
    }
    else {
        // 
    }
}

bool Elevator::waitingElevator() {
    for (size_t i{1}; i < FLOOR_QTY; ++i) {
        if (callSet[i])
            return true;
    }
    return false;
}

bool Elevator::waitingAtLobby() {
    return callSet[LOBBY];
}

bool Elevator::noneWaiting() {
    return (!waitingElevator() && !waitingAtLobby());
}