#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
public:
    virtual void enqueue(const T& item) = 0;
    virtual T dequeue() = 0;
    virtual T front() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif  /* QUEUE_H */