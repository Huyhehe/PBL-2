#include "EmployeeManager.h"
#include <iostream>

using namespace std;

int main() {
    Employee emp1("10220", "Hieu", 20, "Nam", "0901201", "minhhieu@gamil.com", "26 Binh Minh 3", Contract("10/11/2012", "11/2/2021", true), 10000000);
    Employee emp2("10221", "Nam", 22, "Nam", "0901222", "Namise@gamil.com", "34 Phan Tu", Contract("5/11/2021", "5/2/2023", true), 12000000);
    Employee emp3("10222", "Binh", 19, "Nu", "0901211", "Bindkae@gamil.com", "9 Ton Duc Thang", Contract("4/3/2021", "4/1/2022", false), 7000000);
    EmployeeManager e;
    e.push(emp1);
    e.push(emp3);
    e.push(emp2);

    cout << e;

    cout << emp1.getEmail();

    return 0;
}