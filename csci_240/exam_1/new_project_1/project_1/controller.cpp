#include "controller.h"

Controller::Controller() : ticks{0}, arrivalCount{0}, prvFloor{1}
{}

void Controller::play()
{
    bdg.elevator.updateCounter();

    if (uty.randRange(1, 1000) <= 35)
        arrival();

    if (bdg.elevator.getState() == IDLE || bdg.elevator.getState() == DISEMBARKING)
        enterFloor();

    if (bdg.elevator.getState() == IDLE || bdg.elevator.getState() == EMBARKING)
        enterElevator();

    // setCall();

    bdg.elevator.updateCurFloor();
    bdg.elevator.updatePrvState();
    bdg.elevator.updateState();
    printElevatorState();
    printCurFloor();

    departure();
    ++ticks;
}

void Controller::setCall()
{
    for(size_t i{LOBBY + 1}; i < TOP_FLOOR; ++i)
    {
        if (uty.randRange(1, 1000) <= 15 && !bdg.floors[i].occupants.empty())
        {
            bdg.elevator.calls[i] = true;
            enterQueue(i);
            uty.enterQueueMsg();
        }
    }
}

void Controller::arrival()
{
    //Person p(++arrivalCount, uty.randRange(LOBBY + 1, TOP_FLOOR));
    Person p(++arrivalCount, uty.randRange(LOBBY + 1, 8));
    bdg.floors[LOBBY].queue.enqueue(p);
    uty.arrivalMsg();
}

void Controller::enterFloor()
{
    Bag temp;
    Person p;

    while (!bdg.elevator.occupants.empty())
    {
        p = bdg.elevator.occupants.disembark();
        if (p.getDst() == bdg.elevator.curFloor)
        {
            bdg.floors[bdg.elevator.curFloor].occupants.embark(p);
            bdg.elevator.setDisembarkCounter();
            --bdg.elevator.pCount;
        }
        else
            temp.embark(p);
    }
    while (!temp.empty())
        bdg.elevator.occupants.embark(temp.disembark());
}

void Controller::enterQueue(size_t f)
{
    bdg.floors[f].queue.enqueue(bdg.floors[f].occupants.disembark());
}

void Controller::enterElevator()
{
    while (!bdg.floors[bdg.elevator.curFloor].queue.empty() && bdg.elevator.pCount < MAX_CAPACITY)
    {
        bdg.elevator.occupants.embark(bdg.floors[bdg.elevator.curFloor].queue.dequeue());
        bdg.elevator.setEmbarkCounter();
        ++bdg.elevator.pCount;
    }
}

void Controller::departure()
{
    if (!bdg.floors[LOBBY].occupants.empty())
    {
        bdg.floors[LOBBY].occupants.disembark();
        uty.departBdgMsg();
    }
}

void Controller::printElevatorState()
{
    ticks %= 10;
    if (bdg.elevator.curFloor == LOBBY && ticks == 0 && (bdg.elevator.getState() != GOING_UP || bdg.elevator.getState() != GOING_DOWN))
        std::cout << "The elevator is at lobby now\n";
    if (bdg.elevator.getState() == IDLE && ticks == 0)
        std::cout << "The elevator is currently idle\n";
    if (bdg.elevator.getState() == EMBARKING && bdg.elevator.getEmbarkCounter() == 10)
        std::cout << "People are embarking the elevator\n";
    if (bdg.elevator.getState() == DISEMBARKING && bdg.elevator.getDisembarkCounter() == 10)
        std::cout << "People are disembarking the elevator\n";
    if (bdg.elevator.getState() == GOING_UP && bdg.elevator.getGoUpCounter() == 4)
        std::cout << "The elevator is currently going up\n";
    if (bdg.elevator.getState() == GOING_DOWN && bdg.elevator.getGoDownCounter() == 4)
        std::cout << "The elevator is currently going down\n";
}

void Controller::printCurFloor()
{
    if (prvFloor != bdg.elevator.curFloor && bdg.elevator.curFloor > LOBBY)
        std::cout << "The elevator is at floor " << bdg.elevator.curFloor << '\n';
    prvFloor = bdg.elevator.curFloor;
}