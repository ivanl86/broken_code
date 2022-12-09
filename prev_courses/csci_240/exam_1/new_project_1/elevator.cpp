#include "elevator.h"

Elevator::Elevator() : call{}, count{0}, drt{STILL}, state{IDLE}, occupants{new Bag}
{}
