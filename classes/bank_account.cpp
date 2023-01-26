#include <iostream>
#include <string>

using std::string;

class BankAccount
{
  private:
      int acct_number_{00000000};
      string acct_holder_{""};
      float avail_funds_{0.00};

  public:
      // Don't do this in reality. Core Guidelines suggests avoiding trivial getters and setters. Just make variables public.
      int Acct_Number() const {return acct_number_;}
      void Acct_number(int x) {acct_number_ = x;}
      string Acct_Holder() const {return acct_holder_;}
      void Acct_Holder(string s) {acct_holder_ = s;}
      int Avail_funds() const {return avail_funds_;}
      void Avail_funds(int y) {avail_funds_ = y;}

      BankAccount(int x, string s, int y) : acct_number_(x), acct_holder_(s), avail_funds_(y) {};
};

int main(){
    BankAccount bank_account(1000000, "Jono", 100.00);
    std::cout << bank_account.Acct_Holder();
    std::cout << bank_account.Acct_Number();
    std::cout << bank_account.Avail_funds();
}