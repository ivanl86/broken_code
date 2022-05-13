// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "savingsAccount.h"

// constructor initializes data member name, balance, and interest rate with parameter accountName, accountBalance, and accountRate
SavingsAccount::SavingsAccount(const std::string &accountName, const double &accountBalance, const double &accountRate)
    : Account(accountName, accountBalance), interestRate{accountRate} {}

// function to calculate the interest
double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}

// function to set the account interest rate
void SavingsAccount::setInterestRate(const double &accountInterestRate)
{
    interestRate = accountInterestRate;
}

// function to retrieve the account interest rate
double SavingsAccount::getInterestRate() const
{
    return interestRate;
}