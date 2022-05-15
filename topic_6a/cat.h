
#include "pet.h"

class Cat : public Pet
{
public:
    Cat(const std::string &); // set breed
    Cat(const std::string &, const std::string &); // set breed and name

    virtual std::string speak() const;

private:


};