Die::Die() : Die(DEFAULT_SIZE)
{}

Die::Die(const uint16_t& sides)
    : sides{sides}, face{static_cast<uint16_t>(rand() % sides + 1)}
{}

uint16_t Die::roll()
{
    return (face = static_cast<uint16_t>(rand() % sides + 1));
}

uint16_t Die::getFace()
{
    return face;
}

void Die::setSides(const uint16_t& sides)
{
    this->sides = sides;
}

uint16_t Die::getSides()
{
    return sides;
}