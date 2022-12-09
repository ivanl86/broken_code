#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    virtual void enqueueFront(T item) = 0;
    virtual void enqueueBack(T item) = 0;
    virtual T dequeueFront() = 0;
    virtual T dequeueBack() = 0;
    virtual T getFront() = 0;
    virtual T getBack() = 0;
    virtual bool isEmpty() = 0;
    virtual void clearQueue() = 0;
};

#endif  /* QUEUE_H */