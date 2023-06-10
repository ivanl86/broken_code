#include <iostream>

#define ARRAY_SZ 10

void quickSort(int[], int64_t, int64_t);
int64_t partition(int[], int64_t, int64_t);
// int64_t partition(int[], int64_t, int64_t, int64_t);
void swap(int&, int&);

int main()
{
    int array[] {446,32,534,64,134,69,34,98,174,29};

    std::cout << "{ ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
        std::cout << array[i] << " ";
    std::cout << "}\n";

    quickSort(array, 0, ARRAY_SZ - 1);

    std::cout << "{ ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
        std::cout << array[i] << " ";
    std::cout << "}\n";

    return 0;
}

void quickSort(int array[], int64_t start, int64_t end) {
    int64_t pivotIdx{0};

    if (start >= end)
        return;

    pivotIdx = partition(array, start, end);

    quickSort(array, start, pivotIdx - 1);
    quickSort(array, pivotIdx + 1, end);
}
// void quickSort(int array[], int64_t start, int64_t end) {
//     int pivot{0};
//     int64_t pos{0};

//     if (start >= end)
//         return;

//     pivot = array[end];
//     pos = partition(array, start, end, pivot);

//     quickSort(array, start, pos - 1);
//     quickSort(array, pos + 1, end);
// }
// void quickSort(int array[], int64_t start, int64_t end) {
//     int64_t p{0};

//     if (start >= end)
//         return;

//     p = partition(array, start, end);

//     quickSort(array, start, p - 1);
//     quickSort(array, p + 1, end);
// }

int64_t partition(int array[], int64_t start, int64_t end) {
    int pivot{array[end]};
    // int64_t idx{start - 1};
    int64_t idx{start};
    if (start >= 0)
        idx = start - 1;

    for(int64_t j{start}; j < end; ++j) {
        if (array[j] <= pivot) {
            ++idx;
            swap(array[idx], array[j]);
        }
    }
    swap(array[idx + 1], array[end]);
    return idx + 1;
}
// int64_t partition(int array[], int64_t start, int64_t end, int64_t pivot) {
//     int64_t i{start};
//     int64_t j{start};
//     while (i <= end) {
//         if (array[i] > pivot)
//             ++i;
//         else {
//             swap(array[i], array[j]);
//             ++i;
//             ++j;
//         }
//         return j - 1;
//     }
// }
// int64_t partition(int array[], int64_t start, int64_t end) {
//     int64_t pivot{array[start]};
//     int64_t pivotIdx{0};
//     int64_t count{0};
//     int64_t i{start};
//     int64_t j{end};

//     for(size_t i{start + 1}; i <= end; ++i)
//         if (array[i] <= pivot)
//             ++count;

//     pivotIdx = start + count;
//     swap(array[pivotIdx], array[start]);

//     while (i < pivotIdx && j > pivotIdx) {
//         while (array[i] <= pivot) {
//             ++i;
//         }
//         while (array[j] > pivot) {
//             --j;
//         }
//         if (i < pivotIdx && j > pivotIdx)
//             swap(array[i++], array[j--]);
//     }

//     return pivotIdx;
// }

void swap(int& left, int& right) {
    int tmp{left};
    left = right;
    right = tmp;
}