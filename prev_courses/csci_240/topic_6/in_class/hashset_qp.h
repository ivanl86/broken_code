#include "hashset.h"

#ifndef HASHSET_QP_H
#define HASHSET_QP_H

template<typename T>
class HashsetQP : public Hashset<T>
{
public:

private:
    int locateItem(const T& item)
    {
        int s{this->hashcode(item)};

        for (size_t i{0}, i < PROB_LIMIT; ++i)
        {
            size_t subscript{s + (i * i) % INITIAL_SIZE};
            if (this->store[subscript].status == EMPTY)
                return -1;
            if (this->store[subscript].status == OCCUPIED && store[subscript].item == item)
                return subscript;
        }
        return -1;
    }
    int locateAvailPos(const T& item)
    {}

    size_t offset[]{0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676}
    constexpr offset(int i)
    {
        return i * i;
    }
};

#endif  /* HASHSET_QP_H */