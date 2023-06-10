#include <iostream>

void func(int* ptr);
void func2(int* ptr);
void func3(int * ptr, const uint64_t& size);

int main(int argc, char const *argv[])
{
    /* code */
    int val{8};
    int arr[] {1, 2, 3};
    int* ptr{arr};
    uint64_t size{sizeof(arr) / sizeof(int)};
    std::cout << val << "\n";
    for(size_t i{0}; i < size; ++i)
    {
        std::cout << " " << arr[i];
    }
    std::cout << "\n";
    func(&val);
    func2(ptr);
    std::cout << val << "\n";
    func3(ptr, size);
    // for(size_t i{0}; i < size; ++i)
    // {
    //     std::cout << " " << arr[i];
    // }
    std::cout << "\n";
    return 0;
}

void func(int* ptr)
{
    *ptr = 10;
}

void func2(int* ptr)
{
    *(ptr + 1) = 4; 
}

void func3(int* ptr, const uint64_t& size)
{
    for(size_t i{0}; i < size; ++i)
    {
        if (i > 0)
            std::cout << " ";

        std::cout << *(ptr + i);
    }
}