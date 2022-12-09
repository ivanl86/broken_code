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

Person Queue::front()
{ return frontPtr->person; }

bool Queue::empty()
{ return frontPtr == nullptr; }

void Queue::clear()
{
    Node *temp{frontPtr};

    if (frontPtr != nullptr)
        throw std::runtime_error("Empty Queue!");

    while (frontPtr != nullptr)
    {
        frontPtr = frontPtr->nextPerson;
        delete temp;
        temp = frontPtr;
    }
    backPtr = nullptr;
}