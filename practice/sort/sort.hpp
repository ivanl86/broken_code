#ifndef SORT_HPP
#define SORT_HPP

#include <stdint.h>

template <typename T>
void swap(T& left, T& right);

template <typename T>
void bubbleSort(T array[], int64_t size);

template <typename T>
void selectionSort(T array[], int64_t size);

template <typename T>
void insertionSort(T array[], int64_t size);

#include "sort.tpp"

#endif  /* SORT_HPP */