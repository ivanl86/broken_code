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
       : name{accountName}, balance{accountBalance}
   { // member initializer
      // empty body
   }

   // function to set the account name
   void setName(std::string accountName)
   {
      name = accountName;
   }

   // function to retrieve the account name
   std::string getName() const
   {
      return name;
   }

   void setBalance(double accountBalance)
   {
      if (accountBalance < 0)
         throw std::invalid_argument("Initial balance must be equal or greater than zero!");
      balance = accountBalance;
   }

   double getBalance() const
   {
      return balance;
   }

   void credit(double deposit)
   {
      balance += deposit;
   }

   bool debit(double charge)
   {
      if (charge > balance)
         throw std::out_of_range("Insufficient balance!");
      balance -= charge;
      return true;
   }

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