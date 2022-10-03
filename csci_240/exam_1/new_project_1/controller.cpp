#include "controller.h"

Controller::Controller() : pplCount{0}, ticks{0}
{}

Controller::~Controller()
{}

void Controller::arrival()
{
    person = new Person(ticks, uty.randRange(LOBBY + 1, TOP_FLOOR));
    bdg->floors[LOBBY]->queue->enqueue(person);
    delete person;
}