#ifndef SORT_TPP
#define SORT_TPP

#include <stdint.h>

namespace
{
    template <typename T>
    void swap(T &left, T &right);

    template <typename T>
    void quickSort(T array[], const int64_t& lowIdx, const int64_t& highIdx);

    template <typename T>
    int64_t partition(T array[], const int64_t& lowIdx, const int64_t& highIdx, const T& pivotTerm);

    template <typename T>
    void merge(T arr[], T leftHalf[], const uint64_t& leftSize, T rightHalf[], const uint64_t& rightSize);
}

namespace sort
{
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
                    ::swap(array[j], array[j + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }
    }

    template <typename T>
    void selectionSort(T array[], const int64_t& size)
    {
        uint64_t min{};
        for (size_t i{0}; i < size - 1; ++i)
        {
            min = i;
            for (size_t j{i + 1}; j < size; ++j)
            {
                if (array[min] > array[j])
                {
                    min = j;
                }
            }
            if (min > i)
            {
                ::swap(array[i], array[min]);
            }
        }
    }

    template <typename T>
    void insertionSort(T array[], const int64_t& size)
    {
        T min{};
        int64_t j;
        for (size_t i{0}; i < size; ++i)
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

    template <typename T>
    void quickSort(T array[], const int64_t& size)
    {
        ::quickSort(array, 0, size - 1);
    }

    template <typename T>
    void mergeSort(T arr[], const int64_t& size)
    {
        uint64_t midIdx{size / 2};
        T leftHalf[midIdx];
        T rightHalf[size - midIdx];

        if (size < 2)
            return;
        
        for(uint64_t i{0}; i < midIdx; ++i)
            leftHalf[i] = arr[i];

        for(uint64_t i{midIdx}; i < size; ++i)
            rightHalf[i - midIdx] = arr[i];

        mergeSort(leftHalf, midIdx);
        mergeSort(rightHalf, size - midIdx);

        ::merge(arr, leftHalf, midIdx, rightHalf, size - midIdx);
    }
}

namespace
{
    template <typename T>
    void swap(T &left, T &right)
    {
        T tmp{left};
        left = right;
        right = tmp;
    }

    template <typename T>
    void quickSort(T array[], const int64_t& lowIdx, const int64_t& highIdx)
    {
        // T pivotTerm{array[highIdx]};
        int64_t leftPtr{};

        if (lowIdx >= highIdx)
            return;

        leftPtr = partition(array, lowIdx, highIdx, array[highIdx]);

        quickSort(array, lowIdx, leftPtr - 1);
        quickSort(array, leftPtr + 1, highIdx);
    }

    template <typename T>
    int64_t partition(T array[], const int64_t& lowIdx, const int64_t& highIdx, const T& pivotTerm)
    {
        int64_t leftPtr{lowIdx};
        int64_t rightPtr{highIdx};

        while (leftPtr < rightPtr)
        {
            while (array[leftPtr] <= pivotTerm && leftPtr < rightPtr) // while left term is equal to or less than pivot term and left ptr is less than right ptr
            {
                ++leftPtr; // increment left ptr
            }
            while (array[rightPtr] >= pivotTerm && leftPtr < rightPtr) // while right term is equal to or greater than pivot term and left ptr is less than right ptr
            {
                --rightPtr; // decrement right ptr
            }
            swap(array[leftPtr], array[rightPtr]); // swap the left term with right term
        }
        swap(array[leftPtr], array[highIdx]); // swap the left term with pivot term
        return leftPtr;
    }

    template <typename T>
    void merge(T arr[], T leftHalf[], const uint64_t& leftSize, T rightHalf[], const uint64_t& rightSize)
    {
        uint64_t i{0};
        uint64_t j{0};
        uint64_t k{0};

        while (i < leftSize && j < rightSize)
        {
            if (leftHalf[i] <= rightHalf[j])
            {
                arr[k] = leftHalf[i];
                ++i;
            }
            else
            {
                arr[k] = rightHalf[j];
                ++j;
            }
            ++k;
        }

        while (i < leftSize)
        {
            arr[k] = leftHalf[i];
            ++i;
            ++k;
        }

        while (j < rightSize)
        {
            arr[k] = rightHalf[j];
            ++j;
            ++k;
        }
    }
}

#endif /* SORT_TPP */