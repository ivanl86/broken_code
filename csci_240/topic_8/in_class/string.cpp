#include <iostream>
#include <cstring>

void printString(const std::string &str) {
    std::cout << str << "\n";
}

int main(int argc, char const *argv[])
{
    char* str{"these characters"};
    size_t strSize{std::strlen(str)};
    std::string str2{str};
    str2[8] = 'r';
    std::cout << str2.find("r") << "\n";
    const char* str3{str2.c_str()};

    std::cout << str3 << "\n";
    std::cout << str2 + str3 << "\n";

    printString("test");

    return 0;
}
