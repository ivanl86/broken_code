#include "common.h"

#include "floor.h"
#include "person.h"

bool Floor::update()
{
    if (isProbable(EXIT_PROBABILITY))
    {
        Person p = occupants.grab();
        occupants.remove(p);
        elevQueue.enqueue(p);
    }

    return !elevQueue.empty();
}

void Floor::add(const Person &p)
{ occupants.add(p); }

Person Floor::get()
{ return elevQueue.dequeue(); }

void Floor::addElevQueue(const Person &p)
{
    elevQueue.enqueue(p);
}