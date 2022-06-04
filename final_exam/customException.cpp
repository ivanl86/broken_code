
#include <iostream>
#include <stdexcept>

double quotient(const double & numerator, const double &denominator);

namespace except
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
    double num1{6};
    double num2{0};

    try
    { std::cout << quotient(num1, num2) << std::endl; }
    catch(const except::DivideByZeroException &divideByZeroException)
    { std::cerr << divideByZeroException.what() << '\n'; }

    return 0;
}

double quotient(const double &numerator, const double &denominator)
{
    if (denominator == 0)
        throw except::DivideByZeroException();
    return (numerator / denominator);
}
