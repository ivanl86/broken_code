#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() = 0;
    virtual bool isEmpty() = 0;
    virtual void clearQueue() = 0;
};

#endif  /* QUEUE_H */