
#include "pet.h"

class Dog : public Pet
{
public:
    Dog(const std::string &); // set breed
    Dog(const std::string &, const std::string &); // set breed and name

    std::string speak() const;

private:


};