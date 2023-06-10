#ifndef FUNC2_HPP
#define FUNC2_HPP

#include "func.hpp"
// code goes here
namespace
{
    template <typename T>
    void swap(T &left, T &right)
    {
        T tmp{left};
        left = right;
        right = tmp;
    }
}

#endif  /* FUNC2_HPP */