#include "Employee.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int findInVec(vector<Employee>& vec, string id)
{
    for (int i = 0;i < vec.size(); ++i)
    {
        if (vec[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void add2Vec(vector<Employee>& vec, Employee newmember)
{
    int index = findInVec(vec, newmember.id);
    if (index != -1)
    {
        cout << "*** Duplicate ID ***" << endl;
        return ;
    }
    int position = -1;
    for (int i = 0;i < vec.size();++i)
    {
        if (vec[i].salary > newmember.salary)
        {
            position = i;
            vec.insert(vec.begin() + position, newmember);
            break;
        }
    }
    if (position == -1)
        vec.push_back(newmember);
    newmember.display();
}

void delFromVec(vector<Employee>& vec, string id)
{
    int index = findInVec(vec, id);
    if (index == -1)
    {
        cout << "*** ID not found ***" << endl;
        return ;
    }
    vec[index].display();
    vec.erase(vec.begin() + index);
}

void display(vector<Employee>& vec, string id)
{
    int index = findInVec(vec, id);
    if (index == -1)
    {
        cout << "*** ID not found ***" << endl;
        return ;
    }
    vec[index].display();
}

string takeoutid(string content)
{
    string id = content;
    char *pt = strtok ((char *)content.c_str(), ",");
    if (pt != NULL)
    {
        id = pt;
    }
    return id;
}

int main()
{
    vector<Employee> vec;
    ifstream input;
    input.open("commands.in", ifstream::in);
    string cmd;
    while (input >> cmd)
    {
        if (cmd == "+")
        {
            Employee newmember;
            input >> newmember;
            cout << cmd << " ";
            cout << newmember.id << ": ";
            add2Vec(vec, newmember); 
        }
        else if (cmd == "-")
        {
            cout << cmd << " ";
            string id;
            input >> id;
            id = takeoutid(id);
            cout << id << ": ";
            delFromVec(vec, id);
        }
        else if (cmd == "?")
        {
            cout << cmd << " ";
            string id;
            input >> id;
            id = takeoutid(id);
            cout << id << ": ";
            display(vec, id);
        }
        else
        {
            cout << cmd << " ";
            string id;
            input >> id;
            id = takeoutid(id);
            cout << id << ": ";
            cout << "*** Invalid command ***" << endl;
        }
    }
    input.close();
    //
    cout << "All employees" << endl;
    cout << "-------------" << endl;
    for (int i = 0;i < vec.size(); ++i)
    {
        vec[i].display();
    }

    cout << "Statistics" << endl;
    cout << "----------" << endl;
    int min_salary = 10000000;
    int max_salary = 0;
    float total_sarary = 0;
    for (int i = 0;i < vec.size(); ++i)
    {
        if (vec[i].salary < min_salary)
            min_salary = vec[i].salary;
        if (vec[i].salary > max_salary)
            max_salary = vec[i].salary;
        total_sarary += vec[i].salary;
    }

    cout << "Minimum salary = $";
    cout.width(6);
    cout << right << min_salary << ".00" << endl;

    cout << "Maximum salary = $" << right << max_salary << ".00" << endl;

    //cout.precision(2);
    cout << "Average salary = $" << right << setprecision(2) << fixed << total_sarary *1.0 / vec.size() << endl;;
}