#ifndef SORT_TPP
#define SORT_TPP

#include "sort.hpp"

template <typename T>
void swap(T& left, T& right)
{
    T tmp{left};
    left = right;
    right = tmp;
}

template <typename T>
void bubbleSort(T array[], int64_t size)
{
    bool isSwapped{false};
    for(size_t i{0}; i < size - 1; ++i)
    {
        for(size_t j{0}; j < size - 1 - i; ++j)
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

template <typename T>
void selectionSort(T array[], int64_t size)
{
    uint64_t min{};
    for(size_t i{0}; i < size - 1; ++i)
    {
        min = i;
        for(size_t j{i + 1}; j < size; ++j)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        if (min > i)
        {
            swap(array[i], array[min]);
        }
    }
}

template <typename T>
void insertionSort(T array[], int64_t size)
{
    T min{};
    int64_t j;
    for(size_t i{0}; i < size; ++i)
    {
        min = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > min)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = min;
    }
}

#endif  /* SORT_TPP */