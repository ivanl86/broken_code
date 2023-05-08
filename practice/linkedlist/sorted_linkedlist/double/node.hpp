#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:

public:
    T item;
    Node<T>* prev;
    Node<T>* next;

    Node(T item);
    Node(T item, Node<T>* prev, Node<T>* next);
};

#include "node.tpp"

#endif  /* NODE_H */