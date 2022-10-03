#include "elevator.h"

Elevator::Elevator() : curFloor{LOBBY}, pCount{0}, calls{}, state{IDLE}, prvState{IDLE}, embarkCounter{0}, disembarkCounter{0}, goUpCounter{0}, goDownCounter{0}
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

void Elevator::updatePrvState()
{
    size_t dstFloor{setDstFloor()};

    if (curFloor == LOBBY && zeroCounter())
        prvState = GOING_UP;
    if (occupants.empty() && zeroCounter() && prvState == GOING_UP && state == IDLE)
        prvState = IDLE;
    if (prvState == IDLE && dstFloor > curFloor)
        prvState = GOING_UP;
    if (prvState == IDLE && dstFloor <= curFloor)
        prvState = GOING_DOWN;
}

void Elevator::updateState()
{
    size_t dstFloor{setDstFloor()};

    if (zeroCounter() && state != IDLE)
    { state = IDLE; }
    else if (prvState == GOING_UP && state == IDLE && !occupants.empty() && zeroCounter())
    {
        state = GOING_UP;
        setGoUpCounter();
    }
    else if (prvState == GOING_UP && state == IDLE && dstFloor > curFloor && zeroCounter())
    {
        state = GOING_UP;
        setGoUpCounter();
    }
    else if (prvState == GOING_DOWN && state == IDLE && dstFloor < curFloor && zeroCounter())
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

State Elevator::getPrvState()
{ return prvState; }

size_t Elevator::getEmbarkCounter()
{ return embarkCounter; }
size_t Elevator::getDisembarkCounter()
{ return disembarkCounter; }
size_t Elevator::getGoUpCounter()
{ return goUpCounter; }
size_t Elevator::getGoDownCounter()
{ return goDownCounter; }
