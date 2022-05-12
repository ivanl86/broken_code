// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "account.h"

explicit Account::Account(std::string accountName)
         : name{accountName} {}

explicit Account::Account(double accountBalance)
         : balance{accountBalance} {}

explicit Account::Account(std::string accountName, double accountBalance)
         : name{accountName}
{
    setBalance(accountBalance);
}

// function to set the account name
void Account::setName(std::string accountName)
{
    name = accountName;
}

// function to retrieve the account name
std::string Account::getName() const
{
    return name;
}

void Account::setBalance(double accountBalance)
{
    if (accountBalance < 0)
        throw std::invalid_argument("Initial balance must be equal or greater than zero!");
    balance = accountBalance;
}

double Account::getBalance() const
{
    return balance;
}

void Account::credit(double deposit)
{
    balance += deposit;
}

bool Account::debit(double charge)
{
    if (charge > balance)
        throw std::out_of_range("Insufficient balance!");
    balance -= charge;
    return true;
}