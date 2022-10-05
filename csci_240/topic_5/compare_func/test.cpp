#include <iostream>

#include "test.h"
#include "keyvalue_pair.h"

int main(int argc, char const *argv[])
{
/*
    Tester<int> t(
        [] (int l, int r) { return l >= r; }
        );

    std::cout << std::boolalpha;

    std::cout << t.compare(10, 10) << '\n';

    //

    Tester<KVPair<int, int>> t(
        [] (KVPair<int, int> l, KVPair<int, int> r) { return l.key >= r.key; }
        );

    std::cout << std::boolalpha;

    std::cout << t.compare({10, 20}, {5, 55}) << '\n';
    return 0;
*/
    KVPair<int, int> p1{5, 55};
    KVPair<int, int> p2{10, 20};

    std::cout << std::boolalpha;

    std::cout << (p1 < p2) << '\n';
    return 0;
}
