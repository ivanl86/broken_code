#include <functional>
#include "elevator.h"

Elevator::Elevator(Floor floors[], bool callset[])
    : floors{floors}, callset{callset}, currentFloor{LOBBY},
      currentDir{STILL}, currentState{IDLE} {}


void Elevator::update()
{
    switch (currentState)
    {
    case IDLE:
        idle();
        break;
    case DELIVER:
        deliver();
        break;
    case PICKUP:
        pickup();
        break;
    }
}

void Elevator::idle()
{
    currentDir = STILL;
    if (noneWaiting())
        return;
    if (currentFloor == LOBBY)
        currentState = (callset[LOBBY]) ? DELIVER : PICKUP;
    else
        currentState = (waiting(LOBBY + 1, TOP_FLOOR) >= 0) ? PICKUP : DELIVER;
}

void Elevator::deliver()
{}

void Elevator::pickup()
{}

bool Elevator::noneWaiting()
{
    for(size_t i{0}; i < FLOOR_QTY; ++i)
        if (callset[i])
            return false;

    return true;
}

bool Elevator::noneLobbyWaiting()
{
    for(size_t i{LOBBY + 1}; i < FLOOR_QTY; ++i)
        if (callset[i])
            return true;

    return false;
}

size_t Elevator::waiting(size_t floor)
{ return callset[floor] ? floor : -1; }

size_t Elevator::waiting(size_t start, size_t end)
{
    int step{(start > end) ? -1 : 1};

    while (start != end + step) // while (start != end)
    {
        if (callset[start])
            return start;
        start += step;
    }

    return -1; // return (callset[start]) ? start : -1
}