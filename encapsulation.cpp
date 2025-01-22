#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
    string name;
    int id, salary, overtime, unitpayment;

public:
    void setter(string n, int i, int s, int o, int u)
    {
        name = n;
        id = i;
        salary = s;
        overtime = o;
        unitpayment = u;
    }
    void getter()
    {
        cout << "Name: " << name << '\n';
        cout << "Id: " << id << '\n';
        cout << "Salary: " << salary << '\n';
        cout << "Overtime: " << overtime << '\n';
        cout << "Unit payment: " << unitpayment << '\n';
    }
    int calculateSalary()
    {
        return salary + overtime * unitpayment;
    }
};
int main()
{
    Employee ron;
    ron.setter("Ron", 15, 20000, 10, 100);
    ron.getter();
    cout << ron.calculateSalary() << '\n';
    return 0;
}