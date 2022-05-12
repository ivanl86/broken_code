// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include <iostream>

#include "savingsAccount.h"
#include "checkingAccount.h"

int main(int argc, char const *argv[])
{
    CheckingAccount ckAcount("customer", 1000, 10);

    std::cout << ckAcount.getBalance();

    return 0;
}

