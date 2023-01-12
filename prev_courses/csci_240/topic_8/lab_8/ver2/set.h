#include <list>
#include <cstdint>

#ifndef SET_H
#define SET_H

template<typename T>
class Set
{   
    // inserts an item into the set. Returns true if success or false otherwise.
    // It will be unsuccessful if an equal item already exists.
    bool insert(item) = 0;

    // removes an item, returns true if success or false otherwise
    bool erase(item) = 0;

    // removes an item at a certain position where 0 <= position <= size - 1,
    // returns true if success or false otherwise
    bool erase(position) = 0;

    // removes all elements from the set
    void clear() = 0;

    // returns true if empty or false otherwise
    bool empty() = 0;

    // number of elements in the set
    uint64_t size() = 0;

    // returns a ordered sequence of the set items
    std::list<T>* toSequence() = 0;

    // returns a set created from the union of A and B
    Set union(Set A, Set B) = 0;

    // returns a set created from the intersection of A and B
    Set intersection(Set A, Set B) = 0;
};

#endif  /* SET_H */