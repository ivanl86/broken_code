#include "elevator.h"

Elevator::Elevator(Floors floors[], bool callSet[])
    : floors{floors}, callSet{callSet}, currentFloor{LOBBY}, count{0}, currentState{IDLE}, currentDirection{STILL} {}

void Elevator::update() {
    switch (currentState)
    {
    case IDLE:
        toIdle();
        break;
    case PICKUP:
        toPickup();
        break;
    case DELIVER:
        toDeliver();
        break;
    }
}

void Elevator::toIdle() {
    currentDirection = STILL;

    if (noneWaiting())
        return;
    else
        currentState = PICKUP;
}

void Elevator::toPickup() {
    if (currentFloor == LOBBY)
        currentDirection == UP;
    else if (currentFloor < callSet[floorWaiting()])
        currentDirection == UP;
    else
        currentDirection == DOWN;
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

int Elevator::floorWaiting() {
    for(size_t i{TOP_FLOOR}; i >= LOBBY; --i) {
        if (callSet[i])
            return i;
    }
    return -1;
}