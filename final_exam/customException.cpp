
#include <iostream>
#include <stdexcept>

double quotient(const double & numerator, const double &denominator);

namespace exc
{
class DivideByZeroException : public std::runtime_error
{
public:
    DivideByZeroException()
    : std::runtime_error{"attempted to divide by zero"} {}
};
}

int main(int argc, char const *argv[])
{
    double numerator{6};
    double denominator{0};

    try
    { std::cout << quotient(numerator, denominator) << std::endl; }
    catch(const exc::DivideByZeroException &divideByZeroException)
    { std::cerr << divideByZeroException.what() << '\n'; }

    return 0;
}

double quotient(const double &numerator, const double &denominator)
{
    if (denominator == 0)
        throw exc::DivideByZeroException();
    return (numerator / denominator);
}
