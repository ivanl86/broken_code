// who: Ivan Leung ileung2
// what: Bcuket Container
// why: Lab 5a
// when: May/10/2022

#include <stdexcept>

#include "bucket.h"

Bucket::Bucket() : Bucket(DEFAULT_SIZE) {}

Bucket::Bucket(const size_t size) : currSize{size}
{
    items = new double[currSize];
}

Bucket::~Bucket() { delete[] items; }

void Bucket::resize()
{
    size_t newSize{ currSize * SCALING_FACTOR };
    double *newItems{new double[newSize]};
    for (size_t i = 0; i < DEFAULT_SIZE; ++i)
        newItems[i] = items[i];
    delete[] items;
    items = newItems;
    currSize = newSize;
}

size_t Bucket::count() const
{
    return itemCount;
}

bool Bucket::isEmpty() const
{
    return (itemCount == 0) ? true : false;
}

void Bucket::add(const double item)
{
    if (itemCount == currSize - 1)
        resize();
    items[++itemCount] = item;
}

double Bucket::remove()
{
    if (isEmpty())
        throw std::runtime_error("Bucket is empty!");
    return items[itemCount--];
}

bool Bucket::remove(const double item)
{
    for (size_t i = 0; i <= itemCount; ++i)
    {
        if (items[i] == item)
        {
            for (size_t j = i; j < itemCount; ++j)
            {
                items[j] = items[j + 1];
            }
            --itemCount;
            return true;
        }
    }
    return false;
}

void Bucket::clear()
{
    for (size_t i = 0; i <= itemCount; i++)
        items[i] = NULL;
    itemCount = 0;
}

size_t Bucket::getFrequency(const double item) const
{
    size_t freq{0};
    for (size_t i = 0; i <= itemCount; ++i)
        if (items[i] == item)
            ++freq;
        
    return freq;
}

bool Bucket::contains(const double item) const
{
    for (size_t i = 0; i <= itemCount; ++i)
        if (items[i] == item)
            return true;
    return false;
}