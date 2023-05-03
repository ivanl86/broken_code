#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T item;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& item) : Node(item, nullptr, nullptr) {}
    Node(const T& item, Node<T>* prev, Node<T>* next) : item{item}, prev{prev}, next{next} {}
};

#endif  /* NODE_H */