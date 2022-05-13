// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include <iostream>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"

#define DEFAULT_INTEREST_RATE 0.01

int main(int argc, char const *argv[])
{
    CheckingAccount ckAccount("customer", 1000, 10);
    SavingsAccount svAccount("customer", 1000, 0.03);

    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " with $" << ckAccount.calculateFee() << " transaction fee\n";
    std::cout << svAccount.getName() << " has $" << svAccount.getBalance() << " with " << svAccount.calculateInterest() << "% interest rate\n";

    

    return 0;
}