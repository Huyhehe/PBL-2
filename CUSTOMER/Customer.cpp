#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(string ID, string name, string phoneNumber, string email, string address) : ID(ID), name(name),
 phoneNumber(phoneNumber), email(email), address(address) {    
}
Customer::~Customer(){}

void Customer::Customer_setInfo(string ID, string name, string phoneNumber, string email, string address) {
    this->ID = ID;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->address = address;
}

string Customer::Customer_getID() {
    return ID;
}
string Customer::Customer_getName() {
    return name;
}
string Customer::Customer_getPhoneNumber() {
    return phoneNumber;
}
string Customer::Customer_getEmail() {
    return email;
}
string Customer::Customer_getAddress() {
    return address;
}