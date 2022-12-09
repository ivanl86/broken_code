#include "elevator.h"

Elevator::Elevator() : curCount{0}, curFloor{0}
{
    for(size_t i{0}; i <= HIGHEST_FLOOR; ++i)
        call[i] = false;
}

void Elevator::set(Person *person)
{ call[person->getDst()] = true; }

void Elevator::unset(Person *person)
{ call[person->getDst()] = false; }

void Elevator::increCapacity()
{ ++curCount; }

void Elevator::decreCapacity()
{ --curCount; }

size_t Elevator::getCurCapacity()
{ return curCount; }

void Elevator::clearCapacity()
{ curCount = 0; }