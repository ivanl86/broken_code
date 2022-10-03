#include "controller.h"

Controller::Controller() : bdg{new Building}, visitorCount{0}, curCount{0}, curFloor{LOBBY}, transitCounter{0}, embarkCounter{0}, disembarkCounter{0}, ticks{0}, curDrt{STILL}, curOp{IDLE}
{
    bdg->elevator = new Elevator;
    bdg->elevator->occupants = new Bag;
    bdg->floors = new Floors[HIGHEST_FLOOR + 1];
    for(size_t i{0}; i < HIGHEST_FLOOR + 1; ++i)
    {
        bdg->floors[i].occupants = new Bag;
        bdg->floors[i].elevatorQueue = new Queue;
    }
    for(size_t i{0}; i < HIGHEST_FLOOR + 1; ++i)
    {
        bdg->floors[i].occupants->clear();
        bdg->floors[i].elevatorQueue->clear();
    }
    bdg->elevator->occupants->clear();
}

Controller::~Controller()
{
    delete bdg->floors->occupants;
    delete bdg->floors->elevatorQueue;
    delete bdg->elevator->occupants;
    delete bdg->elevator;
    delete[] bdg->floors;
    delete bdg;
}

void Controller::update()
{
    if (newVisitor())
        newVisitorMsg();
    setCall();

    if (curOp != IN_TRANSIT)
        embarkElevator();

    disembarkElevator();

    exitBuilding();

    updateCurFloor();
    updateCurOp();
    updateCurDrt();
    updateCounter();
    ++ticks;
}

bool Controller::newVisitor()
{
    if (uty.randRange(1, 1000) <= 35)
    {
        Person visitor(++visitorCount, uty.randRange(LOBBY + 1, HIGHEST_FLOOR));
        bdg->floors[LOBBY].elevatorQueue->enqueue(visitor);
        return true;
    }
    return false;
}

void Controller::setCall()
{
    for(size_t i{LOBBY + 1}; i < HIGHEST_FLOOR; ++i)
    {
        if (!bdg->floors[i].occupants->empty())
        {
            if (uty.randRange(1, 1000) <= 15)
            {
                bdg->elevator->call[i] = true;
                queueElevator();
                visitorLeavingMsg();
            }
        }
    }
}

void Controller::unSetCall()
{
    if (bdg->floors[curFloor].elevatorQueue->empty())
        bdg->elevator->call[curFloor] = false;
}

void Controller::embarkElevator()
{
    while (curCount < MAX_CAPACITY && !bdg->floors[curFloor].elevatorQueue->empty())
    {
        bdg->elevator->occupants->embark(bdg->floors[curFloor].elevatorQueue->dequeue());
        curOp = EMBARKING;
        embarkCounter = 10;
        ++curCount;
    }
    if (curFloor > LOBBY)
        unSetCall();
}

void Controller::disembarkElevator()
{
    Bag temp;

    while (!bdg->elevator->occupants->empty())
    {
        Person p = bdg->elevator->occupants->disembark();
        if (p.getDst() == curFloor)
        {
            bdg->floors[curFloor].occupants->embark(p);
            visitorEnterFloorMsg();
            curOp = DISEMBARKING;
            disembarkCounter = 10;
            --curCount;
        }
        else
            temp.embark(p);
    }

    while (!temp.empty())
        bdg->elevator->occupants->embark(temp.disembark());
}

void Controller::queueElevator()
{
    for(size_t i{LOBBY + 1}; i <= HIGHEST_FLOOR; ++i)
        if (bdg->elevator->call[i])
            bdg->floors[curFloor].elevatorQueue->enqueue(bdg->floors[curFloor].occupants->disembark());
}

void Controller::exitBuilding()
{
    if (!bdg->floors[LOBBY].occupants->empty())
    {
        bdg->floors[LOBBY].occupants->clear();
        exitBuildingMsg();
    }
}

void Controller::newVisitorMsg()
{
    std::cout << "A new visitor has arrived!\n";
}

void Controller::visitorEnterFloorMsg()
{
    std::cout << "A visitor entered floor " << curFloor << '\n';
}

void Controller::visitorLeavingMsg()
{ std::cout << "A visitor is ready to leave!\n"; }



void Controller::exitBuildingMsg()
{ std::cout << "A visitor(s) has left!\n"; }

void Controller::updateCurFloor()
{
    if (transitCounter == 0 && curDrt == UP)
    {
        ++curFloor;
    }
    if (transitCounter == 0 && curDrt == DOWN)
    {
        --curFloor;
    }
}

void Controller::updateCurDrt()
{
    Bag temp;
    size_t highestDst{};
    size_t highestCall{};
    bool hasCall{false};

    for(size_t i{LOBBY + 1}; i < HIGHEST_FLOOR; ++i)
    {
        if (bdg->elevator->call[i])
        {
            highestCall = i;
            hasCall = true;
        }
    }

    while (!bdg->elevator->occupants->empty())
    {
        Person p = bdg->elevator->occupants->disembark();
        if (p.getDst() > highestDst)
            highestDst = p.getDst();

        temp.embark(p);
    }

    while (!temp.empty())
        bdg->elevator->occupants->embark(temp.disembark());

    if (curOp == IN_TRANSIT && curCount < MAX_CAPACITY && (highestDst > curFloor || highestCall > highestCall))
        curDrt = UP;
    else if (curOp == IN_TRANSIT && (highestDst <= curFloor || highestCall <= highestCall))
        curDrt = DOWN;
    else
        curDrt = STILL;

    /*
        if (((!hasCall && bdg->floors[LOBBY].elevatorQueue->empty()) || curOp == DISEMBARKING || curOp == EMBARKING))
        {
            curDrt = STILL;
        }
        else if (curFloor == LOBBY && bdg->floors[LOBBY].elevatorQueue->empty() && curDrt != UP && !bdg->elevator->occupants->empty())
        {
            curDrt = UP;
        }
        else if ((highestCall < curFloor || curFloor >= HIGHEST_FLOOR) && curDrt != DOWN)
        {
            curDrt = DOWN;
        }
    */
}

void Controller::updateCurOp()
{
    Bag temp;

    if (embarkCounter == 0 && disembarkCounter == 0 && transitCounter == 0)
    {
        for (size_t i{LOBBY + 1}; i <= HIGHEST_FLOOR; ++i)
        {
            if (bdg->elevator->call[i])
            {
                curOp = IN_TRANSIT;
                transitCounter = 4;
            }
        }

        while (!bdg->elevator->occupants->empty())
        {
            Person p = bdg->elevator->occupants->disembark();
            if (p.getDst() != curFloor)
            {
                bdg->floors[curFloor].occupants->embark(p);
                curOp = IN_TRANSIT;
                transitCounter = 4;
            }
            temp.embark(p);
        }

        while (!temp.empty())
            bdg->elevator->occupants->embark(temp.disembark());
    }

    /*
    Bag temp;

    if (bdg->elevator->call[curFloor] && !bdg->elevator->occupants->empty())
    {
        curOp = DISEMBARKING;
        disembarkCounter = 10;
        return;
    }

    while (!bdg->elevator->occupants->empty())
    {
        Person p = bdg->elevator->occupants->disembark();
        if (p.getDst() == curFloor)
        {
            curOp = EMBARKING;
            embarkCounter = 10;
        }
        temp.embark(p);
    }

    while (!temp.empty())
        bdg->elevator->occupants->embark(temp.disembark());
    */
}

void Controller::updateCounter()
{
    if (transitCounter > 0 && curOp == IN_TRANSIT)
        --transitCounter;
    if (embarkCounter > 0 && curOp == EMBARKING)
        --embarkCounter;
    if (disembarkCounter > 0 && curOp == DISEMBARKING)
        --disembarkCounter;
}