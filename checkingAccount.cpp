// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022


#include "checkingAccount.h"
CheckingAccount::CheckingAccount(std::string accountName, double accountBalance, double transactionFee) : Account(accountName, accountBalance), fee{transactionFee}
{}

