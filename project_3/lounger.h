#include "person.h"
#include "position.h"
#include "Infected.h"

// should inherit from Infected 
class Lounger
{
public:
    /** Lounger constructor. Calls Infected constructor with type 'I'
     * @parameter pos is the initial position.*/
    Lounger(const Position& pos);

    /** Moves the Infected. This function overrrides in the Infected's pure virtual function
     *  has a 20% chance of moving this Infected in a random direction.
     * @parameter move determines the  position to move to. 
     *            Defaults to 'A' for auto
     */
    void move(const char move = 'A'); 
    
    /** Destructor */
    ~Lounger(){}
    
protected:

private:
};