#pragma once
#include <string>
#include "Contract.h"
#include "Human.h"
#include <iostream>

using namespace std;

class Employee : public Human{
    private:
        Contract contract;
        long salary = 4000000; //base salary for full-time employee in VND
    public:
        Employee();
        Employee(string, string, int, string, string, string, string, Contract, long);
        ~Employee();
        void setSalary();
        long getSalary() const;
        void setContract(const Contract&);
        Contract getContract() const;
        const Employee& operator=(const Employee&);
        friend ostream& operator<<(ostream&, const Employee&);
};