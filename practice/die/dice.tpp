Dice::Dice(const uint16_t& count) noexcept
    : dice{new Die[count]}, count{count}
{
    roll();
}

Dice::Dice(const uint16_t& sides, const uint16_t& count) noexcept
    : dice{new Die[count]}, count{count}
{
    for (uint16_t i {0}; i < this->count; ++i)
        dice[i].setSides(sides);

    roll();
}

Dice::~Dice() noexcept
{
    delete[] dice;
}

uint16_t Dice::roll() noexcept
{
    sum = 0;

    for (uint16_t i{0}; i < count; ++i)
        sum += dice[i].roll();

    return sum;
}

uint16_t Dice::getSum() const noexcept
{
    return sum;
}

// void Dice::addDie(const uint16_t& count)
// {
//     Die* newSet{new Die[this->count + count]};
//     this->count += count;
//     delete[] dice;
//     dice = newSet;
// }

// void Dice::removeDie(const uint16_t& count)
// {
//     Die* newSet{new Die[this->count - count]};
//     this->count += count;
//     delete[] dice;
//     dice = newSet;
// }

void Dice::setCount(const uint16_t& newCount) noexcept(false)
{
    Die* newSet;
    uint16_t sides{dice->getSides()};

    if (newCount < 1 || newCount > MAX_COUNT)
        throw std::runtime_error("Invalid Dice count!");

    newSet = new Die[newCount];
    count = newCount;

    for (uint16_t i {0}; i < count; ++i)
        newSet[i].setSides(sides);

    delete[] dice;
    dice = newSet;
}

uint16_t Dice::getCount() const noexcept
{
    return count;
}