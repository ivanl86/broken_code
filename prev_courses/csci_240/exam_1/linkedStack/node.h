#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    Node(T item, Node<T> *next) : item{item}, next{next} {}
    Node(T item) : Node<T>(item, nullptr) {}

    T item;
    Node<T> *next;
private:

};

#endif  /* NODE_H */