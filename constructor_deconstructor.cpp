#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int accountNumber, balance;

public:
    BankAccount(int a, int b)
    {
        accountNumber = a;
        balance = b;
        cout << accountNumber << " is intiated with " << balance << " in balance" << '\n';
    }
    ~BankAccount()
    {
        cout << accountNumber << " is destroyed" << '\n';
    }
};
int main()
{
    BankAccount acc(1234, 5000);

    return 0;
}