#include <functional>

#ifndef TEST_H
#define TEST_H

template<typename T>
class Tester
{
public:
    Tester(std::function<bool(T, T)> comparator) : comparator{comparator} {}

    bool compare(T left, T right) { return comparator(left, right); }
private:
    std::function<bool(T, T)> comparator;
};

#endif  /* TEST_H */