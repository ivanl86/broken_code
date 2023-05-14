#ifndef D6_DIE_HPP
#define D6_DIE_HPP

#include "die.hpp"

#define SIX_SIDES 6

namespace die
{
    class D6 : public Die
    {
    public:
        D6();

        ~D6();

    private:

    };

    #include "d6.tpp"
}

#endif  /* D6_DIE_HPP */