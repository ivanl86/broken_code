// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

#include <iostream>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"

#define DEFAULT_INTEREST_RATE 0.01
#define DEFAULT_TRANSACTION_FEE 3

int main(int argc, char const *argv[])
{
    // declare a Account type named account with the name New Account User and $1000 balance
    Account account("New Account User", 1'000);
    // display the account name and account balance
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // set balance to 1200
    account.setBalance(1'200);
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // deposit into the account
    double accountDeposit{500};
    // should output successfully deposits if the amount is greater than 0
    std::cout << account.getName() << (account.credit(accountDeposit) ? " successfully deposits $" : " cannot deposit $") << accountDeposit << " into the account\n";
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // withdraw from the account
    double accountWithdraw{800};
    // will throw a exception if the accountWithdraw is more than the account balance
    std::cout << account.getName() << (account.debit(accountWithdraw) ? " successfully withdraw $" : " cannot withdraw $") << accountWithdraw << " from the account\n";
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    // change account name
    account.setName("Royal Account User");
    std::cout << account.getName() << " has $" << account.getBalance() << " in the account\n";
    std::cout << "\n";

    // declare a CheckingAccount type named ckAccount with the name New Checking Account User, $800 balance, and $10 transaction fee
    CheckingAccount ckAccount("New Checking Account User", 800, 10);
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
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
    ckAccount.setName("Royal Checking Account User");
    std::cout << ckAccount.getName() << " has $" << ckAccount.getBalance() << " in the checking account with $" << ckAccount.getFee() << " transaction fee\n";
    std::cout << "\n";

    // declare a SavingsAccount type named savAccount with the name New Savings Account User, $1200 balance, and 1% interest rate
    SavingsAccount savAccount("New Savings Account User", 1200, 0.01);
    std::cout << savAccount.getName() << " has $" << savAccount.getBalance() << " in the savings account\n";


    return 0;
}