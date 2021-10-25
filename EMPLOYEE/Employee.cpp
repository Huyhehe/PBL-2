#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string ID, string name, int age, string sex, string phoneNumber, string address, string email, Contract contract, long salary)
: ID(ID), name(name), age(age), sex(sex), phoneNumber(phoneNumber), address(address), email(email), contract(contract), salary(salary) {}
Employee::~Employee(){}

void Employee::Employee_setInfo(string ID, string name, int age, string sex, string phoneNumber, string address, string email, Contract contract, long salary) {
    this->ID = ID;
    this->name = name;
    this->age = age;
    this->sex = sex;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->email = email;
    this->contract = contract;
    if (contract.Contract_getIsFullTime()) {
        this->salary = salary;
    }
    else {
        this->salary = salary / 2;
    }
}
string Employee::Employee_getID() {
    return ID;
}
string Employee::Employee_getName() {
   return name; 
}
int Employee::Employee_getAge() {
    return age;
}
string Employee::Employee_getSex() {
    return sex;
}
string Employee::Employee_getPhoneNumber() {
    return phoneNumber;
}
string Employee::Employee_getAddress() {
    return address;
}
string Employee::Employee_getEmail() {
    return email;
}
long Employee::Employee_getSalary() {
    return salary;
}