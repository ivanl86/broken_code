// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "account.h"

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
public:
   explicit SavingsAccount(const std::string &, const double &, const double &);

   double calculateInterest() const;
   double getInterestRate() const;
   void setInterestRate(const double &);

private:
   double interestRate;
};

#endif