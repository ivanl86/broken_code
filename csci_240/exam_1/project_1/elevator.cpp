#include "elevator.h"

Elevator::Elevator() : call{}, curCount{0}, occupants{new Bag}
{
    for(size_t i{1}; i <= HIGHEST_FLOOR; ++i)
    {
        call[i] = false;
    }
    
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