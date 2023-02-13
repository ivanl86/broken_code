#include "floors.h"

bool Floors::update() {
    ArrayBag<Person> bag;
    Person p;
    while (occupants.size() >= 0)
    {
        p = occupants.peek();
        if (isProbable(EXIT_PROBABILITY)) {
            removeOccupant(p);
            addElevatorQueue(p);
        }
        else {
            bag.add(removeOccupant(p));
        }
    }
    occupants = bag;

    return !(elevatorQueue.empty());
}

void Floors::addElevatorQueue(const Person& p) {
    elevatorQueue.enqueue(p);
}

Person Floors::removeElevatorQueue() {
    return elevatorQueue.dequeue();
}

void Floors::addOccupant(const Person& p) {
    occupants.add(p);
}

Person Floors::removeOccupant(const Person& p) {
    occupants.remove(p);
    return p;
}