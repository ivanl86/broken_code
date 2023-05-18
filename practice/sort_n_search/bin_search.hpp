#ifndef BIN_SEARCH_HPP
#define BIN_SEARCH_HPP

#include <stdint.h>

template<typename T>
int64_t binSearch(T array[], uint32_t size, T searchTerm)
{
    int64_t start{0};
    int64_t end{size - 1};
    int64_t mid{};

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (searchTerm == array[mid])
            return mid;
        else if (searchTerm > array[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

#endif  /* BIN_SEARCH_HPP */