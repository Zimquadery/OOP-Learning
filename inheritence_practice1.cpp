#include <iostream>
using namespace std;

class employee
{
protected:
    string name, employeeID;

public:
    employee(string n, string id) : name(n), employeeID(id) {}
};
class doctor : protected employee
{
protected:
    string specialization;

public:
    doctor(string n, string id, string spec) : employee(n, id), specialization(spec) {}
    void prescribeMedication()
    {
        cout << "Prescribing Medication of " << specialization<< '\n';
    }
    void display()
    {
        cout << "Name: " << name << '\n';
        cout << "Employee ID: " << employeeID << '\n';
        cout << "Specialization: " << specialization << '\n';
    }
};

class nurse : protected employee
{
protected:
    string shiftDetail;
public:
    nurse(string n, string id, string shift) : employee(n, id), shiftDetail(shift) {}
    void display()
    {
        cout << "Name: " << name << '\n';
        cout << "Employee ID: " << employeeID << '\n';
        cout << "Shift Detail: " << shiftDetail << '\n';
    }
};
int main()
{
    doctor dr("Alif", "123456", "Cardiology");
    dr.prescribeMedication();
    dr.display();
    nurse n("Adiba", "654321", "Morning");
    n.display();
    return 0;
}
