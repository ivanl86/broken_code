#include "controller.h"

Controller::Controller() : bdg{new Building}, visitorCount{0}, goUp{true}
{
    bdg->elevator = new Elevator;
    bdg->floors = new Floors[HIGHEST_FLOOR + 1];
    bdg->floors->occupants = new Bag;
    bdg->floors->elevatorQueue = new Queue;
    bdg->elevator = new Elevator;
}

Controller::~Controller()
{
    delete bdg->floors->occupants;
    delete bdg->floors->elevatorQueue;
    delete bdg->elevator;
    delete[] bdg->floors;
    delete bdg;
}

void Controller::newVisitor()
{
    Person visitor(++visitorCount, uty.randRange(LOBBY + 1, HIGHEST_FLOOR));
    bdg->floors[LOBBY].elevatorQueue->enqueue(visitor);
}

void Controller::setCall()
{ bdg->elevator->set(visitor); }

void Controller::unSetCall()
{ bdg->elevator->unset(visitor); }

void Controller::embarkElevator(size_t curFloor)
{ bdg->elevator->occupants->embark(bdg->floors[curFloor].elevatorQueue->dequeue()); }

void Controller::disembarkElevator(size_t dstFloor)
{ bdg->floors[dstFloor].occupants->embark(bdg->elevator->occupants->disembark()); }

void Controller::queueElevator(size_t curFloor)
{ bdg->floors[curFloor].elevatorQueue->enqueue(bdg->floors[curFloor].occupants->disembark()); }