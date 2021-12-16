#pragma once
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
        int getNumberOfEmployee() const;
        void insert(Employee, int);
        void push(Employee);
        void shift(Employee);
        int indexOf(const Employee&);
        int indexOf(string, string = "ID", int = 0);
        string getLastName(int);
        int indexOfLastName(string, int = 0);
        int indexOf(const Contract&);
        int indexOfStatus(bool, int = 0);
        int indexOf(long, int = 0);
        void update(Employee, Employee);
        void update(string, string, string);
        void updateData(string, string);
        void updateSalary(long);
        void remove(int);
        void remove(Employee);
        void deleteEmployee(string, string = "ID");
        void deleteAllLastName(string);
        void deleteAllEmployee(string, string = "ID");
        void swap(Employee&, Employee&);
        void sort(string);
        Employee& operator[](int);
        const EmployeeManager& operator=(const EmployeeManager&);
        friend ostream& operator<<(ostream&, const EmployeeManager&);
        friend istream& operator>>(istream&, EmployeeManager&);
        const EmployeeManager& findAllEmployee(string, string = "ID");
        const EmployeeManager& findAllLastName(string);
};
