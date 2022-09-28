#include "controller.h"

Controller::Controller() : bdg{new Building}, visitorCount{0}, goUp{true}
{
    bdg->elevator = new Elevator;
    bdg->floors = new Floors[HIGHEST_FLOOR + 1];
    for(size_t i{0}; i < HIGHEST_FLOOR + 1; ++i)
    {
        bdg->floors[i].occupants = new Bag;
        bdg->floors[i].elevatorQueue = new Queue;
    }
    //bdg->floors->occupants = new Bag;
    //bdg->elevator = new Elevator;
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

void Controller::setCall(size_t curFloor)
{
    size_t randFloor{};
    do
    {
        randFloor = uty.randRange(LOBBY, HIGHEST_FLOOR);
        if (!bdg->floors[curFloor].occupants->empty())
            {
                call[randFloor] = true;
                return;
            }
    } while (true);
    
    
    
}

void Controller::unSetCall()
{ bdg->elevator->unset(visitor); }

void Controller::embarkElevator(size_t curFloor)
{ bdg->elevator->occupants->embark(bdg->floors[curFloor].elevatorQueue->dequeue()); }

void Controller::disembarkElevator(size_t curFloor)
{
    //bdg->floors[dstFloor].occupants->embark(bdg->elevator->occupants->disembark());
    Bag temp;
    while (!bdg->elevator->occupants->empty())
    {
        Person p = bdg->elevator->occupants->disembark();
        if (p.getDst() == curFloor)
            bdg->floors[curFloor].occupants->embark(p);
        else
            temp.embark(p);
    }
    while (!temp.empty())
        bdg->elevator->occupants->embark(temp.disembark());
}

void Controller::queueElevator(size_t curFloor)
{ bdg->floors[curFloor].elevatorQueue->enqueue(bdg->floors[curFloor].occupants->disembark()); }