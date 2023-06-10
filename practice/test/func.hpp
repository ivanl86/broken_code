#ifndef FUNC_HPP
#define FUNC_HPP

#include <stdint.h>

#include "func2.cpp"

    template <typename T>
    void bubbleSort(T array[], const int64_t& size)
    {
        bool isSwapped{false};
        for (size_t i{0}; i < size - 1; ++i)
        {
            for (size_t j{0}; j < size - 1 - i; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }
    }

#endif  /* FUNC_HPP */
