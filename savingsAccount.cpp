// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "savingsAccount.h"

SavingsAccount::SavingsAccount(const std::string &accountName, const double &accountBalance, const double &interestRate) : Account(accountName, accountBalance)
{}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}