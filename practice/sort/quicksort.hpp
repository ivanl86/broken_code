#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <stdint.h>

template <typename T>
void swap(T& left, T& right)
{
    T tmp{left};
    left = right;
    right = tmp;
}

template <typename T>
void quickSort(T array[], int64_t start, int64_t end)
{
    int64_t pivotIdx{};
    if (start >= end)
        return;
    pivotIdx = end - 1;

    quickSort(array, start, pivotIdx);
    quickSort(array, pivotIdx + 1, end);

    for(int64_t i{start}; i < end; ++i)
    {
        if (array[start] > array[end])
            swap(array[start], array[end]);
    }
}


#endif  /* QUICKSORT_HPP */