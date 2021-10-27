#include "Employee.h"

Employee::Employee(string ID, string name, int age, string sex, string phoneNumber, string address, string email, Contract contract, long salary) :Human(ID, name, phoneNumber, address, email, sex, age){
    this->salary = salary;
    this->contract = contract;
}
Employee::~Employee(){}

void Employee::setSalary() {
    if (contract.Contract_getIsFullTime()) {
        this->salary = salary;
    }
    else {
        this->salary = salary / 2;
    }
}
long Employee::getSalary() {
    return salary;
}