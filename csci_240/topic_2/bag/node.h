#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T item;
    Node<T> *children;

    Node(T item, Node<T> *children) : item{item}, children{children} {}
    Node(T item) : Node<T>(item, nullptr) {}
};

#endif  /* NODE_H */