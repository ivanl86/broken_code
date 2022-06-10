#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book1, book2, book3, book4;
    std::cin >> book1 >> book2 >> book3 >> book4;
    std::cout << book1 + book2 + book3 + book4 << std::endl;
    return 0;
}