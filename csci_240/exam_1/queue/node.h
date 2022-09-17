#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    Node(T item, Node<T> *previous, Node<T> *next) : item{item}, previous{previous}, next{next} {}
    Node(T item) : Node<T>(item, nullptr, nullptr) {}

    T item;
    Node<T> *next;
    Node<T> *previous;
private:

};

#endif  /* NODE_H */