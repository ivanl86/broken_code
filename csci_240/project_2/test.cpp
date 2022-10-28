#include <iostream>

#include "skiplist.h"

int main(int argc, char const *argv[])
{
    Skiplist<int> sList([] (int l, int r) { return l > r; }); // ascending order
    sList.add(10);
    sList.add(20);
    sList.add(15);
    sList.add(25);
    sList.add(5);
    return 0;
}