#ifndef MATH_H
#define MATH_H

template<typename T>
class Math
{
public:
    Math(T length, T width) : length{length}, width{width} {}
    T area() { return length * width; }
    static T min(T a, T b) { return (a > b) ? b : a; }
    static T max(T a, T b) { return (a > b) ? a : b; }
    static T abs(T a) { return (a >= 0 ? a : (-a)); }

private:
    T length;
    T width;
};

#endif