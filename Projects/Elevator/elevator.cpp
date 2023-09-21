#include "elevator.h"

Elevator::Elevator() : curFloor{LOBBY}, pCount{0}, calls{}, state{IDLE}, flow{STILL}, prvState{IDLE}, embarkCounter{0}, disembarkCounter{0}, goUpCounter{0}, goDownCounter{0}
{}

void Elevator::updateCounter()
{
    if (embarkCounter > 0)
        --embarkCounter;
    if (disembarkCounter > 0)
        --disembarkCounter;
    if (goUpCounter > 0)
        --goUpCounter;
    if (goDownCounter > 0)
        --goDownCounter;
}

void Elevator::updateCurFloor()
{
    if (state == GOING_UP && goUpCounter == 0)
        ++curFloor;
    if (state == GOING_DOWN && goDownCounter == 0)
        --curFloor;
}

void Elevator::updateFlow()
{
    size_t dstFloor{setDstFloor()};

    if (curFloor == LOBBY && flow == DOWN && zeroCounter())
        flow = STILL;
    else if (curFloor == LOBBY && flow == STILL && curFloor < TOP_FLOOR && zeroCounter())
        flow = UP;
    else if (flow == UP && dstFloor > curFloor && curFloor < TOP_FLOOR && zeroCounter())
        flow = UP;
    else if (curFloor == TOP_FLOOR && curFloor > LOBBY)
        flow = DOWN;
    else if (dstFloor <= curFloor && occupants.empty() && curFloor > LOBBY)
        flow = DOWN;
}

void Elevator::updateState()
{
    size_t dstFloor{setDstFloor()};

    if (zeroCounter() && state != IDLE)
    { state = IDLE; }
    else if (flow == UP && state == IDLE && zeroCounter() && !this->occupants.empty())
    {
        state = GOING_UP;
        setGoUpCounter();
    }
    else if (flow == UP && state == IDLE && zeroCounter() && occupants.empty() && dstFloor > curFloor)
    {
        state = GOING_UP;
        setGoUpCounter();
    }
    else if (flow == DOWN && state == IDLE && zeroCounter())
    {
        state = GOING_DOWN;
        setGoDownCounter();
    }
    else if (embarkCounter > 0)
        state = EMBARKING;
    else if (disembarkCounter > 0)
        state = DISEMBARKING;
}

bool Elevator::zeroCounter()
{ return (embarkCounter == 0 && disembarkCounter == 0 && goUpCounter == 0 && goDownCounter == 0); }

void Elevator::setCall(size_t idx)
{ calls[idx] = true; }

void Elevator::unsetCall(size_t idx)
{ calls[idx] = false; }

size_t Elevator::setDstFloor()
{
    for(size_t i{TOP_FLOOR}; i > LOBBY; --i)
        if (calls[i])
            return i;

    return LOBBY;
}

void Elevator::setEmbarkCounter()
{ embarkCounter = 10; }

void Elevator::setDisembarkCounter()
{ disembarkCounter = 10; }

void Elevator::setGoUpCounter()
{ goUpCounter = 4; }

void Elevator::setGoDownCounter()
{ goDownCounter = 4; }

State Elevator::getState()
{ return state; }

Flow Elevator::getFlow()
{ return flow; }

size_t Elevator::getEmbarkCounter()
{ return embarkCounter; }
size_t Elevator::getDisembarkCounter()
{ return disembarkCounter; }
size_t Elevator::getGoUpCounter()
{ return goUpCounter; }
size_t Elevator::getGoDownCounter()
{ return goDownCounter; }
