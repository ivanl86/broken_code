#include <iostream>

#include "pet.h"
#include "dog.h"
#include "cat.h"

int main(int argc, char const *argv[])
{
    // Pet pet("dog", "lucky");
    // Dog dog("Fido");
    Pet *pets[] = {new Dog("Lucky"), new Dog("Fido"), new Cat("Frisky")};

    // std::cout << pet.speak() << std::endl;
    // std::cout << dog.speak() << std::endl;

    for (size_t i = 0; i < 3; ++i)
        std::cout << pets[i]->speak() << std::endl;
    
    std::cout << std::endl;

    for (Pet *p : pets)
        std::cout << p->speak() << std::endl;

    return 0;
}
