#include "elevator.h"

Elevator::Elevator() : call{false}
{}

void Elevator::set(Person person)
{ call[person.getDst()] = true; }

void Elevator::unset(Person person)
{ call[person.getDst()] = false; }