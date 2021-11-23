#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(){}
Customer::Customer(string ID, string name, string phoneNumber, string email, string address) 
    : Human(ID, name, phoneNumber, address, email){    
}
Customer::~Customer(){}
