#include <iostream>
#include <array>

namespace std{
    void printArray(const std::array<int, 4> &a)
    {
        std::cout << sizeof a << std::endl;
        std::cout << "[ ";
        for (size_t i = 0; i < a.size(); ++i)
            std::cout << a.at(i) << ' ';
        std::cout << "]";
    }
}
int main(int argc, char const *argv[])
{
    std::array<int, 4> array{1,2,3,4};
    std::printArray(array);
    return 0;
}
