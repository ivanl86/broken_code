#include "pet.h"

#ifndef CAT_H
#define CAT_H

class Cat : public Pet
{
public:
    Cat(const std::string &);
    std::string speak() override;
};

#endif