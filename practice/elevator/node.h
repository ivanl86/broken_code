#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T item;
    Node<T>* next;

    Node(T item) : Node(item, nullptr) {}
    Node(T item, Node* next) : item{item}, next{next} {}
};

#endif  /* NODE_H */