#ifndef SORT_HPP
#define SORT_HPP

// #include <stdint.h>

namespace sort
{
    template <typename T>
    void bubbleSort(T array[], const int64_t& size);

    template <typename T>
    void selectionSort(T array[], const int64_t& size);

    template <typename T>
    void insertionSort(T array[], const int64_t& size);

    template <typename T>
    void quickSort(T array[], const int64_t& size);
}

#include "sort.tpp"

#endif  /* SORT_HPP */