#pragma once
#include <string>

using namespace std;

class Customer {
    private:
        string ID;
        string name;
        string phoneNumber;
        string email;
        string address;
        //mat hang da mua;
    public:
        Customer(string, string, string, string, string);
        ~Customer();
        void Customer_setInfo(string, string, string, string, string);
        string Customer_getID();
        string Customer_getName();
        string Customer_getPhoneNumber();
        string Customer_getEmail();
        string Customer_getAddress();

};