// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include <iostream>
#include <iomanip>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"

void testAccount();
void testCheckingAccount();
void testSavingsAccount();

int main(int argc, char const *argv[])
{
    testAccount();
    std::cout << "\n";

    testCheckingAccount();
    std::cout << "\n";

    testSavingsAccount();
    std::cout << "\n";
    return 0;
}

void testAccount()
{
    // declare a Account type named account with the name New Account User and $1000 balance
    Account account("New Account User", 1'000);
    // display the account name and account balance
    std::cout << account.getName() << " has $" << std::fixed << std::setprecision(2) << account.getBalance() << " in the account\n";
    // set balance to 1200
    account.setBalance(1'200);
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // deposit into the account
    double accountDeposit{500};
    // should output successfully deposits if accountDeposit is greater than 0
    std::cout << account.getName() << (account.credit(accountDeposit) ? " successfully deposits $" : " cannot deposit $") << accountDeposit << " into the account\n";
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // withdraw from the account
    double accountWithdraw{800};
    // will throw a exception if accountWithdraw is more than the account balance
    std::cout << account.getName() << (account.debit(accountWithdraw) ? " successfully withdraw $" : " cannot withdraw $") << accountWithdraw << " from the account\n";
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // change account name
    account.setName("Royal Account User");
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
} // end test Account

void testCheckingAccount()
{
    // declare a CheckingAccount type named ckAccount with the name New Checking Account User, $800 balance, and $10 transaction fee
    CheckingAccount ckAccount("New Checking Account User", 800, 10);
    std::cout << ckAccount.getName() << " has $" << std::fixed << std::setprecision(2) << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    // set balance to 700
    ckAccount.setBalance(700);
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    // deposit into the checking account
    double ckDeposit{2'000};
    // return true if the deposit is successful and transaction fee will be charged
    if (ckAccount.credit(ckDeposit))
    {
        ckAccount.debit(ckAccount.getFee());
        std::cout << ckAccount.getName() << " successfully deposits $" << ckDeposit << " into the checking account\n";
    }
    else
        std::cout << "Deposit cannot be equal or less than zero!\n";
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    // change transaction fee
    double ckTransactionFee{5};
    ckAccount.setFee(ckTransactionFee);
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    // withdraw from the checking account
    double ckWithdraw{1'500};
    // return true if the withdraw is successful and transaction fee will be charged
    if (ckAccount.debit(ckWithdraw))
    {
        ckAccount.debit(ckAccount.getFee());
        std::cout << ckAccount.getName() << " successfully withdraws $" << ckWithdraw << " from the checking account\n";
    }
    else
        std::cout << "Withdraw cannot be greater than balance + fee!\n";
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    // change checking account name
    ckAccount.setName("Royal Checking Account User");
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
} // end test CheckingAccount

void testSavingsAccount()
{
    // declare a SavingsAccount type named savAccount with the name New Savings Account User, $1200 balance, and 1% interest rate
    SavingsAccount savAccount("New Savings Account User", 1'200, 0.01);
    std::cout << savAccount.getName() << " has $" << std::fixed << std::setprecision(2) << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // set balance to 1600
    savAccount.setBalance(1'600);
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // deposit into the savings account
    double savDeposit{1'450};
    // should output successfully deposits if savDeposit is greater than 0
    std::cout << savAccount.getName() << (savAccount.credit(savDeposit) ? " successfully deposits $" : " cannot deposit $") << savDeposit << " into the savings account\n";
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // receive interest
    double interest{savAccount.calculateInterest()};
    savAccount.credit(interest);
    std::cout << savAccount.getName() << " received $" << interest << " interest\n";
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // withdraw from the account
    double savWithdraw{1'100};
    // will throw a exception if savWithdraw is more than the savings account balance
    if (savAccount.debit(savWithdraw))
        std::cout << savAccount.getName() << " successfully withdraw $" << savWithdraw << "from the savings account\n";
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // set interests rate to 2%
    double interestRate{0.02};
    savAccount.setInterestRate(interestRate);
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // receive interest with new interest rate
    interest = savAccount.calculateInterest();
    savAccount.credit(interest);
    std::cout << savAccount.getName() << " received $" << interest << " interest\n";
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
    // change savings account name 
    savAccount.setName("Royal Savings Account User");
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account with " << savAccount.getInterestRate() << "% interest rate\n";
} // end test SavingsAccount