#include <iostream>
#include <iomanip>

#include "mortcalc.hpp"

template <typename T>
T getInput(std::string prompt);

int main(int argc, char const *argv[])
{
    const std::string welcomeMsg{"\t***Welcome to Mortgage Calculator***\n\n"};
    const std::string getPrincipal{"Enter your principal: $"};
    const std::string getDownPayment{"Enter your down payment: $"};
    const std::string getInterestRate{"Enter your annual interest rate: "};
    const std::string getPeriod{"Enter your mortgage term (years): "};
    float monthlyPayment{};

    std::cout << welcomeMsg;

    monthlyPayment = mort::calcMortPayment(getInput<uint64_t>(getPeriod), getInput<float>(getInterestRate), getInput<uint64_t>(getDownPayment), getInput<uint64_t>(getPrincipal));

    std::cout << std::fixed << std::setprecision(2) << "\nYour monthly mortgage payment is $" << monthlyPayment << "\n";

    return 0;
}

template <typename T>
T getInput(std::string prompt)
{
    T input{};
    std::cout << prompt;
    std::cin >> input;
    if (input < 0)
        input = abs(input);
    return input;
}