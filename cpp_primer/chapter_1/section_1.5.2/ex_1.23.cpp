#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item totalBooks, bookTrans;

    if (std::cin >> totalBooks)
    {
        while (std::cin >> bookTrans)
        {
            if (bookTrans.isbn() == totalBooks.isbn())
                totalBooks += bookTrans;
            else
            {
                std::cout << totalBooks << std::endl;
                totalBooks = bookTrans;
            }
        }
        std::cout << totalBooks << std::endl;
    }

    return 0;
}