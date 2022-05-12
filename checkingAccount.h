// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include "account.h"

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
   explicit CheckingAccount(std::string, double, double);

private:
   double fee; // account transaction fee
};

#endif