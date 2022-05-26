#include "position.h"
#include "infected.h"
#include "uninfected.h"

#ifndef AGGRESSOR_H
#define AGGRESSOR_H

#define IN_RANGE 2

// should inherit from Infected
class Aggressor : public Infected
{
public:
    /** Aggressor constructor. Calls Infected constructor with type 'H'
     * @parameter pos is the initial position.*/
    Aggressor(const Position &pos);

    /** Aggressor construtor. Calls first Aggressor constructor
     * @parameter specOp is used to track specOp's current position */
    Aggressor(const Position &pos, Uninfected *specOp);

    /** Moves the Infected. This function overrides in the Infected's pure virtual function
     *  moves this Infected towards the spec-op either in the x or y direction.
     * @parameter move determines the position to move to.
     *            Defaults to 'A' for auto */
    void move(const char move = 'A');

    /** Destructor */
    ~Aggressor();

protected:

private:
    Uninfected *victim{nullptr};

    /* return true if the victim is witin the range of two adjacent cells and false otherwise */
    bool isVictimInRange() const;

    /* make a random move using the random function if victim is not witin the range*/
    void randomMove();

    /* pursue the victim if it is within the range */
    void pursueVictim();
};

#endif