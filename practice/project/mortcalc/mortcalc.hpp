#ifndef MORTCALC_HPP
#define MORTCALC_HPP

#include <stdint.h>
#include <string>
#include <cmath>

#define MONTHS_IN_YEAR 12
#define PERCENT 100

namespace mort
{
    // float calcMortPayment(const uint64_t& principal, const uint64_t& downPayment, const float& interestRate, const uint64_t& period);
    float calcMortPayment(const uint64_t& period, const float& interestRate, const uint64_t& downPayment, const uint64_t& principal);
}

#endif  /* MORTCALC_HPP */