#include <iostream>
using namespace std;
class employee
{
private:
    string name, employeeID;

public:
    employee(string n, string id) : name(n), employeeID(id) {}
    void show()
    {
        cout << "Name: " << name << '\n';
        cout << "Employee ID: " << employeeID << '\n';
    }
};
class salary : protected employee
{
private:
    int basicPay, Bonus;
public:
    salary(string n, string id, int basicPay, int Bonus) : employee(n, id), basicPay(basicPay), Bonus(Bonus) {}
    void ShowSalaryDetails()
    {
        cout << "Basic Pay: " << basicPay << '\n';
        cout << "Bonus: " << Bonus << '\n';
        cout << "Total Salary: " << basicPay + Bonus << '\n';
    }
    void updateSalary( int basicPay, int Bonus )
    {
        this->basicPay = basicPay;
        this->Bonus = Bonus;
        cout << "Salary Updated Successfully" <<'\n';
    }
};
int main()
{
    salary emp("Sazid", "12345", 5000, 1000);
    emp.ShowSalaryDetails();
    emp.updateSalary(10000, 2000);
    emp.ShowSalaryDetails();
    return 0;
}
