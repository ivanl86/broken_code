// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "savingsAccount.h"


SavingsAccount::SavingsAccount(const std::string &accountName, const double &accountBalance, const double &accountRate)
    : Account(accountName, accountBalance), interestRate{accountRate} {}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}

double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

void SavingsAccount::setInterestRate(const double &accountInterestRate)
{
    interestRate = accountInterestRate;
}