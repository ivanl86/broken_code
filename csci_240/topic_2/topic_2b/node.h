#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    T item;
    Node<T> *nextItem;

    Node(T item, Node<T> *nextItem) : item{item}, nextItem{nextItem} {}
    Node(T item) : Node<T>(item, nullptr) {}
};

#endif  /* NODE_H */