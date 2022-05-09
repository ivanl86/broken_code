// who: Ivan Leung ileung2
// what: Bcuket Container
// why: Lab 5a
// when: May/10/2022

#include <iostream>

#include "bucket.h"

int main(int argc, char const *argv[])
{
    Bucket items;

    // testing count() and isEmpty()
    std::cout << items.count() << " item(s) in the bucket\n";
    std::cout << "The bucket " << (items.isEmpty() ? "is" : "is not") << " empty!\n";
    // testing add(int)
    for (size_t i = 1; i <= 4; i++)
        items.add(i);
    std::cout << items.count() << " item(s) in the bucket\n";
    std::cout << "The bucket " << (items.isEmpty() ? "is" : "is not") << " empty!\n";
    // testing remove()
    std::cout << "The bucket " << (items.contains(4) ? "contains" : "does not contain") << " 4\n";
    std::cout << items.remove() << " is removed\n";
    std::cout << items.count() << " item(s) in the bucket\n";
    std::cout << "The bucket " << (items.contains(4) ? "contains" : "does not contain") << " 4\n";
    // testing remove(int) and contains(int)
    std::cout << "The bucket " << (items.contains(1) ? "contains" : "does not contain") << " 1\n";
    std::cout << "1 " << (items.remove(1) ? "is removed\n" : "is not removed\n");
    std::cout << items.count() << " item(s) in the bucket\n";
    std::cout << "The bucket " << (items.contains(1) ? "contains" : "does not contain") << " 1\n";
    // testing remove(int) and getFrequency(int)
    std::cout << "The bucket " << (items.contains(1) ? "contains" : "does not contain") << " 1\n";
    std::cout << "1 " << (items.remove(1) ? "is removed\n" : "is not removed\n");
    std::cout << "The bucket contains " << items.getFrequency(1) << " 1(s) in the bucket\n";
    std::cout << items.count() << " item(s) in the bucket\n";
    // testing add(int) and resize()
    for (size_t i = 1; i <= 4; i++)
        items.add(i);
    for (size_t i = 1; i <= 4; i++)
        items.add(i);
    std::cout << items.count() << " item(s) in the bucket\n";
    // testing remove(int), contains(int), and getFrequency(int)
    std::cout << "The bucket " << (items.contains(3) ? "contains" : "does not contain") << " 3\n";
    std::cout << "The bucket contains " << items.getFrequency(3) << " 3(s) in the bucket\n";
    std::cout << "3 " << (items.remove(3) ? "is removed\n" : "is not removed\n");
    std::cout << "The bucket contains " << items.getFrequency(3) << " 3(s) in the bucket\n";
    std::cout << items.count() << " item(s) in the bucket\n";
    // testing clear()
    items.clear();
    // std::cout << items.remove() << " is removed\n";
    std::cout << "1 " << (items.remove(1) ? "is removed\n" : "is not removed\n");
    std::cout << "The bucket " << (items.isEmpty() ? "is" : "is not") << " empty!\n";
    std::cout << items.count() << " item(s) in the bucket\n";
    return 0;
}