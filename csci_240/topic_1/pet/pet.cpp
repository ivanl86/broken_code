#include "pet.h"

Pet::Pet(const std::string &species, const std::string &name)
    : species{species}, name{name} {}

std::string Pet::speak() { return name + std::string{" Wuu"}; }