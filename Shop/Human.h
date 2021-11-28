#pragma once
#include <string>
using namespace std;

class Human {
    private:
        string ID;
        string name;
        string phoneNumber;
        string address;
        string email;
        string gender;
        int age;
    public:
        Human();
        Human(string, string, int,string, string, string, string);
        Human(string, string, string, string, string);
        ~Human();
        void setID(string);
        void setName(string);
        void setPhoneNumber(string);
        void setAddress(string);
        void setEmail(string);
        void setGender(string);
        void setAge(int);
        string getID() const;
        string getName() const;
        string getPhoneNumber() const;
        string getAddress() const;
        string getEmail() const;
        string getGender() const;
        int getAge() const; 
};