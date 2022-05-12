// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "account.h"

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class CheckingAccount : Account
{
public:
   explicit CheckingAccount(std::string accountName, double accountBalance, double transactionFee) : Account(accountName, accountBalance)
   {}

private:
   double fee; // account transaction fee
};

#endif