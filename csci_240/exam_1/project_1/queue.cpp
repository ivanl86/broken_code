#include "queue.h"

Queue::Queue()
: frontPtr{nullptr}, backPtr{nullptr} {}


void Queue::enqueue(Person person)
{
    (empty() ? backPtr : backPtr->nextPerson) = new Node(person);
    (empty() ? frontPtr = backPtr : backPtr = backPtr->nextPerson);
}


Person Queue::dequeue()
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


bool Queue::empty()
{ return frontPtr == nullptr; }

