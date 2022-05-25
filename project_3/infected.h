#include <cstdlib>

#include "person.h"
#include "position.h"

#ifndef INFECTED_H
#define INFECTED_H

// should inherit from Person but be an abstract class
class Infected : public Person
{
public:
    /** Infected constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
    Infected(const Position& pos, char type);

    /** Moves the Infected. This is a pure virtual function which is overrriden in the derived Infecteds
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto */
    virtual void move(char move = 'A') = 0;
    
    /** Virtual Destructor */
    virtual ~Infected(); 

protected:
    const std::string stumble{"NSEW"};
    size_t randomStumble;
    size_t random(const size_t &start, const size_t &end);
    bool isValidStumble(const char &stumble);

private:
};



#endif