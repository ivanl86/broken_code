#include <iostream>

#include "search.hpp"
#include "sort.hpp"

// void sizeOfArray(int array[])
// {
//     std::cout << "The size of array in func: " << sizeof(array) << "\n";
// }

int main(int argc, char const *argv[])
{
    int idx{};
    int term{446};
    int array[] {446,32,534,64,134,69,34,98,174,29};
    // int array[] {1,2,3,4};
    // int array[] {4,3,2,1};
    uint64_t size{sizeof(array) / sizeof(int)};
    for(int element : array)
    {
        std::cout << " " << element;
    }
    std::cout << "\n";
    // idx = seqSearch(array, size, term);
    // idx = binSearch(array, size, term);
    if (idx < 0)
        std::cout << "Item is not found\n";
    else
        std::cout << array[idx] << " is at index " << idx << "\n";
    // sort::bubbleSort(array, size);
    // sort::selectionSort(array, size);
    // sort::insertionSort(array, size);
    sort::quickSort(array, size);
    // swap(array[0], array[1]);
    for(int element : array)
    {
        std::cout << " " << element;
    }
    std::cout << "\n";
    // idx = seqSearch(array, size, term);
    // idx = binSearch(array, size, term);
    if (idx < 0)
        std::cout << "Item is not found\n";
    else
        std::cout << array[idx] << " is at index " << idx << "\n";
    return 0;
}
