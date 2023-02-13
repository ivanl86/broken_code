#include "priorityqueue.h"
#include "person.h"
#include "floors.h"
#include "utility.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

enum States {IDLE, PICKUP, DELIVER};
enum Directions {STILL, UP, DOWN};

class Elevator {
public:
    Elevator(Floors floors[] , bool callSet[]);
    void update();
    void setState();
    void toIdle();
    void toPickup();
    void toDeliver();
    void setDirection();
    bool waitingElevator();
    bool waitingAtLobby();
    bool noneWaiting();

private:
    uint64_t currentFloor;
    uint64_t count;
    Floors* floors;
    bool *callSet;

    States currentState;
    Directions currentDirection;
};

#endif