#include <iostream>
using namespace std;

class persion
{
protected:
    string name;

public:
    persion(string n) : name(n) {}
};

class student : protected persion
{
protected:
    string studentID, depertment;

public:
    student(string name, string ID, string dept) : persion(name), studentID(ID), depertment(dept) {}
};
class graduateStudent : protected student 
{
private:
    string supervisor,thesistopic;

public:
    graduateStudent(string name, string ID, string dept, string supervisor, string topic) : student(name, ID, dept), supervisor(supervisor), thesistopic(topic) {}

    void display()
    {
        cout << "Name: " << name << '\n';
        cout << "Student ID: " << studentID << '\n';
        cout << "Department: " << depertment << '\n';
        cout << "Supervisor: " << supervisor << '\n';
        cout << "Thesis Topic: " << thesistopic << '\n';
    }
};
int main()
{
    graduateStudent student1("Zim", "123456", "Computer Science", "Dr. Md. Abdullah Al Mamun", "Introduction to Computer Science");
    student1.display();
    return 0;
}