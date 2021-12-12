#pragma once
#include <string>
#include "Contract.h"
#include "Human.h"
#include <iostream>

using namespace std;

class Employee : public Human{
    private:
        Contract contract;
        long salary; //base salary for full-time employee in VND
    public:
        Employee();
        Employee(string, string, Date, string, string, string, string, Contract, long = 4000000);
        ~Employee();
        void setSalary(long);
        long getSalary() const;
        void setContract(const Contract&);
        Contract getContract() const;
        const Employee& operator=(const Employee&);
        friend ostream& operator<<(ostream&, const Employee&);
};
