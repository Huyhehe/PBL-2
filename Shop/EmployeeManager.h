#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

class EmployeeManager {
    private:
        Employee* emp;
        int numberOfEmployee;
    public:
        EmployeeManager();
        EmployeeManager(int);
        ~EmployeeManager();
        void insert(Employee, int);
        void push(Employee);
        void shift(Employee);
        int indexOf(const Employee&);
        int indexOf(string, string, int = 0);
        void update(Employee, Employee);
        void remove(int);
        void remove(Employee);
        void swap(Employee&, Employee&);
        void sort(string);
        friend ostream& operator<<(ostream&, const EmployeeManager&);
};