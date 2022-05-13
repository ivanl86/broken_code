// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022


#include "checkingAccount.h"

// constructor initializes data member name, balance, and interest rate with parameter accountName, accountBalance, and transaction fee
CheckingAccount::CheckingAccount(std::string accountName, double accountBalance, double transactionFee)
    : Account(accountName, accountBalance), fee{transactionFee} {}

// function to set transaction fee
void CheckingAccount::setFee(const double &accountFee)
{
    fee = accountFee;
}

// function to retrieve transaction fee
double CheckingAccount::getFee() const
{
    return fee;
}

// override function to deposit to the account with transaction fee
bool CheckingAccount::credit(const double &deposit)
{
    if (deposit <= 0)
        return false;
    setBalance(getBalance() + deposit);
    return true;
}

// override function to withdraw from account with transaction fee
bool CheckingAccount::debit(const double &charge)
{
    if (charge > getBalance())
        return false;
    setBalance(getBalance() - charge);
    return true;
}