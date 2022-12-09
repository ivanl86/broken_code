
#ifndef STACK_H
#define STACK_H

template<typename T>
class Node
{
public:
    T val;
    Node* next;
    Node(T val, Node *next) : val{val}, next{next} {}
private:

};

template<typename T>
class Stack
{
public:
    Stack() : head{nullptr} {}
    ~Stack() { clear(); }

    bool isEmpty() { return head == nullptr; }

    void push(T val) { head = new Node<T>(val, head); }

    T peek()
    {
        if (isEmpty())
            throw std::runtime_error("The stack is empty");

        return head->val;
    }

    T pop()
    {
        if (isEmpty())
            throw std::runtime_error("The stack is empty");

        Node<T>* temp{head};
        T val{head->val};

        head = head->next;

        delete temp;
        return val;
    }

    void clear()
    {
        head = clear(head);
        /*
        Node<T>* temp{};
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }*/
    }

private:
    Node<T>* head;

    Node<T>* clear(Node<T>* n)
    {
        Node<T>* t{n->next};
        if (n == nullptr)
            return nullptr;
        delete n;
        return clear(t);
    }
};

#endif