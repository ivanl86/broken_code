
#include <iostream>
#include <vector>

// #include "pet.h"
#include "dog.h"
#include "cat.h"

int main(int argc, char const *argv[])
{
    // Pet p1{"Dog", "German Shepherd"};
    // Pet p2{"Cat", "who the hell cares", "fluffy"};

    std::vector<Pet*> pets{new Dog{"Shitpoo", "Milo"}, new Cat {"Calico", "Black"}};

    Dog d1{"Shitpoo", "Milo"};
    Cat c1{"Calico", "Black"};

    Dog d2("");

    Pet *p3{new Dog{""}};

    *p3 = *pets[0];

    Pet& p2{d2};

    // std::cout << p2.getName() << " the " << p2.getType() << " is a " << p2.getBreed() << "\n";
    // std::cout << p1.getName() << " the " << p1.getType() << " is a " << p1.getBreed() << "\n";
    for (Pet* p : pets)
    {
        // std::cout << p->getName() << " the " << p->getType() << " is a " << p->getBreed() << " and says " << p->speak() << "\n";
        std::cout << *p << "\n";
    }

    std::cout << *p3 << "\n";

    // std::cout << d1.getName() << " the " << d1.getType() << " is a " << d1.getBreed() << " and says " << d1.speak() << "\n";
    // std::cout << c1.getName() << " the " << c1.getType() << " is a " << c1.getBreed() << " and says " << c1.speak() << "\n";

    return 0;
}
