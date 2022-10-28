#include <iostream>

#include "skiplist.h"

int main(int argc, char const *argv[])
{
    Skiplist<int> sList([] (int l, int r) { return l < r; });
    sList.add(10);
    sList.add(20);
    return 0;
}
