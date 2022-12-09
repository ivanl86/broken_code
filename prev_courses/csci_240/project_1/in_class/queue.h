#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual T front() = 0;
    virtual bool empty() = 0;
    virtual void clear() = 0;
};

#endif  /* QUEUE_H */