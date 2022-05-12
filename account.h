// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

// Account class with a constructor that initializes the account name.
#include <string>
#include <stdexcept>

class Account
{
public:
   // constructor initializes data member name with parameter accountName
   explicit Account(std::string accountName)
       : name{accountName}
   { // member initializer
      // empty body
   }

   explicit Account(double accountBalance)
       : balance{accountBalance}
   { // member initializer
      // empty body
   }

   explicit Account(std::string accountName, double accountBalance)
       : name{accountName}
   { // member initializer
      setBalance(accountBalance);
   }

   // function to set the account name
   void setName(std::string accountName);

   // function to retrieve the account name
   std::string getName() const;

   void setBalance(double accountBalance);

   double getBalance() const;

   void credit(double deposit);

   bool debit(double charge);

private:
   std::string name; // account name data member
   double balance; // account balance
};                   // end class Account

class SavingsAccount : Account
{
public:
   explicit SavingsAccount(std::string accountName, double accountBalance, double interestRate) : Account(accountName, accountBalance)
   {}

   double calculateInterest() const
   {
      return getBalance() * interestRate;
   }

private:
   double interestRate;
};

class CheckingAccount : Account
{
public:
   explicit CheckingAccount(std::string accountName, double accountBalance, double transactionFee) : Account(accountName, accountBalance)
   {}

private:
   double fee; // account transaction fee
};