#include <iostream>
#include <stdexcept>

struct Node {
    int val;
    Node* next;

    Node(int val) : Node(val, nullptr) {}
    Node(int val, Node* next)
        : val{val}, next{next} {}
};

class Stack {
public:
    Stack() : head{nullptr} {}

    void push(int val) {
        head = new Node(val, head);
    }

    int pop() {
        Node* tmp{head};
        int rtn{head->val};

        if (empty())
            throw std::runtime_error("Pop on empty stack");

        head = head->next;
        delete tmp;
        
        return rtn;
    }

    int peek() {
        if (empty())
            throw std::runtime_error("Pop on empty stack");

        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        while (!empty())
            pop();
    }
private:
    Node* head;
};

int main(int argc, char const *argv[])
{
    Stack stack;
    for (size_t i{0}; i < 10; ++i)
        stack.push(i);

    while (!stack.empty())
        std::cout << stack.pop() << "\n";
    
    return 0;
}
