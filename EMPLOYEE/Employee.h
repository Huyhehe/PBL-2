#pragma once
#include <string>
#include "CONTRACT/Contract.h"
using namespace std;

class Employee {
    private:
        string ID;
        string name;
        int age;
        string sex;
        string phoneNumber;
        string address;
        string email;
        Contract contract;
        long salary = 4000000; //base salary for full-time employee in VND
    public:
        Employee(string, string, int, string, string, string, string, Contract, long);
        ~Employee();
        void Employee_setInfo(string, string, int, string, string, string, string, Contract, long);
        string Employee_getID();
        string Employee_getName();
        int Employee_getAge();
        string Employee_getSex();
        string Employee_getPhoneNumber();
        string Employee_getAddress();
        string Employee_getEmail();
        long Employee_getSalary();
        
};