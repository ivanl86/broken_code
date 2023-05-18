#include <iostream>

#include "bin_search.hpp"

int main(int argc, char const *argv[])
{
    uint32_t size{10};
    int term{0};
    int array[size]{1,2,3,4,5,6,7,8,9};
    int64_t idx{binSearch(array, size, term)};

    if (idx > -1)
        std::cout << array[idx] << " at index " << idx << "\n";
    else
        std::cout << "Item not Found!\n";

    return 0;
}
