#include <iostream>
#include <string>

using namespace std;

class atm
{
private:
    string userName;
    unsigned int balance;
    string mobileNumber;

public:
    atm(string user_name, int bal, string num)
    {
        userName = user_name;
        balance = bal;
        mobileNumber = num;
    }
    void checkBalance()
    {
        cout << "Current balance: " << balance << '\n';
    }
    void cashWithdraw(int amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance" << '\n';
        }
        else
        {
            balance -= amount;
            cout << amount << " withdrawn. New balance: " << balance << '\n';
        }
    }
    void userDetails()
    {
        cout << "User: " << userName << ", Balance: " << balance << ", Mobile: " << mobileNumber << '\n';
    }
    void updateMobileNumber(string newNumber)
    {
        mobileNumber = newNumber;
        cout << "Mobile number updated to " << newNumber << '\n';
    }
    void depositCash(int amount)
    {
        balance += amount;
        cout << amount << " deposited. New balance: " << balance << '\n';
    }
    void changeUserName(string newUserName)
    {
        userName = newUserName;
        cout << "User name updated to " << newUserName << '\n';
    }
};

int main()
{
    atm user1("John Doe", 1000, "1234567890");
    int choice;
    string newNumber, newUserName;
    int amount;

    do
    {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw Cash\n";
        cout << "3. Deposit Cash\n";
        cout << "4. View User Details\n";
        cout << "5. Update Mobile Number\n";
        cout << "6. Change User Name\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user1.checkBalance();
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            user1.cashWithdraw(amount);
            break;
        case 3:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            user1.depositCash(amount);
            break;
        case 4:
            user1.userDetails();
            break;
        case 5:
            cout << "Enter new mobile number: ";
            cin >> newNumber;
            user1.updateMobileNumber(newNumber);
            break;
        case 6:
            cout << "Enter new user name: ";
            cin >> newUserName;
            user1.changeUserName(newUserName);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}