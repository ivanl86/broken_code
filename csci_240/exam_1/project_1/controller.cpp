#include "controller.h"

Controller::Controller(size_t lobby, size_t highestFloor, size_t maxCapacity) : bdg{new Building}, lobby{lobby},
                                                                  highestFloor{highestFloor}, maxCapacity{maxCapacity}
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

bool Controller::newVisitor()
{
    if (uty.randRange(1, 1000) <= 35)
    {
        Person visitor(++visitorCount, uty.randRange(LOBBY + 1, highestFloor));
        bdg->floors[LOBBY].elevatorQueue->enqueue(visitor);
        return true;
    }
    return false;
}

void Controller::setCall()
{
    if (uty.randRange(1, 1000) >= 15)
        return;

    size_t randFloor{uty.randRange(LOBBY + 1, HIGHEST_FLOOR)};

    for(size_t i{LOBBY + 1}; i < HIGHEST_FLOOR; ++i)
    {
        if (!bdg->floors[i].occupants->empty())
        do
        {
            if (!bdg->floors[randFloor].occupants->empty() && call[randFloor] != true)
            {
                call[randFloor] = true;
                queueElevator(randFloor);
                visitorLeavingMsg();
                return;
            }
            randFloor = uty.randRange(LOBBY, HIGHEST_FLOOR);
        } while (true);
    }
}

void Controller::unSetCall(size_t curFloor)
{
    if (bdg->floors[curFloor].elevatorQueue->empty())
        call[curFloor] = false;
}

void Controller::embarkElevator(size_t curFloor)
{
    while (curCount < maxCapacity && !bdg->floors[curFloor].elevatorQueue->empty())
    {
        bdg->elevator->occupants->embark(bdg->floors[curFloor].elevatorQueue->dequeue());
        ++curCount;
    }
    if (curFloor > LOBBY)
        unSetCall(curFloor);
}

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
{
    for(size_t i{2}; i <= highestFloor; ++i)
        if (call[i])
            bdg->floors[curFloor].elevatorQueue->enqueue(bdg->floors[curFloor].occupants->disembark());
}

void Controller::exitBuilding(size_t curFloor)
{
    bdg->floors[curFloor].occupants->clear();
    exitBuildingMsg();
}

void Controller::newVisitorMsg()
{ std::cout << "A new visitor has arrived!\n"; }

void Controller::visitorLeavingMsg()
{ std::cout << "A visitor is ready to leave!\n"; }

void Controller::exitBuildingMsg()
{ std::cout << "A visitor(s) has left!\n"; }