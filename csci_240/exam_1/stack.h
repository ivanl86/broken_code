#include <stdexcept>

#ifndef STACK_H
#define STACK_H

#define DEFAULT_SIZE 8
#define SCALING_FACTOR 2

template<typename T>
class Stack
{
public:
    Stack() : currentCount{0}, currentSize{DEFAULT_SIZE} {}

    void push(T newItem)
    {
        if (currentCount >= currentSize)
            resize();
        
        item[currentCount++] = newItem;
    }

    T pop()
    {
        if (empty)
            throw std::runtime_error("The stack is empty");

        return item[currentCount--];
    }

    T peek()
    { return item[currentCount]; }

    bool empty()
    { return currentCount == 0; }

    void clear()
    { currentCount == 0; }

private:
    T *item;
    size_t currentCount;
    size_t currentSize;

    void resize()
    {
        T *newItem{new T[currentSize *= SCALING_FACTOR]};
        for(size_t i{0}; i < currentSize / SCALING_FACTOR; ++i)
            newItem[i] = item[i];
        delete item;
        item = newItem;
    }
};



#endif  /* STACK_H */