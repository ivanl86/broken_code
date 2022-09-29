#include <iostream>

#include "node.h"
#include "bag.h"
#include "queue.h"
#include "person.h"

int main(int argc, char const *argv[])
{
    Bag *occupants{new Bag};
    Queue *queue{new Queue};

    for(size_t i{1}; i < 11; ++i)
    {
        Person p(i, i);
        occupants->embark(p);
    }
    for(size_t i{1}; i < 11; ++i)
    {
        Person p = occupants->disembark();
        std::cout << p.getID() << ' ';
    }
    std::cout << '\n';
    for(size_t i{1}; i < 11; ++i)
    {
        Person p(i, i);
        queue->enqueue(p);
    }
    for(size_t i{1}; i < 11; ++i)
    {
        Person p = queue->dequeue();
        std::cout << p.getID() << ' ';
    }
    std::cout << '\n';

    return 0;
}
