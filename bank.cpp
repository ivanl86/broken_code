// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include <iostream>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"

int main(int argc, char const *argv[])
{
    CheckingAccount ckAccount("customer", 1000, 10);

    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " with $" << ckAccount.calculateFee() << " transaction fee\n";

    return 0;
}

