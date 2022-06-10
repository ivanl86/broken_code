#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */;
    std::cout << /*  "*/" /*  "/*"  */;
    return 0;
}

// Only the third cout is not legal
// Add a double qoute before the semi-colon to fix the error