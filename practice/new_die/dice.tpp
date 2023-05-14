#ifndef DICE_TPP
#define DICE_TPP

Dice::Dice(uint16_t count)
    : count{count}, dice{std::make_unique<die::D6[]>(count)}
{
    roll();
}

Dice::~Dice()
{}

uint16_t Dice::roll()
{
    sum = 0;
    // for (std::unique_ptr<D6> &die : dice)
    for(uint16_t i{0}; i < count; ++i)
    {
        sum += dice[i].roll();
    }
    return sum;
}

uint16_t Dice::getCount() const
{
    return count;
}

uint16_t Dice::getSum() const
{
    return sum;
}

#endif  /* DICE_TPP */