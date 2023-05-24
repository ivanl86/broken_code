#ifndef SORT_HPP
#define SORT_HPP

#include <random>

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

    template <typename T>
    void mergeSort(T arr[], const int64_t& size);
}

#include "sort.tpp"

#endif  /* SORT_HPP */