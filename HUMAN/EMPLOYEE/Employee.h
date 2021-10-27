#pragma once
#include <string>
#include "CONTRACT/Contract.h"
#include "../Human.h"
using namespace std;

class Employee : public Human{
    private:
        Contract contract;
        long salary = 4000000; //base salary for full-time employee in VND
    public:
        Employee(string, string, int, string, string, string, string, Contract, long);
        ~Employee();
        void setSalary();
        long getSalary();
};