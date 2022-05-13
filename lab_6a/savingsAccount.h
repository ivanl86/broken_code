// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

// SavingsAccount class with a constructor that initializes the account name, account balance, and account interest rate.
#include "account.h"

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
public:
   // constructor initializes data member name, balance, and interest rate with parameter accountName, accountBalance, and accountRate
   explicit SavingsAccount(const std::string &, const double &, const double &);

   // function to calculate the interest
   double calculateInterest() const;

   // function to retrieve the account interest rate
   double getInterestRate() const;

   // function to set the account interest rate
   void setInterestRate(const double &);

private:
   double interestRate; // account interest rate data member
};                      // end class SavingsAccount

#endif