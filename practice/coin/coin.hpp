#ifndef COIN_HPP
#define COIN_HPP

#include <stdlib.h>
#include <string>
#include <random>

class Coin
{
public:
    Coin(const double& value, const std::string& name)
        : heads{static_cast<bool>(rand(0, 1))}, value{value}, name{name} {}

    virtual ~Coin() {}

    void flip() noexcept
    {
        heads = static_cast<bool>(rand(0, 1));
    }

    bool isHeads() const noexcept
    {
        return heads;
    }

    double getValue() const noexcept
    {
        return value;
    }

    std::string getName() const noexcept
    {
        return name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Coin& coin) noexcept
    {
        return os << (coin.heads ? "Heads" : "Tails");
    }
    // std::ostream& operator<<(std::ostream& os, const Coin& coin) const noexcept
    // {
    //     return os << (heads ? "Heads" : "Tails");
    // }

    friend bool operator<(const Coin& left, const Coin& right) noexcept
    {
        return left.value < right.value;
    }
    // bool operator<(const Coin& other) const noexcept
    // {
    //     return value < other.getValue();
    // }

    friend bool operator>(const Coin& left, const Coin& right) noexcept
    {
        return right < left;
    }
    // bool operator>(const Coin& other) const noexcept
    // {
    //     return other < value;
    // }

    friend bool operator<=(const Coin& left, const Coin& right) noexcept
    {
        return !(left > right);
    }
    // bool operator<=(const Coin& other) const noexcept
    // {
    //     return !(value > other);
    // }

    friend bool operator>=(const Coin& left, const Coin& right) noexcept
    {
        return !(left < right);
    }
    // bool operator>=(const Coin& other) const noexcept
    // {
    //     return !(value < other);
    // }

private:
    bool heads;
    double value;
    std::string name;

    int16_t rand(const int16_t& low, const int16_t& high)
    {
    static std::random_device rd;
    static std::mt19937 rndGen{rd()};
    static std::uniform_int_distribution<int> uniformDist{low, high};
    return static_cast<uint16_t>(uniformDist(rd));
    }
};

#endif  /* COIN_HPP */