#include <bits/stdc++.h>

using namespace std;

class NonwithDrawableAccount
{
public:
  virtual void deposit(double amount) = 0;
};

class withDrawableAccount : public NonwithDrawableAccount
{
public:
  virtual void withdraw(double amount) = 0;
};

class SavingAccount : public withDrawableAccount
{
private:
  double balance;

public:
  SavingAccount()
  {
    balance = 0;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
  }

  void withdraw(double amount)
  {
    if (balance >= amount)
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
    }
    else
    {
      cout << "Insufficient funds in Savings Account!\n";
    }
  }
};

class CurrentAccount : public withDrawableAccount
{
private:
  double balance;

public:
  CurrentAccount()
  {
    balance = 0;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
  }

  void withdraw(double amount)
  {
    if (balance >= amount)
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
    }
    else
    {
      cout << "Insufficient funds in Current Account!\n";
    }
  }
};

class FixedTermAccount : public NonwithDrawableAccount
{
private:
  double balance;

public:
  FixedTermAccount()
  {
    balance = 0;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
  }

  // void withdraw(double amount)
  // {
  //   throw logic_error("Withdrawal not allowed in Fixed Term Account!");
  // }
};

class BankClient
{
private:
  vector<withDrawableAccount *> withdrawableAccounts;
  vector<NonwithDrawableAccount *> NonwithDrawableAccounts;

public:
  BankClient(vector<withDrawableAccount *> withDrawableAccounts, vector<NonwithDrawableAccount *> NonwithDrawableAccounts)
  {
    this->withdrawableAccounts = withDrawableAccounts;
    this->NonwithDrawableAccounts = NonwithDrawableAccounts;
  }
  void processTransactions()
  {
    for (withDrawableAccount *acc : withdrawableAccounts)
    {
      acc->deposit(1000);
      acc->withdraw(500);
    }
    for (NonwithDrawableAccount *acc : NonwithDrawableAccounts)
    {
      acc->deposit(5000);
    }
  }
};

int main()
{
  vector<withDrawableAccount *> withdrawableAccounts;
  withdrawableAccounts.push_back(new SavingAccount());
  withdrawableAccounts.push_back(new CurrentAccount());

  vector<NonwithDrawableAccount *> depositOnlyAccounts;
  depositOnlyAccounts.push_back(new FixedTermAccount());

  BankClient *client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
  client->processTransactions();

  return 0;
}