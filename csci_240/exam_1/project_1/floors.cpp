#include <stdexcept>

#include "floors.h"

Floors::Floors() : floor{nullptr} {}

void Floors::arrive(Person person)
{
    floor = new Node(person, floor);
}

Person Floors::depart()
{
    if (empty())
        throw std::runtime_error("Empty Floor!");

    Node *temp{floor};
    Person dptPerson{floor->person};

    floor = floor->nextPerson;

    delete temp;
    return dptPerson;
}

bool Floors::empty()
{ return floor == nullptr; }