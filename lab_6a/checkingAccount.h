// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

// CheckingAccount class with a constructor that initializes the account name, account balance, and account fee.
#include "account.h"

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
   // constructor initializes data member name, balance, and interest rate with parameter accountName, accountBalance, and accountFee
   explicit CheckingAccount(std::string, double, double);

   void setFee(const double &);

   // function to retrieve transaction fee
   double getFee() const;

   // override function to deposit to the account with transaction fee
   bool credit(const double &);

   // override function to withdraw from account with transaction fee
   bool debit(const double &);

private:
   double fee; // account transaction fee
};             // end class CheckingAccount

#endif