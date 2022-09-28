#include "controller.h"

Controller::Controller() : bdg{new Building}, tick{0}, goUp{true} {}

void Controller::newVisitor()
{
    visitor = new Person(++tick, uty.randRange(LOBBY + 1, HIGHEST_FLOOR));
    bdg->floors[LOBBY].elevatorQueue->enqueue(visitor);
}

void Controller::setCall()
{ bdg->elevator->set(visitor); }

void Controller::unSetCall()
{ bdg->elevator->unset(visitor); }

void Controller::embarkElevator(size_t currentFloor)
{ bdg->elevator->occupants->embark(bdg->floors[currentFloor].elevatorQueue->dequeue()); }

void Controller::disembarkElevator(size_t dstFloor)
{ bdg->floors[dstFloor].occupants->embark(bdg->elevator->occupants->disembark()); }

void Controller::queueElevator(size_t currentFloor)
{ bdg->floors[currentFloor].elevatorQueue->enqueue(bdg->floors[currentFloor].occupants->disembark()); }