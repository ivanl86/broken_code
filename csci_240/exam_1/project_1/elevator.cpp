#include "elevator.h"

Elevator::Elevator() : call{}, curCapacity{0}, elevator{new Bag}
{}

void Elevator::set(Person *person)
{ call[person->getDst()] = true; }

void Elevator::unset(Person *person)
{ call[person->getDst()] = false; }

void Elevator::increCapacity()
{ ++curCapacity; }

void Elevator::decreCapacity()
{ --curCapacity; }

size_t Elevator::getCurCapacity()
{ return curCapacity; }

void Elevator::clearCapacity()
{ curCapacity = 0; }