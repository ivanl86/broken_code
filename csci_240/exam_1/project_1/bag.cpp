#include "bag.h"

Bag::Bag() : head{nullptr} {}

void Bag::embark(Person person)
{
    head = new Node(person, head);
}

Person Bag::disembark()
{
    if (empty())
        throw std::runtime_error("Empty Floor!");

    Node *temp{head};
    Person dptPerson{head->person};

    head = head->nextPerson;

    delete temp;
    return dptPerson;
}

bool Bag::empty()
{ return head == nullptr; }