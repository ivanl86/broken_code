// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "account.h"

// constructor initializes data member name with parameter accountName
Account::Account(std::string accountName)
    : name{accountName} {}

// constructor initializes data member name and balance
Account::Account(std::string accountName, double accountBalance)
    : name{accountName}
{
    setBalance(accountBalance);
}

// function to set the account name
void Account::setName(const std::string &accountName)
{
    name = accountName;
}

// function to retrieve the account name
std::string Account::getName() const
{
    return name;
}

// function to set the account initial balance
void Account::setBalance(const double &accountBalance)
{
    if (accountBalance < 0)
        throw std::invalid_argument("Initial balance must be equal or greater than zero!");
    balance = accountBalance;
}

// function to retrieve the account balance
double Account::getBalance() const
{
    return balance;
}

// function to deposit to the account
bool Account::credit(const double &deposit)
{
    if (deposit <= 0)
        return false;
    balance += deposit;
    return true;
}

// function to withdraw from the account
bool Account::debit(const double &charge)
{
    if (charge > balance)
        throw std::out_of_range("Insufficient balance!");
    balance -= charge;
    return true;
}