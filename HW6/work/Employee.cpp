#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

istream& operator>>(istream& ins, Employee& newmember)
{
    string content;
    ins >> content;
    char *pt = strtok ((char *)content.c_str(), ",");
    if (pt != NULL)
    {
        newmember.id = pt;
    }
    pt = strtok (NULL, ",");
    if (pt != NULL)
    {
        newmember.last = pt;
    }
    pt = strtok (NULL, ",");
    if (pt != NULL)
    {
        newmember.first = pt;
    }
    pt = strtok (NULL, ",");
    if (pt != NULL)
    {
        newmember.salary = atoi(pt);
    }
}

void Employee::display()
{
    cout << "Employee{ID=" << id << ", last="<< last <<", first=" << first << ", salary=" << salary << "}" << endl;
}
