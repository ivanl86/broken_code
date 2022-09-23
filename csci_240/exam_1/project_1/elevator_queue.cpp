#include "elevator_queue.h"

ElevatorQueue::ElevatorQueue()
: frontPtr{nullptr}, backPtr{nullptr} {}


void ElevatorQueue::enqueue(Person person)
{
    (empty() ? backPtr : backPtr->nextPerson) = new Node(person);
    (empty() ? frontPtr = backPtr : backPtr = backPtr->nextPerson);
}


Person ElevatorQueue::dequeue()
{
    if (empty())
        throw std::runtime_error("Empty Queue!");

    Node *temp{frontPtr};
    Person dptPerson{frontPtr->person};
    frontPtr = frontPtr->nextPerson;

    delete temp;

    if (empty())
        backPtr = nullptr;

    return dptPerson;
}


bool ElevatorQueue::empty()
{ return frontPtr == nullptr; }

