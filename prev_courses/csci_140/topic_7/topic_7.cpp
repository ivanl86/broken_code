

#include <iostream>

int main(int argc, char const *argv[])
{
    char c;
    while (std::cin.peek() != EOF) // EOF == CTRL Z
    {
        //std::cin.get(c);
        //std::cout << c;
        std::cout << static_cast<char>(std::cin.get());
    }
    std::cout << c;
    return 0;
}
