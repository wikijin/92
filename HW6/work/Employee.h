#include <string>
#include <iostream>

using namespace std;

class Employee
{
public:
    void display();

    friend istream& operator>>(istream& ins, Employee& newmember);

    string id;
    string last;
    string first;
    int salary;
};