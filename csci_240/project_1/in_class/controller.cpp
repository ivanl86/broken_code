#include "common.h"
#include "controller.h"

Controller::Controller() : nextId{0}
{}

void Controller::start()
{
    while (true)
    {
        if (isProbable(NEW_PERSON_PROBABILITY))
            bdg.add({nextId++, randRange(1, FLOOR_QTY - 1)});

        bdg.update();
    }
}