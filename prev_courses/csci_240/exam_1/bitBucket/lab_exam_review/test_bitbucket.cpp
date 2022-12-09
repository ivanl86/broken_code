#include <iostream>

#include "bit_bucket.h"

int main(int argc, char const *argv[])
{
    BitBucket<1000> bb;

    for(size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout << "get a prob with the bucket\n";

    bb.set(120);

    for(size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout << "have a bit set at " << i << '\n';

    bb.unset(120);

    for(size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout << "get a prob with the bucket\n";

    try
    {
        bb.at(1000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
