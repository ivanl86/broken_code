#ifndef DIE_TPP
#define DIE_TPP

Die::Die(uint16_t sides)
    : totalSides{sides}, faceValue{static_cast<uint16_t>(rand(1 , sides))} {}

Die::~Die() {}

uint16_t Die::roll()
{
    return static_cast<uint16_t>(rand(1, totalSides));
}

uint16_t Die::getFaceValue() const
{
    return faceValue;
}

uint16_t Die::getTotalSides() const
{
    return totalSides;
}

uint16_t Die::rand(int start, int end)
{
    static std::random_device rd;
    static std::mt19937 rndGen{rd()};
    static std::uniform_int_distribution<int> uniformDist{start, end};
    return static_cast<uint16_t>(uniformDist(rd));
}

#endif  /* DIE_TPP */