// who:  Ivan Leung ileung2
// what: BitBucket Definition
// why:  Lab Exam 1
// when: 2022-09-20

#include <stdexcept>
#include "bit_bucket.h"

BitBucket::BitBucket(size_t size) : size{size}
{
    bucket = new unsigned char[size];
    clear();
}

void BitBucket::set(size_t pos)
{
    size_t bytePos{pos >> 3};
    size_t bitPos{pos - (bytePos << 3)};

    if (pos >= (size << 3))
        throw std::range_error("Position out of the range!");
    bucket[bytePos] = bucket[bytePos] | (1 << bitPos);
}

void BitBucket::unset(size_t pos)
{
    size_t bytePos{pos >> 3};
    size_t bitPos{pos - (bytePos << 3)};

    if (pos >= size << 3)
        throw std::range_error("Position out of the range!");
    bucket[bytePos] = bucket[bytePos] & ~(1 << bitPos);
}

bool BitBucket::at(size_t pos)
{
    size_t bytePos{pos >> 3};
    size_t bitPos{pos - (bytePos << 3)};

    if (pos >= size << 3)
        throw std::range_error("Position out of the range!");
    return bucket[bytePos] & (1 << bitPos);
}

void BitBucket::clear()
{
    for (size_t i = 0; i < size; ++i)
        bucket[i] = 0;
}