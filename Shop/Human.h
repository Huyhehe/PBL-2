#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Human {
    private:
        string ID;
        string name;
        Date dateOfBirth;
        string phoneNumber;
        string address;
        string email;
        string gender;
    public:
        Human();
        Human(string, string, Date, string, string, string, string);
        Human(string, string, string, string, string);
        ~Human();
        void setID(string);
        void setName(string);
        void setPhoneNumber(string);
        void setAddress(string);
        void setEmail(string);
        void setGender(string);
        void setDateOfBirth(int, int, int);
        void setDateOfBirth(const Date&);
        string getID() const;
        string getName() const;
        string getPhoneNumber() const;
        string getAddress() const;
        string getEmail() const;
        string getGender() const;
        Date getDateOfBirth() const;
};