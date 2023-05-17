#ifndef MORTCALC_CPP
#define MORTCALC_CPP

#include "mortcalc.hpp"

namespace
{
    uint64_t getMonth(const uint64_t& period);
    float getMonthlyRate(const float& interestRate);
}

namespace mort
{
    // float calcMortPayment(const uint64_t& principal, const uint64_t& downPayment, const float& interestRate, const uint64_t& period)
    float calcMortPayment(const uint64_t& period, const float& interestRate, const uint64_t& downPayment, const uint64_t& principal)
    {
        uint64_t loanAmount{principal - downPayment};
        float monthlyRate{getMonthlyRate(interestRate)};
        uint64_t monthTerm{getMonth(period)};
        return loanAmount * monthlyRate * std::pow(1 + monthlyRate, monthTerm) / (std::pow(1 + monthlyRate, monthTerm) - 1);
    }
}

namespace
{
    uint64_t getMonth(const uint64_t& period)
    {
        return period * MONTHS_IN_YEAR;
    }

    float getMonthlyRate(const float& interestRate)
    {
        return interestRate / MONTHS_IN_YEAR / PERCENT;
    }
}

#endif  /* MORTCALC_CPP */