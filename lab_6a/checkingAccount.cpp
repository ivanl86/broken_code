// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022


#include "checkingAccount.h"
CheckingAccount::CheckingAccount(std::string accountName, double accountBalance, double transactionFee) : Account(accountName, accountBalance), fee{transactionFee}
{}

// function to retrieve transaction fee
double CheckingAccount::getFee() const
{
    return fee;
}

// override function to deposit to the account with transaction fee
bool CheckingAccount::credit(const double &deposit)
{
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