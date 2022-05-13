// who: Ivan Leung ileung2
// what: Account
// why: Lab 6a
// when: May/15/2022

// Account class with a constructor that initializes the account name.
#include <string>
#include <stdexcept>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
   // constructor initializes data member name with parameter accountName
   explicit Account(std::string);

   // constructor initializes data member name and balance
   explicit Account(std::string , double);

   // function to set the account name
   void setName(const std::string &);

   // function to retrieve the account name
   std::string getName() const;

   void setBalance(const double &);

   double getBalance() const;

   virtual bool credit(const double &);

   virtual bool debit(const double &);

private:
   std::string name; // account name data member
   double balance; // account balance
};                   // end class Account

#endif