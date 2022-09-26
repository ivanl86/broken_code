#include "controller.h"

Controller::Controller() : bdg{new Building}, tick{0} {}

void Controller::newVisitor()
{
    visitor = new Person(++tick, uty.randRange(LOBBY + 1, HIGHEST_FLOOR));
    bdg->floor[LOBBY].elevatorQueue->enqueue(visitor);
}

void Controller::setCall()
{ bdg->elevator->set(visitor); }

void Controller::unSetCall()
{ bdg->elevator->unset(visitor); }

void Controller::embarkElevator(size_t currentFloor)
{ bdg->elevator->elevator->embark(bdg->floor[currentFloor].elevatorQueue->dequeue()); }

void Controller::disembarkElevator(size_t dstFloor)
{ bdg->floor[dstFloor].floor->embark(bdg->elevator->elevator->disembark()); }

void Controller::queueElevator(size_t currentFloor)
{ bdg->floor[currentFloor].elevatorQueue->enqueue(bdg->floor[currentFloor].floor->disembark()); }