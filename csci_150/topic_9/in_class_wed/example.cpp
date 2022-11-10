#include <iostream>

struct Coordinates
{
    int x;
    int y;
};

void swap(int& a, int& b) {
    if (a == b)
        return;

    a ^= b;
    b ^= a;
    a ^= b;
}

void bubbleSort(int array[], size_t size) {
    int greater{};
    bool hasSwapped;
    for(size_t i{size - 1}; i > 0; --i)
    {
        hasSwapped = false;
        for(size_t less{0}; less < i; ++less)
        {
            greater = less + 1;
            if (array[less] > array[greater])
                swap(array[less], array[greater]);
            hasSwapped = true;
        }
        if (!hasSwapped)
            break;
    }
}

void printArray(int array[], size_t size) {
    std::cout << "[ ";
    for(size_t i{0}; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << "]\n";
}

int binarySearch(int array[], int start, int end, int term) {
    int mid {(start + end) / 2};
    if (start > end)
        return -1;
    if (array[mid] == term)
        return mid;
    else if (array[mid] > term)
        return binarySearch(array, start, mid - 1, term);
    else
        return binarySearch(array, mid + 1, end, term);
}

int binarySearch(int array[], int size, int term) {
    return binarySearch(array, 0, size - 1, term);
}

int main(int argc, char const *argv[])
{
    // Coordinates c{2,1};
    // std::cout << sizeof(Coordinates) << "\n";

    int array[] {8,6,3,7,9,1,2,4,5};
    size_t size {sizeof(array) / sizeof(int)};

    std::cout << "Before sorting:\n";
    printArray(array, size);
    bubbleSort(array, size);
    std::cout << "After sorting:\n";
    printArray(array, size);
    std::cout << "10 does " << (binarySearch(array, size, 10) >= 0 ? "exists\n" : "not exists\n");
    return 0;
}
