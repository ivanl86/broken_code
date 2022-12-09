#include <iostream>


int main(int argc, char const *argv[])
{
    char cs[]{"this is a test"};
    std::string s{"this is a test of the size of a string"};
    std::cout << sizeof(cs) << std::endl;
    //std::cout << s.length() << std::endl;
    return 0;
}
