#include <iostream>
using namespace std;

class SmartHomeSystem
{
protected:
    string deviceID, status;

public:
    SmartHomeSystem(string id, string st) : deviceID(id), status(st) {}
    SmartHomeSystem() {}
};
class sensors : virtual public SmartHomeSystem
{
protected:
    string sensitivity;

public:
    sensors(string id, string st, string sens) : SmartHomeSystem(id, st), sensitivity(sens) {}
    sensors(string sens) : sensitivity(sens) {}

    void show()
    {
        cout << "Device ID: " << SmartHomeSystem::deviceID << '\n';
        cout << "Status: " << SmartHomeSystem::status << '\n';
        cout << "Sensitivity: " << sensitivity << '\n';
    }
};
class smartDevice : virtual public SmartHomeSystem
{
protected:
    string connectivity;
public:
    smartDevice(string id, string st, string conn) : SmartHomeSystem(id, st), connectivity(conn) {}
    smartDevice(string conn): connectivity(conn) {}

    void show()
    {
        cout << "Device ID: " << SmartHomeSystem::deviceID << '\n';
        cout << "Status: " << SmartHomeSystem::status << '\n';
        cout << "Connectivity: " << connectivity << '\n';
    }
};
class smartSensor : public sensors, public smartDevice
{
public:
    smartSensor(string id, string st, string sens, string conn) : SmartHomeSystem(id, st), sensors(sens), smartDevice(conn) {}
    void show()
    {
        cout << "Device ID: " << SmartHomeSystem::deviceID << '\n';
        cout << "Status: " << SmartHomeSystem::status << '\n';
        cout << "Sensitivity: " << sensitivity << '\n';
        cout << "Connectivity: " << connectivity << '\n';
    }
};
 int main()
{
    smartSensor s("12345", "On", "High", "Wi-Fi");
    s.show();

    sensors s1("12345", "On", "High");
    s1.show();

    smartDevice s2("12345", "On", "Wi-Fi");
    s2.show();

    return 0;
}
