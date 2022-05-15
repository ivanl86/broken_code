
#include <string>
#include <iostream>

#ifndef PET_H
#define PET_H

class Pet
{
    friend std::ostream& operator<<(std::ostream&, const Pet&);

public:
    Pet(const std::string &, const std::string &); // set type and breed
    Pet(const std::string &, const std::string &, const std::string &); // set type, breed, and name

    virtual std::string speak() const = 0;

    void operator=(const Pet&);

    std::string getBreed() const;
    std::string getType() const;
    std::string getName() const;

    void setBreed(const std::string &);
    void setType(const std::string &);
    void setName(const std::string &);

private:
    std::string type;
    std::string breed;
    std::string name;
};

#endif
