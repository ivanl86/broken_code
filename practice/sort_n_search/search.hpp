#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <stdint.h>

// template<typename T>
// int64_t seqSearch(const T array[], const uint32_t& size, const T& searchTerm)
// {
//     for(size_t i{0}; i < size; ++i)
//     {
//         if (array[i] == searchTerm)
//             return i;
//     }
//     return -1;
// }

template<typename T>
int64_t seqSearch(const T array[], const uint32_t& size, const T& searchTerm)
{
    if (size < 1)
        return -1;
    return (array[size - 1] == searchTerm) ? size - 1 : seqSearch(array, size - 1, searchTerm); 
}

// template<typename T>
// int64_t binSearch(const T array[], const uint32_t& size, const T& searchTerm)
// {
//     int64_t start{0};
//     int64_t end{size - 1};
//     int64_t mid{};

//     while (start <= end)
//     {
//         mid = (start + end) / 2;

//         if (searchTerm == array[mid])
//             return mid;
//         else if (searchTerm > array[mid])
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }

//     return -1;
// }

template<typename T>
int64_t binSearch(const T array[], const int64_t& lowIdx, const int64_t& highIdx, const T& searchTerm)
{
    int64_t mid{(lowIdx + highIdx) / 2};
    if (lowIdx > highIdx)
        return -1;
    if (searchTerm == array[mid])
        return mid;
    return (searchTerm < array[mid]) ? binSearch(array, lowIdx, mid - 1, searchTerm) : binSearch(array, mid + 1, highIdx, searchTerm);
}

template<typename T>
int64_t binSearch(const T array[], const uint32_t& size, const T& searchTerm)
{
    return binSearch(array, 0, size - 1, searchTerm);
}

#endif  /* SEARCH_HPP */