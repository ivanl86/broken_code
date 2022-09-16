#include <iostream>

int binSearch(int[], int, int, int);

int main(int argc, char const *argv[])
{
    int array[]{1,2,3,4,5,6,7,8,9};

    std::cout << binSearch(array, 0, 8, 7) << std::endl;
    std::cout << binSearch(array, 0, 8, 4) << std::endl;
    std::cout << binSearch(array, 0, 8, 100) << std::endl;
    std::cout << binSearch(array, 0, 8, -4) << std::endl;

    return 0;
}

// returns the subscript of the term or -1 if not found
int binSearch(int a[], int start, int end, int term)
{
    int mid((start + end) >> 1);

    if (start > end)
        return -1;
    if (term == a[mid])
        return mid;
    if (term < a[mid])
        return binSearch(a, start, mid - 1, term);
    return binSearch(a, mid + 1, end, term);
}